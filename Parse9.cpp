#include "Parse9.h"
#include <string.h>
#include <iostream>

HugeWeights::HugeWeights(FILE * fp1)
{
	fp = fp1;

}

double** HugeWeights::Run(void) {
	rowPointer = new double*[numOfLines];

	if (fp != nullptr)
		ParseText1(); // Parse text line by line from the file and store it in a twoD array
	else
		rowPointer = nullptr;
	
	return rowPointer;
}

double* HugeWeights::ProcessLine(char* line, int numInLine) {

	int nCharInLine = strlen(line);
	double* numIdentified = new double[numInLine]; // Array of double numbers
	char* charNum = new char[20]; // maximum of 15 digits in the double number
	int charNumPointer = 0, iNumIdentified = 0, flagForNumToParse = 0;

	for (int i = 0; i < nCharInLine; i++) {
		if (line[i] != ' ' && line[i] != '\n'&& line[i] != '\t') {
			charNum[charNumPointer] = line[i]; // store the number until you encounter a space
			charNumPointer++;
			flagForNumToParse = 1;
		}
		else {
			if (flagForNumToParse == 1) {

				charNum[charNumPointer] = 0; // To indicate the end of the char Num charecter
				numIdentified[iNumIdentified] = atof(charNum); // Convert the char to double
				iNumIdentified++;

				flagForNumToParse = 0;

				charNumPointer = 0;
				delete[] charNum;
				charNum = new char[15];
			}
		}
	}

	return numIdentified;
}


void HugeWeights::ParseText1() {

	int iLine = 0;
	char line[1000000];

	while (nullptr != fgets(line, 1000000, fp)) {
		rowPointer[iLine++] = ProcessLine(line, numInLine);
	}
}
