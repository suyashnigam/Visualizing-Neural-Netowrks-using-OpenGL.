#ifndef PARSESTRING_H_IS_INCLUDED
#define PARSESTRING_H_IS_INCLUDED

int ParseString(int &nWord, int wordTop[], int wordLength[], char str[]);
void SafeStrCpy(char dst[], char src[], int nLetters, int nLimit);
void RemoveTailControlCode(char str[]);
double** ParseWeights(char filename[],int start,int end);
double* ParseBias(char filename[], int start, int end);
#endif