/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void sortArr(int *arr, int st, int end);

void swap(int *a, int *b);

void removeDup(int *Arr, int len);

void * removeArrayDuplicates(int *Arr, int len)
{
	
	if (Arr==NULL || len <0)
		return NULL;

	sortArr(Arr, 0,len - 1);//Sort Given Array - O(nlogn)

	removeDup(Arr, len);//Eliminate duplicates - O(n)
}

void sortArr(int *arr, int leftIndex, int rightIndex){


	int leftHold = leftIndex;
	int rightHold = rightIndex;

	int medianInd;
	int pivotElement;
	int pivotIndex;

	medianInd = (leftIndex + rightIndex) / 2;

	swap(&arr[leftIndex], &arr[medianInd]);

	pivotElement = arr[leftIndex];

	

	while (leftIndex < rightIndex){


		while (arr[rightIndex] >= pivotElement && leftIndex < rightIndex)
			--rightIndex;

		if (leftIndex != rightIndex)
			arr[leftIndex++] = arr[rightIndex];

		while (arr[leftIndex] <= pivotElement && leftIndex < rightIndex)
			++leftIndex;

		if (leftIndex != rightIndex)
			arr[rightIndex--] = arr[leftIndex];


		}

	arr[leftIndex] = pivotElement;
	pivotIndex = leftIndex;

	if (leftHold < pivotIndex)
		sortArr(arr, leftHold, pivotIndex - 1);

	if (rightHold> pivotIndex)
		sortArr(arr, pivotIndex + 1, rightHold);
	}

void swap(int *a, int *b){

	int temp = *a;

	*a = *b;
	*b = temp;
	}

void removeDup(int *Arr, int len){

	int i,j=0;

	for (i = 0; i < len-1 ; i++){

		if (Arr[i] != Arr[i+1]){
			Arr[j] = Arr[i];
			j++;
			}
		else{
			Arr[j] = Arr[i];
			j++;
			i++;
			}

		}
		
	Arr[j] = Arr[i];

	}