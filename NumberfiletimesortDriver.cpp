#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Numberfiletimesort.h"


#define FILE_NAME_500 "NumFile500.txt"
#define FILE_NAME_5K "NumFile5K.txt"
#define FILE_NAME_25K "NumFile25K.txt"
#define FILE_NAME_100K "NumFile100K.txt"

#define LIST_SIZE_500 500
#define LIST_SIZE_5K 5000
#define LIST_SIZE_25K 25000
#define LIST_SIZE_100K 100000

using namespace std;

int main(void)
{
	NumberFileSort sortFile;

	
	cout << "SORTING LIST OF 100K NUMBERS" << endl;
	sortFile.readIntoSort(FILE_NAME_500, LIST_SIZE_500);
	cout << endl;
	cout << "SORTING LIST OF 5K NUMBERS" << endl;
	sortFile.readIntoSort(FILE_NAME_5K, LIST_SIZE_5K);
	cout << endl;
	cout << "SORTING LIST OF 25K NUMBERS" << endl;
	sortFile.readIntoSort(FILE_NAME_25K, LIST_SIZE_25K);
	cout << endl;
	cout << "SORTING LIST OF 100K NUMBERS" << endl;
	sortFile.readIntoSort(FILE_NAME_100K, LIST_SIZE_100K);
	cout << endl;

	system("pause");
	return 0;
}