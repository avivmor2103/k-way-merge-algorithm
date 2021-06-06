#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include  "kWayMergeAlgorithm.h"
#define MAX_SIZE 100

long int* checkFile(ifstream& file, int n);
bool checkLine(char* line);
void compareNtoK(int n, int k);
void checkNandK(int size);

using namespace std;
int main()
{
	char* fileNameInput = new char[MAX_SIZE] ;
	char* fileNameOutput = new char[MAX_SIZE];
	int n, k, indexForArr = 0;
	cout << "please insert amount of numbers :" << endl;
	cin >> n;
	cout << "Please insert the K division :" << endl;
	cin >> k;
	long int* newArr = new long int[n];
	cout << "Please insert the inpute file name :" << endl;
	cin >> fileNameInput;
	cout << "Please insert the output file name:" << endl;
	cin >> fileNameOutput;
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open(fileNameInput);
	if (!inputFile.is_open())
	{
		cout << "File Not Good , worng input" << endl;
		exit(1);
	}
	outputFile.open(fileNameOutput);
	newArr = checkFile(inputFile , n);
	kWayMergeAlgorithm* toMerge = new kWayMergeAlgorithm();
	toMerge->kWayMergeAlgo(k, n, newArr);
	for (int i = 0; i < n; i++)
		outputFile << newArr[i] << endl;
	outputFile.close();
	for (int i = 0; i < n; i++)
			cout << newArr[i] << endl;
}

long int* checkFile(ifstream& file, int n)
{
	long int* arr = new long int[n];
	int i = 0;
	char* line = new char(MAX_SIZE);
	if (!file)
	{
		cout << "Wroge Input" << endl;
		exit(1);
	}

	while (!file.eof() && i < n)
	{
		file.getline(line, MAX_SIZE);
		if (!checkLine(line))
		{
			cout << "Wronge Input";
			exit(1);
		}
		arr[i] = atoi(line);
		i++;
	}
	if(i < n)
	{ 
		cout << "Wronge Input";
		exit(1);
	}
	if (!file.eof())
	{
		cout << "Wronge Input";
		exit(1);
	}
	return arr; 
}

bool checkLine(char* line)
{
	int i = 0;
	while (line[i] != '\0')
	{
		if (line[0] != '-' && line[0] < 0 && line[0] > 9)
			return false;

		else if (line[i] < 0 && line[i] > 9)
			return false;

		i++;
	}
	return true;
}

void compareNtoK(int n, int k)
{
	if (k > n)
	{
		cout << " wronge Inpute";
		exit(1);
	}
}

void checkNandK(int size)
{
	if (size <= 0)
	{
		cout << "Wronge Inpute" << endl;
		exit(1);
	}
}