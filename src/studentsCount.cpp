
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

int binSearch(int* Arr, int st, int end, int key);

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	
	int count = 0,ind;

	//Check For Invalid Inputs
	if (Arr == NULL || len <0)
		return NULL;

	//If there is only one element in the arrays
	if (len == 1){
		if (Arr[0] < score){
			*lessCount = 1;
			*moreCount = 0;
			return 0;
			}
		else if (Arr[0]>score){
			*moreCount = 1;
			*lessCount = 0;
			return 0;
			}
		else
			*lessCount = *moreCount = 0;
			return 0;
		}

	ind = binSearch(Arr, 0, len - 1, score);

	if (ind != -1){//if score is found in the array
		*lessCount = ind;
		*moreCount = len - ind - 1;
		
		int i;

		int lessInd = ind-1;
		int moreInd = ind + 1;

		for (i = lessInd; Arr[i] == score; i--)
			*lessCount = *lessCount - 1;

		for (i = moreInd; Arr[i] == score; i++)
			*moreCount = *moreCount - 1;

		return 0;
		}
	else{//if the score 

		int i = 0;

		for (i; i < len; i++){
			if (Arr[i]>score)
				break;
			}

		*lessCount = i;
		*moreCount = len - i ;

		}

	//return NULL;
}

int binSearch(int* Arr, int st, int end, int key){

	if (st > end)
		return -1;
	
	int mid = (st + end) / 2;
	
	if (Arr[mid] == key){
		

			return mid;
		}
	else if (Arr[mid] < key)
		return binSearch(Arr, mid + 1, end, key);
	else
		return binSearch(Arr, st, mid - 1, key);
	}
