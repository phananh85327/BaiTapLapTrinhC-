#include "stdio.h"
#include "conio.h"

#define MAXSIZE 100

void merge(int array[], int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;

	int *leftArray = new int[subArrayOne];
	int *rightArray = new int[subArrayTwo];

	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	int indexOfSubArrayOne = 0;
	int indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while ((indexOfSubArrayOne < subArrayOne) && (indexOfSubArrayTwo < subArrayTwo))
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else
		{
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne)
	{
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo)
	{
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(int arr[], int const begin, int const end)
{
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

int main()
{
	int n;
	int arr[MAXSIZE];
	
	printf("Nhap so luong phan tu: ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Nhap phan tu %d: ", i);
		scanf_s("%d", &arr[i]);
	}

	printf("Mang truoc khi sap xep: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	mergeSort(arr, 0, n - 1);

	printf("\nMang sau khi sap xep su dung merge sort: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	
	_getch();
}
