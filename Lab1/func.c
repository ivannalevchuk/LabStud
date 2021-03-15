#include "func.h"

//--------------------------------------------------------------------------------------------------

void AddStudent(struct Sstudent **pHead, struct Sstudent *pElem) {
	struct Sstudent *p = *pHead;
	pElem->pNext = p->pNext;
	p->pNext = pElem;
}

//--------------------------------------------------------------------------------------------------

void AddNew(struct Sstudent **pHead) {
	struct Sstudent *pTmp = malloc(sizeof(struct Sstudent));	
	double dAvr_mark = 0;
	printf("\n");
	printf("Enter surname: ");
	scanf("%s", pTmp->cSurname);
	printf("Enter name: ");
	scanf("%s", pTmp->cName);
	printf("Enter day: ");
	scanf("%d", &pTmp->nDate[0]);
	printf("Enter month: ");
	scanf("%d", &pTmp->nDate[1]);
	printf("Enter year: ");
	scanf("%d", &pTmp->nDate[2]);
	printf("Enter 3 marks: ");
for (int i = 0; i < NUMBER_OF_MARKS; i++) {
		scanf( "%d", &(pTmp->nMarks[i]));
		dAvr_mark += pTmp->nMarks[i];
	}
dAvr_mark /= NUMBER_OF_MARKS;
pTmp->dAverage = dAvr_mark;
	pTmp->pNext = (*pHead);
	(*pHead) = pTmp;
}

//--------------------------------------------------------------------------------------------------

struct Sstudent *ReadStruct(FILE *pInput){
	struct Sstudent* p = malloc(sizeof(struct Sstudent));
	fscanf(pInput, "%s %s %d %d %d", p->cSurname, p->cName, &(p->nDate[0]), &(p->nDate[1]), &(p->nDate[2]));
	double dAvr_mark = 0;
	for (int i = 0; i < NUMBER_OF_MARKS; i++) {
		fscanf(pInput, "%d", &(p->nMarks[i]));
		dAvr_mark += p->nMarks[i];
	}
	dAvr_mark /= NUMBER_OF_MARKS;
	p->dAverage = dAvr_mark;
	p->pNext = NULL;
	struct Sstudent *pNew;
	while (!feof(pInput)) {
		pNew = malloc(sizeof(struct Sstudent));
		fscanf(pInput, "%s %s %d %d %d", pNew->cSurname, pNew->cName, &(pNew->nDate[0]), &(pNew->nDate[1]), &(pNew->nDate[2]));
		double dAvr_mark = 0;
		for (int i = 0; i < NUMBER_OF_MARKS; i++) {
			fscanf(pInput, "%d", &(pNew->nMarks[i]));
			dAvr_mark += pNew->nMarks[i];
		}
		dAvr_mark /= NUMBER_OF_MARKS;
		pNew->dAverage = dAvr_mark;
		AddStudent(&p, pNew);
	}
	return p;
}

//--------------------------------------------------------------------------------------------------

int SummerBorn(struct Sstudent* pHead) {
	if (pHead->nDate[1] == JUNE || pHead->nDate[1] == JULY || pHead->nDate[1] == AUGUST) {
		return 1;
	}
	return 0;
}

//--------------------------------------------------------------------------------------------------

void DelNextStudent(struct Sstudent *pStudent){
	struct Sstudent *pTmp = pStudent->pNext;
	pStudent->pNext = pTmp->pNext;
	free(pTmp);
}

//--------------------------------------------------------------------------------------------------

void DelStudentBegin(struct Sstudent **pHead) {
	struct Sstudent *pSecond = (*pHead)->pNext;
	free(*pHead);
	*pHead = pSecond;
}

//--------------------------------------------------------------------------------------------------

void DelStudent(struct Sstudent **pHead) {
	while (*pHead) {
		DelStudentBegin(pHead);
	} 
}

//--------------------------------------------------------------------------------------------------

struct Sstudent *Sort(struct Sstudent *pHead) {
	struct Sstudent *pNewHead = NULL;
	while (pHead != NULL) {
		struct Sstudent* p = pHead;
		pHead = pHead->pNext;
		if (pNewHead == NULL || p->dAverage < pNewHead->dAverage) {
			p->pNext = pNewHead;
			pNewHead = p;
		}
		else {
			struct Sstudent* pCurrent = pNewHead;
			while (pCurrent->pNext != NULL && !(p->dAverage < pCurrent->pNext->dAverage)) {
				pCurrent = pCurrent->pNext;
			}
			p->pNext = pCurrent->pNext;
			pCurrent->pNext = p;
		}
	}
	return pNewHead;
}

//--------------------------------------------------------------------------------------------------

void Print(struct Sstudent *pHead, FILE *pOutput) {
	fprintf(pOutput, "\n");
	fprintf(pOutput,"|%-14s | %-10s | %02d | %02d | %4d |", pHead->cSurname, pHead->cName, pHead->nDate[0], pHead->nDate[1], pHead->nDate[2]);
	for (int i = 0; i < NUMBER_OF_MARKS; i++) {
		fprintf(pOutput," %d |", (pHead->nMarks[i]));
	}
	fprintf(pOutput,"% 4.2lf |", pHead->dAverage);
	fprintf(pOutput,"\n");
}

//--------------------------------------------------------------------------------------------------

void PrintStudents(struct Sstudent *pHead, FILE *pOutput) {
	fprintf(pOutput, "Surname           Name         Date of Birth     Marks    Average \n");
	if (pHead) {
		do {
			Print(pHead, pOutput);
		} while (pHead = pHead->pNext);
	}
}

