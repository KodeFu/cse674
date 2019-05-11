#include "stdafx.h"
#include "SmoothSort.h"

//
// Smooth sort implementation based on Djikstra's smoothsort pseudo-code and
// programming algorithms example.
//
// changelog:
//     - Support C++ class structure
//     - Integer sorting instead of strings
//     - Use std vectors types
//     - Handle large sorts (sorting millions of values)
//

#define UP(IA,IB) temp = IA; IA += IB + 1; IB = temp;
#define DOWN(IA,IB) temp = IB; IB = IA - IB - 1; IA = temp;

CSmoothSort::CSmoothSort()
{
	q = 1;
	r = 0;
	p = 1;
	b = 1;
	c = 1;
}


CSmoothSort::~CSmoothSort()
{
}

std::string CSmoothSort::identify()
{
	return "Smooth Sort";
}

void CSmoothSort::sift(std::vector<int>& A)
{
	int r0, r2, temp;
	int t;
	r0 = r1;
	t = A[r0];

	while (b1 >= 3)
	{
		r2 = r1 - b1 + c1;

		if (!(A[r1 - 1] < A[r2])) {
			r2 = r1 - 1;
			DOWN(b1, c1);
		}

		if (A[r2] < t) {
			b1 = 1;
		}
		else {
			A[r1] = A[r2];
			r1 = r2;
			DOWN(b1, c1);
		}
	}

	if (r1 - r0) {
		A[r1] = t;
	}
}

void CSmoothSort::trinkle(std::vector<int>& A)
{
	int p1, r2, r3, r0, temp;
	int t;
	p1 = p;
	b1 = b;
	c1 = c;
	r0 = r1;
	t = A[r0];

	while (p1 > 0)
	{
		while ((p1 & 1) == 0) {
			p1 >>= 1;
			UP(b1, c1)
		}

		r3 = r1 - b1;

		if ((p1 == 1) || (A[r3] < t)) {
			p1 = 0;
		}
		else {
			--p1;

			if (b1 == 1) {
				A[r1] = A[r3];
				r1 = r3;
			}
			else {
				if (b1 >= 3) {
					r2 = r1 - b1 + c1;

					if (!(A[r1 - 1] < A[r2])) {
						r2 = r1 - 1;
						DOWN(b1, c1);
						p1 <<= 1;
					}
					if ((A[r2] < A[r3])) {
						A[r1] = A[r3]; r1 = r3;
					}
					else {
						A[r1] = A[r2];
						r1 = r2;
						DOWN(b1, c1);
						p1 = 0;
					}
				}
			}
		}
	}

	if (r0 - r1) {
		A[r1] = t;
	}

	sift(A);
}

void CSmoothSort::semiTrinkle(std::vector<int>& A) 
{
	int T;
	r1 = r - c;

	if (!(A[r1] < A[r])) {
		T = A[r];
		A[r] = A[r1];
		A[r1] = T;
		trinkle(A);
	}
}

void CSmoothSort::sort(std::vector<int>& A) 
{
	int temp;

	while (q < ((int) A.size())) {
		r1 = r;
		if ((p & 7) == 3) {
			b1 = b;
			c1 = c;
			sift(A);
			p = (p + 1) >> 2;
			UP(b, c);
			UP(b, c);
		}
		else if ((p & 3) == 1) {
			if (q + c < ((int) A.size())) {
				b1 = b;
				c1 = c;
				sift(A);
			}
			else {
				trinkle(A);
			}

			DOWN(b, c);
			p <<= 1;

			while (b > 1) {
				DOWN(b, c);
				p <<= 1;
			}

			p++;
		}

		q++;
		r++;
	}

	r1 = r;
	trinkle(A);

	while (q > 1) {
		--q;

		if (b == 1) {
			r--;
			p--;

			while ((p & 1) == 0) {
				p >>= 1;
				UP(b, c);
			}
		}
		else {
			if (b >= 3) {
				p--;
				r = r - b + c;
				if (p > 0)
					semiTrinkle(A);

				DOWN(b, c);
				p = (p << 1) + 1;
				r = r + c;
				semiTrinkle(A);
				DOWN(b, c);
				p = (p << 1) + 1;
			}
		}
	}
}