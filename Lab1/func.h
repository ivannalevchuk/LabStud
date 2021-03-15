#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define SIZE 30
#define NUMBER_OF_MARKS 3
#define JUNE 6
#define JULY 7
#define AUGUST 8
//
//structure that contains data about students
//
struct Sstudent {
	char cSurname[SIZE];
	char cName[SIZE];
	int nDate[3];
	int nMarks[NUMBER_OF_MARKS];
	double dAverage;
	struct Sstudent *pNext;
};
//
//adding a new element from a file to a singly linked list
//
void AddStudent(struct Sstudent **pHead, struct Sstudent *pElem);
//
//adding a new element from a keyboard to a singly linked list
//
void AddNew(struct Sstudent **pHead);
//
//reading elements from a file into a singly linked list
//
struct Sstudent *ReadStruct(FILE *pInput);
//
//definition of students who were born in summer
//
int SummerBorn(struct Sstudent *pHead);
//
//removing the next element from the given one
//
void DelNextStudent(struct Sstudent *pStudent);
//
//removing the previous element from the given one
//
void DelStudentBegin(struct Sstudent **pHead);
//
//deleting the list of elements
//
void DelStudent(struct Sstudent **pHead);
//
//sorting students in ascending order of rating score
//
struct Sstudent *Sort(struct Sstudent *pHead);
//
//output of one element of the list to a file
//
void Print(struct Sstudent *pHead, FILE *pOutput);
//
//output of all elements of the list to a file
//
void PrintStudents(struct Sstudent *pHead, FILE *pOutput);

