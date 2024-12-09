#include "QuickSort.h"

int partition(point* arr, int left, int right)
{
	pointsSwap(arr, (right + left) / 2, right);
	point pivot = arr[right];
	int pInd = left;
	for (int i = left; i < right; i++)
	{
		if (pointsCompare(arr[0], pivot, arr[i]))
		{
			pointsSwap(arr, i, pInd);
			pInd++;
		}
	}
	pointsSwap(arr, pInd, right);
	return pInd;
}

void quickSort(point* arr, int left, int right)
{
	if (left < right) {
		int pivot = partition(arr, left, right);

		quickSort(arr, left, pivot - 1);

		quickSort(arr, pivot + 1, right);
	}
}