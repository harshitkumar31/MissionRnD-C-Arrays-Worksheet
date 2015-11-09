/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void swapStu(struct student *st1, struct student *st2);
void sortScores(struct student *students, int st, int end);


struct student ** topKStudents(struct student *students, int len, int K) {
	
	if (K<=0||len<0||students==NULL)
		return NULL;

	if (K>len)
		return &students;

	if (K == 1){

		struct student *max = &students[0];
		int maxInd = 0;
		int i;

		for (i = 1; i < len; i++){

			if (students[i].score > (*max).score){
				max = &students[i];
				maxInd = i;
				}
			}

		return  &max;

		}
	else{

		struct student *topK = (struct student*)calloc(K, sizeof(struct student));

		sortScores(students, 0, len - 1);

		int i;

		for (i = 0; i < K; i++)
			topK[i] = students[i];

		return &topK;

		}


}


void sortScores(struct student *students, int leftIndex, int rightIndex){


	int leftHold = leftIndex;
	int rightHold = rightIndex;

	int medianInd;
	int pivotElement;
	int pivotIndex;

	medianInd = (leftIndex + rightIndex) / 2;

	swapStu(&students[leftIndex], &students[medianInd]);

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
		sortScores(students, leftHold, pivotIndex - 1);

	if (rightHold> pivotIndex)
		sortScores(students, pivotIndex + 1, rightHold);

	}

void swapStu(struct student *st1, struct student *st2){

	struct student st = *st1;
	*st1 = *st2;
	*st2 = st;

	}