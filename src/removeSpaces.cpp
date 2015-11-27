/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str)
{
	if (str == '\0')
		return '\0';
	int index = 0, target;//target stores the index value where the variable should be shifted to
	for (; str[index] != 32; index++)
	{
		if (str[index] == '\0')
			return 0;
	}
	target = index;//target stores value of index with space. next variable is shifted to this index and taget value is updated to next index, thus overwriting the copy of value
	for (index = index + 1; str[index] != '\0'; index++)
	{
		if (str[index] == 32)
			continue;
		str[target] = str[index];
		target++;
	}
	for (; target<index; target++)
		str[target] = '\0';	
	return '\0';
}