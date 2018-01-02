#include "ParseString.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int ParseString(int &nWord, int wordTop[], int wordLength[], char str[])
{
	int i, state;

	state = 0;
	nWord = 0;
	for (i = 0; str[i] != 0; i++)
	{
		switch (state)
		{
		case 0:
			if (str[i] != ' ' &&
				str[i] != '\t' &&
				str[i] != ',')
			{
				state = 1;
				wordTop[nWord] = i;
				wordLength[nWord] = 1;
				nWord++;
			}
			break;
		case 1:
			if (str[i] != ' ' &&
				str[i] != '\t' &&
				str[i] != ',')
			{
				wordLength[nWord - 1]++;
			}
			else
			{
				state = 0;
			}
			break;
		}
	}

	return nWord;
}
void SafeStrCpy(char dst[], char src[], int nLetters, int nLimit)
{
	int i, stopper;
	if (nLetters<nLimit)
	{
		stopper = nLetters;
	}
	else
	{
		stopper = nLimit;
	}

	for (i = 0; i<stopper; i++)
	{
		dst[i] = src[i];
	}
	dst[stopper] = 0;
}

void RemoveTailControlCode(char str[])
{
	int i, lng;
	lng = strlen(str);
	for (i = lng - 1; i >= 0; i--)
	{
		if (isprint(str[i]) == 0)
		{
			str[i] = 0;
		}
		else
		{
			break;
		}
	}
}

double** ParseWeights(char filename[], int start, int end)
{
	//Count the number of filters
	//FILE *fp;
	int num = 0;
	/*
	fp = fopen(filename, "r");
	

	if (fp != NULL)
	{
		char str[256];

		while (fgets(str, 255, fp) != NULL)
		{
			str[255] = 0;
			RemoveTailControlCode(str);
			if (str[0] == 'v')
			{
				num_filters++;
			}
		}
	}
	fclose(fp);
	*/
	num = end - start;
	//Initialize 2d array pointer
	double** filter;
	filter = new double*[num];
	for (int i = 0; i < num; i++)
	{
		filter[i] = new double[9];
	}

	//Store the weigths.................
	FILE *fp1;
	fp1 = fopen(filename, "r");
	if (fp1 != NULL)
	{
		char str[256];
		char get_line[256];
		int num_filters = 0;
		int count = 0;
		while (fgets(str, 255, fp1) != NULL)
		{
			str[255] = 0;
			get_line[255] = 0;

			RemoveTailControlCode(str);
			if (str[0] == 'v')
			{
				num_filters++;
				if (num_filters > start && num_filters <= end)
				{
					fgets(get_line, 255, fp1);
					
					for (int i = 0; i < 3; i++)
					{
						int nWord, wordTop[16], wordLength[16];
						char w1[256], w2[256], w3[256];

						fgets(get_line, 255, fp1);
						ParseString(nWord, wordTop, wordLength, get_line);

						SafeStrCpy(w1, get_line + wordTop[0], wordLength[0], 255);
						SafeStrCpy(w2, get_line + wordTop[1], wordLength[1], 255);
						SafeStrCpy(w3, get_line + wordTop[2], wordLength[2], 255);

						*(filter[count] + 3 * i) = atof(w1);
						*(filter[count] + 3 * i + 1) = atof(w2);
						*(filter[count] + 3 * i + 2) = atof(w3);
					}
					count++;
				}
				if (num_filters > end)
				{
					break;
				}
						//printf("%d\n", num_filters);
			}
		}
		
	}
	fclose(fp1);

	return filter;

}

double* ParseBias(char filename[], int start, int end)
{
	
	int num = 0;

	num = end - start;
	//Initialize 2d array pointer
	double* filter;
	filter = new double[num];
	
	//Store the weigths.................
	FILE *fp1;
	fp1 = fopen(filename, "r");
	if (fp1 != NULL)
	{
		char str[256];
		char get_line[256];
		int num_filters = 0;
		int count = 0;
		while (fgets(str, 255, fp1) != NULL)
		{
			str[255] = 0;
			get_line[255] = 0;

			RemoveTailControlCode(str);
			if (str[0] == 'v')
			{
				num_filters++;
				if (num_filters > start && num_filters <= end)
				{
					fgets(get_line, 255, fp1);
					int nWord, wordTop[16], wordLength[16];
					char w[256];
					fgets(get_line, 255, fp1);
				
					filter[count] = atof(get_line);
					count++;
				}
				if (num_filters > end)
				{
					break;
				}
						//printf("%d\n", num_filters);
			}
		}
		
	}
	fclose(fp1);

	return filter;

}