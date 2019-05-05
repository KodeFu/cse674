#include "stdafx.h"
#include "MergeSort.h"


CMergeSort::CMergeSort()
{
}


CMergeSort::~CMergeSort()
{
}

void CMergeSort::sort(std::vector<int>& vector)
{
	size_t p = 0; // first element index
	size_t r = vector.size() - 1; // last element index

	mergeSort(vector, p, r);

}

std::string CMergeSort::identify()
{
	return "Merge Sort";
}

/*
Vector A

   p                  q|q+1                 r
  --------------------------------------------
  |  |                 |                     |
  --------------------------------------------
  ^--------- L -------^|^--------- R --------^
    
*/
void CMergeSort::merge(std::vector<int>& vector, int p, int q, int r)
{
	int i, j, k;

	int n1 = q - p + 1; // left deck size
	int n2 = r - q;     // right deck size

	// Left / right deck vectors
	std::vector<int> L;
	std::vector<int> R;

	// create left vector p to q (left deck)
	for (i = 0; i < n1; i++) {
		L.push_back(vector[p + i]);
	}

	// create right vector q+1 to r (right deck)
	for (j = 0; j < n2; j++) {
		R.push_back(vector[(q + 1) + j]);
	}

	// compare top cards from left and right decks; put the 
	// smaller back on the vector (main deck)
	i = 0;
	j = 0;
	for (k = p; i<n1 && j<n2; k++) {
		if (L[i] <= R[j]) {
			vector[k] = L[i];
			i++;
		}
		else {
			vector[k] = R[j];
			j++;
		}
	}

	// merge any left over elements from left vector (left deck)
	while (i < n1)
	{
		vector[k] = L[i];
		i++;
		k++;
	}

	// merge any left over elements from right vector (right deck)
	while (j < n2)
	{
		vector[k] = R[j];
		j++;
		k++;
	}
}

void CMergeSort::mergeSort(std::vector<int>& vector, int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(vector, p, q);
		mergeSort(vector, q + 1, r);
		merge(vector, p, q, r);
	}
}