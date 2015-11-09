/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{

	//Check if input is valid
	if (Arr==NULL || len<0)
		return NULL;

	int i;
	int pos1=-1, pos2=-1;//Holds positions of swapped elements
	int flag1=0, flag2=0;//Flag1 indicates swapped position1 flag and Flag2 indicates swapped position 2


	//To find the positions of the swapped elements
	for (i = 0; i < len - 1; i++){

		if (Arr[i + 1] < Arr[i] && flag1 != 1){

			pos1 = i;
			flag1 = 1;
			}
		else if (Arr[i + 1] < Arr[i] && flag2 != 1 && flag1 == 1){

			pos2 = i + 1;
			flag2 = 1;
			}
		}

	if (flag2 == 0){
		pos2 = pos1 + 1;
		flag2 = 1;
		}
	if (flag1 && flag2){
		int temp;
		temp = Arr[pos1];
		Arr[pos1] = Arr[pos2];
		Arr[pos2] = temp;
		}


}