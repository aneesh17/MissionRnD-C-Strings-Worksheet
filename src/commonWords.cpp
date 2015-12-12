/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int strlen(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int split(char** Str1, char* str1)
{
	int i, len1;
	int wordLen1 = 3;
	int index1 = 0;
	int indexChar1 = 0;
	len1 = strlen(str1);
	for (i = 0; i <= len1; i++)
	{
		if (str1[i] == 32)
		{
			while (indexChar1<31)
			{
				Str1[index1][indexChar1++] = '\0';
			}
			index1++;
			indexChar1 = 0;
			continue;
		}
		Str1[index1][indexChar1++] = str1[i];
	}
	return index1;
}

int strcmp(char* str1, char* str2)
{
	int i;
	for (i = 0; i<strlen(str1); i++)
	{
		if (str1[i] == str2[i])
		{
			continue;
		}
		return 0;
	}
	return 1;
}

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;

	int i, j, k, wordLen1 = 31, wordLen2 = 31, resultLen = 31;
	int indexChar1 = 0, indexChar2 = 0, resultChar = 0, resultIndex = 0;

	char ** Str1, **Str2, **result;

	Str1 = (char**)malloc(wordLen1 * sizeof(char*));

	for (i = 0; i<31; i++)
	{
		Str1[i] = (char*)malloc(31 * sizeof(char));
	}

	Str2 = (char**)malloc(wordLen2 * sizeof(char*));

	for (i = 0; i<31; i++)
	{
		Str2[i] = (char*)malloc(31 * sizeof(char));
	}

	result = (char**)malloc(resultLen * sizeof(char*));

	for (i = 0; i<31; i++)
	{
		result[i] = (char*)malloc(31 * sizeof(char));
	}
	for (i = 0; i < 31; i++)
	{
		for (j = 0; j < 31; j++)
		{
			result[i][j] = '\0';
		}
	}

	wordLen1 = split(Str1, str1);
	wordLen2 = split(Str2, str2);

	for (i = 0; i <= wordLen1; i++)
	{
		for (j = 0; j <= wordLen2; j++)
		{
			if (strcmp(Str1[i], Str2[j]))
			{
				for (k = 0; k<strlen(Str1[i]); k++)
				{
					result[resultIndex][resultChar++] = Str1[i][k];
				}				

				resultIndex++;
				resultChar = 0;
			}
		}
	}	
	if (result[0][0] == '\0')
		return NULL;
	return result;
}