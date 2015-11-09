/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int findPos(int *Arr, int len, int num);

void insertInArray(int *Arr, int len, int num, int pos);

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	
	if (len < 0 || Arr==NULL)
		return NULL;

	Arr = (int *)realloc( Arr,(len + 1)*sizeof(int) );

	//Arr[5] = 20;
	int pos = findPos(Arr, len, num);

	insertInArray(Arr, len + 1, num, pos);

	return Arr;
}

void insertInArray(int *Arr, int len, int num, int pos){

	int i = len-1;

	for (i; i > pos; i--){
		Arr[i] = Arr[i - 1];
		}

	Arr[pos] = num;
	}

int findPos(int *Arr, int len, int num){

	int i ;

	for (i = 1; i < len; i++){
		
		
			if (Arr[i - 1]<num && Arr[i ]>num)
				return i;

		}

	if (Arr[0]>num)
		return 0;
	else if (Arr[len - 1] < num)
		return len;

	}