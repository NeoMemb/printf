#include "main.h"

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
	while (*format != '\0')
	{
		if ((*(format) == '%') && (*(format) + 1))
		{
			count += format_print(*(++format), ap);
		}
		/**
		 * else if (format == NULL)
		 * {
		 *	return (-1);
		 * }
		 */
		else if (*(format) && *(format + 1))
		{
			count += write(1, format, 1);
		}
		else
		{
			count += write(1, format, 1);
		}
		++format;
	}
	va_end(ap);
	return (count);
}
