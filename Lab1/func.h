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
//структура, що містить дані про студентів
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
//додавання нового елемента з файлу в однозв'язний список
//
void AddStudent(struct Sstudent **pHead, struct Sstudent *pElem);
//
//додавання нового елемента з клавіатури на початок однозв'язного списку
//
void AddNew(struct Sstudent **pHead);
//
//зчитування елементів з файлу в однозв'язний список
//
struct Sstudent *ReadStruct(FILE *pInput);
//
//визначення студентів, народжених влітку
//
int SummerBorn(struct Sstudent *pHead);
//
//видалення наступного елемента від заданого
//
void DelNextStudent(struct Sstudent *pStudent);
//
//видалення попереднього елемента від заданого
//
void DelStudentBegin(struct Sstudent **pHead);
//
//видалення списку елементів
//
void DelStudent(struct Sstudent **pHead);
//
//сортування студентів за зростанням рейтингового балу
//
struct Sstudent *Sort(struct Sstudent *pHead);
//
//виведення одного елемента списку у файл
//
void Print(struct Sstudent *pHead, FILE *pOutput);
//
//виведення усіх елементів списку у файл
//
void PrintStudents(struct Sstudent *pHead, FILE *pOutput);