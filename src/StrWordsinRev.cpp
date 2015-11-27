/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char*, int, int);
void str_words_in_rev(char *input, int len){	
	int index, prevIndex = 0;
	reverse(input, 0, len - 1);		
	for (index = 0; index <= len; index++)
	{
		if (input[index] == 32 || index == len)
		{			
			reverse(input, prevIndex, index - 1);
			prevIndex = index + 1;
		}
	}
}

void reverse(char* inp, int start, int end)
{	
	int length = end - start + 1;
	char temp;
	int counter;
	for (counter = 1; counter <= length / 2; counter++)
	{
		temp = inp[start];
		inp[start++] = inp[end];
		inp[end--] = temp;		
	}
}