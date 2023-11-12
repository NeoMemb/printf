#include <stdarg.h>
#include <stdio.h>

/**
 * _putchar - Creating a function that prints out char
 * @c: char to be printed
 * Return: int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf- pring strings either formatted or not
 * @format: pointer to char (string) to be printed to the stdio
 * Description: we iterated over an infinite number of char.
 * If % is found and the next char char after it is either i, d, c
 * ,s, it will have to map it to the variable passed to it after the %.
 * and then printf, sorry, print it to the stdout of the terminal.
 *
 * Some methods needed:
 * # Helper function (just like the _putchar func created)
 * # Recursion
 * # Pointer to function (when necessary)
 * # And other concept taught in C by ALX
 * 
 *
 * Return: classified as int.
 */
int _printf(const char *format, ...)
{
	va_list(str);
	va_start(str, format);
	while (*format != '\0')
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
