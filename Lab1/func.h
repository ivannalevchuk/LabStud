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
//���������, �� ������ ��� ��� ��������
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
//��������� ������ �������� � ����� � ������'����� ������
//
void AddStudent(struct Sstudent **pHead, struct Sstudent *pElem);
//
//��������� ������ �������� � ��������� �� ������� ������'������ ������
//
void AddNew(struct Sstudent **pHead);
//
//���������� �������� � ����� � ������'����� ������
//
struct Sstudent *ReadStruct(FILE *pInput);
//
//���������� ��������, ���������� �����
//
int SummerBorn(struct Sstudent *pHead);
//
//��������� ���������� �������� �� ��������
//
void DelNextStudent(struct Sstudent *pStudent);
//
//��������� ������������ �������� �� ��������
//
void DelStudentBegin(struct Sstudent **pHead);
//
//��������� ������ ��������
//
void DelStudent(struct Sstudent **pHead);
//
//���������� �������� �� ���������� ������������ ����
//
struct Sstudent *Sort(struct Sstudent *pHead);
//
//��������� ������ �������� ������ � ����
//
void Print(struct Sstudent *pHead, FILE *pOutput);
//
//��������� ��� �������� ������ � ����
//
void PrintStudents(struct Sstudent *pHead, FILE *pOutput);