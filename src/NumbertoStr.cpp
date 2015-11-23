/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int reverse(float);
void number_to_str(float number, char *str,int afterdecimal){
	int index=0;
	if (number < 0)
	{
		str[index++] = '-';
		number *= -1;
	}
	int revNumber=reverse(number);
	while (revNumber > 0)
	{
		str[index++] = revNumber % 10 + '0';		
		revNumber /= 10;
	}
	str[index++] = '.';
	//re-using revNumber as a counter in loop
	for (revNumber = 1; revNumber <= afterdecimal; revNumber++)
	{
		number *= 10;
		str[index++] = (int)number % 10     + '0';
	}
}

int reverse(float number)
{
	int result;
	for (result = 0; number > 0.9; number /= 10)
	{
		result = result * 10 + (int)number % 10;
	}
	return result;
}
