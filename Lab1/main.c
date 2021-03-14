#include "func.h"

int main(){
	struct Sstudent *pHead = NULL;
	FILE *pfR = fopen("stud.txt", "r");
	FILE *pfW = fopen("student.txt", "w");
	pHead = ReadStruct(pfR);
	struct Sstudent *pFirst = pHead;
	printf("Choose one option: \n");
	printf("\n");
	printf("'r'- show the entire list of students\n'a'- add student\n's'- show summerborn students\n\
\'l'- show students whose GPA is below than 4.5\n");
	printf("\n");
	char cH;
	scanf("%c", &cH);
	if (cH != 'r' && cH != 'a' && cH != 's' && cH != 'l') {
		printf("\n");
		printf("Wrong input. Try again\n");
	}
	else {
		switch (cH) {
		case 'r':
			fprintf(pfW, "Students:\n");
			fprintf(pfW, "\n");
			pHead = Sort(pHead);
			PrintStudents(pHead, pfW);
			break;
		case 'a':
			fprintf(pfW, "List with added student: \n");
			fprintf(pfW, "\n");
			AddNew(&pHead);
			pHead = Sort(pHead);
			PrintStudents(pHead, pfW);
			break;
		case 'l':
			fprintf(pfW, "Students with low average: \n");
			fprintf(pfW, "\n");
			while (pFirst = pFirst->pNext) {
				if ((pFirst->dAverage) < 4.5)
					Print(pFirst, pfW);
			}
			break;
		case 's':
			while (!SummerBorn(pHead))
				DelStudentBegin(&pHead);
			pFirst = pHead;
			while ((pFirst = pFirst->pNext) && pFirst->pNext) {
				while (pFirst->pNext && !SummerBorn(pFirst->pNext))
					DelNextStudent(pFirst);
			}
			fprintf(pfW, "Students who were born in summer:\n");
			fprintf(pfW, "\n");
			pHead = Sort(pHead);
			PrintStudents(pHead, pfW);
			break;
		case'e':
			return 1;
			break;
		}
		printf("\n");
		puts("Done! Check the file 'student.txt'");
	}
	DelStudent(&pHead);
	fclose(pfR);
	fclose(pfW);
	_getch();
	return 0;
}
