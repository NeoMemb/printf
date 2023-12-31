#include "main.h"
/**
 * format_print - Creating a function that uses helper funct
 * -ion to handle s, c, d or i and x
 * @spec: char immediately after '%'
 * @ap: the ellipses -> format specifier variables
 * Return: int
 */
int format_print(char spec, va_list ap)
{
	int count;

	count = 0;
	if (spec == 'c')
		count = printChar(va_arg(ap, int));
	else if (spec == 's')
		count = printStr(va_arg(ap, char *));
	else if (spec == 'd')
		count = printDigit((long)va_arg(ap, int), 10);
	else if (spec == 'i')
		count = printDigit((long)va_arg(ap, int), 10);
	else if (spec == 'x')
		count = printDigit((long)va_arg(ap, unsigned int), 16);
	else if (spec == '%')
		count = printChar('%');
	else if (spec == 'u')
		count = printDigit((unsigned int)va_arg(ap, unsigned int), 10);
	else if (spec == 'X')
		count = printHex((unsigned int)va_arg(ap, unsigned int), 16);
	else if (spec == 'o')
		count = printOct((unsigned int)va_arg(ap, int), 8);
	else if (spec)
		count += printChar('%') + write(1, &spec, 1);
	else
		count = -1;
	return (count);
}
