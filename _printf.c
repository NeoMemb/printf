#include <stdarg.h>
#include <stdio.h>
/**
 * _printf- pring strings either formatted or not
 * @format: pointer to char (string) to be printed to the stdio
 * Description: we iterated over an infinite number of char.
 * If % is found and the next char char after it is either i, d, c
 * ,s, it will have to map it to the variable passed to it after the %.
 * and then printf, sorry, print it to the stdout of the terminal.
 * Return: classified as int.
 */
int _printf(const char *format, ...)
{
	va_list(str);
	va_start(str, format);
	while(*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			if ((*format + 1) == 'd' || (*format == 'i'))
			{
				int num = va_arg(str, int;)
			}
			else if ((*format + 1) == 'c')
			{
				char charact = va_arg(str, char);
			}
			else if ((*format + 1) == 's')
			{
				char *characts = va_ar(str, char);
			}
			format = format + 2;
			else
			{
				putchar(*format);
				format++;
			}
		}
	}
	va_end(str);
}
