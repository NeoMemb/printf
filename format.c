#include <stdarg.h>
#include <unistd.h>
#include "main.h"
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
	else if (spec == '%')
	{
		count = printChar(va_arg(ap, int));
	}
	else if (!spec)
	{
		count = -1;
	}
	else
	{
		count += write(1, &spec, 1);
	}
	return (count);
}
