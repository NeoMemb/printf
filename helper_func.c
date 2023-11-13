#include <unistd.h>
#include "main.h"
/**
 * printChar - helper helper that prints chars
 * @c: the char to be printed
 * Return: the char to be printed
 */
int printChar(int c)
{
	return (write(1, &c, 1));
}
/**
 * printDigit - print digits either hex or decimal/
 * @N: long data type and the index for string chars
 * @baseNumb: number base
 * Return: count
 */
int printDigit(long N, int baseNumb)
{
	int count;
	char *symbols;

	symbols = "0123456789abcdef";
	if (N < 0)
	{
		write(1, "-", 1);
		return (printDigit(-N, baseNumb) + 1);
	}
	else if (baseNumb > N)
		return (printChar(symbols[N]));
	else if (baseNumb < N)
	{
		count = printDigit(N / baseNumb, baseNumb);
		return (count + printDigit(N % baseNumb, baseNumb));
	}
	return (0);
}
/**
 * printStr - another helper func that prints string
 * @s: pointer to char(A.K.A string) to be printed
 * Return: count
 */
int printStr(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		count += write(1, s++, 1);
	}
	return (count);
}
