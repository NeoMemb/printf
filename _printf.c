#include <stdarg.h>
#include <stdio.h>
/**
 *******/
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

			}
			else if ((*format + 1) == 'c')
			{
			}
			else if ((*format + 1) == 's')
			{
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
