/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void sortAccScores(struct student *students,int st, int end);

int partitionFunction(struct student *students, int st, int end);

void swapSt(struct student *st1, struct student *st2);

void * scoresDescendingSort(struct student *students, int len) {
	
	if (students==NULL || len<0)
		return NULL;

	sortAccScores(students,0,len-1 );


}

void sortAccScores(struct student *students, int leftIndex, int rightIndex){
	

	int leftHold = leftIndex;
	int rightHold = rightIndex;

	int medianInd;
	int pivotElement;
	int pivotIndex;

	medianInd = (leftIndex + rightIndex) / 2;

	swapSt(&students[leftIndex], &students[medianInd]);

	pivotElement = students[leftIndex].score;

	struct student pivot = students[leftIndex];

	while (leftIndex < rightIndex){

		
		while (students[rightIndex].score <= pivotElement && leftIndex < rightIndex)
			--rightIndex;

		if (leftIndex != rightIndex)
			students[leftIndex++] = students[rightIndex];

		while (students[leftIndex].score >= pivotElement && leftIndex < rightIndex)
			++leftIndex;

		if (leftIndex != rightIndex)
			students[rightIndex--] = students[leftIndex];


		}

	students[leftIndex] = pivot;
	pivotIndex = leftIndex;

	if (leftHold < pivotIndex)
		sortAccScores(students, leftHold, pivotIndex - 1);

	if (rightHold> pivotIndex)
		sortAccScores(students, pivotIndex + 1, rightHold);

	}

void swapSt(struct student *st1, struct student *st2){

	struct student st = *st1;
	*st1 = *st2;
	*st2 = st;

	}