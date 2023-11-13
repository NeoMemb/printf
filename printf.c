#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
	else if
	{
		count = (printDigit(N / baseNumb, baseNumb));
		return (count + printDigit(N % baseNumb, baseNumb));
	}
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
/**
 * format_print - Creating a function that uses helper funct
 * -ion to handle s, c, d or i and x
 * @spec: char immediately after '%'
 * @ap: the ellipses -> format specifier variables
 * Return: int i
 */
int format_print(char spec, va_list ap)
{
	int count;

	count = 0;
	if (spec == 'c')
	{
		count = printChar(va_arg(ap, int));
	}
	else if (spec == 's')
	{
		count = printStr(va_arg(ap, char *));
	}
	else if (spec == 'd')
	{
		count = printDigit((long)va_arg(ap, int), 10);
	}
	else if (spec == 'x')
	{
		count = printDigit((long)va_arg(ap, unsigned int), 16);
	}
	else
	{
		count += write(1, &spec, 1);
	}
	return (count);
}

/**
 * _printf - functioning as printf
 * @format: pointer the char(string)
 * which is to be printed
 *
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list	ap;
	int count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			count += format_print(*(format + 1), ap);
		}
		else
		{
			count += write(STDOUT_FILENO, format, 1);
		}
		++format;
	}
	va_end(ap);
	return (count);
}
