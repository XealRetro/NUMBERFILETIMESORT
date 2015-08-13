#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class NumberFileSort{

private:
	double time_spent;
	clock_t tStart;
	clock_t tFinish;
	int *yourArray;

public:
	NumberFileSort();
	long readIntoSort(char* fileName, long howMany);
	double BubbleSort(int arrayA[], int howMany);
	double SelectionSort(int arrayB[], int howMany);
	double InsertionSort(int arrayC[], int howMany);


};

NumberFileSort::NumberFileSort()
{

}

long NumberFileSort::readIntoSort(char* fileName, long howMany)
{
	int holdNum;
	ifstream aFile;
	aFile.open(fileName);
	if (!aFile)
	{
		cout << "Error opening file";
	}

	int *yourArray = new int[howMany];

	for (int i = 0; i < howMany; i++)
	{
		aFile >> holdNum;
		yourArray[i] = holdNum;
	}
	
	int *copyArray = new int[howMany];
	memcpy(copyArray, yourArray, howMany*sizeof(int));
	InsertionSort(copyArray, howMany);
	memcpy(copyArray, yourArray, howMany*sizeof(int));
	BubbleSort(copyArray, howMany);
	memcpy(copyArray, yourArray, howMany*sizeof(int));
	SelectionSort(copyArray, howMany);
	delete[] copyArray;
	delete[] yourArray;
	
	return 0;

}

double NumberFileSort::BubbleSort(int arrayA[], int howMany)
{
	int c;
	int d;
	int temp;

	tStart = clock();

	for (c = 0; c < (howMany - 1); c++)
	{
		for (d = 0; d < howMany - c - 1; d++)
		{
			if (arrayA[d] > arrayA[d - 1])
			{
				temp = arrayA[d];
				arrayA[d] = arrayA[d - 1];
				arrayA[d] = temp;
			}
		}
	}
	
	tFinish = clock();	

	time_spent = (double)(tFinish - tStart) / CLOCKS_PER_SEC;

	cout << "ELAPSED TIME FOR BUBBLE SORT: " << time_spent << " SECONDS" << endl;
	
	
	return 0;
}


double NumberFileSort::SelectionSort(int arrayB[], int howMany)
{
	int i;
	int k;
	int swap;
	int position;

	tStart = clock();
	for (i = 0; i < (howMany - 1); i++)
	{
		position = i;
		for (k = i + 1; k < howMany; k++)
		{
			if (arrayB[position] > arrayB[k])
			{
				position = k;
			}
		}
		if (position != i)
		{
			swap = arrayB[i];
			arrayB[i] = arrayB[position];
			arrayB[position] = swap;
			
		}
	}
	tFinish = clock();
	time_spent = (double)(tFinish - tStart) / CLOCKS_PER_SEC;

	cout << "ELAPSED TIME FOR SELECTION SORT: " << time_spent << " SECONDS" << endl;

	
	return 0;
}

double NumberFileSort::InsertionSort(int arrayC[], int howMany)
{
	int c;
	int d;
	int t = 0;
	//int comp = 0;				For debugging
	//unsigned int swaps = 0;

	tStart = clock();
	for (c = 1; c <= howMany - 1; c++) {
		d = c;
	//	comp++;

		while (d > 0 && arrayC[d] < arrayC[d - 1]) {
			t = arrayC[d];
			arrayC[d] = arrayC[d - 1];
			arrayC[d - 1] = t;

			d--;
			//swaps++;
		}
	}
	tFinish = clock();
	time_spent = (double)(tFinish - tStart) / CLOCKS_PER_SEC;

	cout << "ELAPSED TIME FOR INSERTION SORT: " << time_spent << " SECONDS" << endl;
	//cout << "SWAPS: " << swaps << endl;
	//cout << "COMPARISONS: " << comp << endl;

	
	return 0;

}