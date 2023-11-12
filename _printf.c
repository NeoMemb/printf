#include <stdarg.h>
#include <stdio.h>

/**
 * printChar - helper helper that prints chars
 * @chars: the char to be printed
 * Return the char to be printed
 */
int printChar(char chars)
{
	return (write(1, &chars, 1));
}

/**
 * printStr - another helper func that prints string
 * @str: pointer to char(A.KA string) to be printed
 * Return: count
 */
int printStr(char *str)
{
	int count;

	for (count = 0; str[count] != '\0'; count++)
	{
		printChar((int)*str);
	}
	return (count);
}

/**
 * printDigit - print digits either hex or decimal
 * @N: long data type and the index for string chars
 * @baseNUMB: number base
 * Return: count
 */
int printDigit(long N, int baseNUMB)
{
	char *chars;
	int count;

	count = 0;
	chars = "0123456789abcdef";
	if (N < 0)
	{
		write (1, "-", 1);
		return (printDigit(-N, baseNUMB) + 1);
	}
	else if(N < baseNUMB)
	{
		return (printChar(chars[N]));
	}
	else
	{
		count += printDigit(N/baseNUMB, baseNUMB);
		return (count + printDigit(N % baseNUMB, baseNUMB));
	}
}

/**
 * format_print - Creating a function that uses helper function to handle s, c, d or i and x
 * @spec: char immediately after '%'
 * Return: int i
 */
int format_print(char spec, va_list str)
{
	int i, DECIMAL, HEX;

	i = 0;
	HEX = 16;
	DECIMAL = 10;
	if (spec == 'c')
	{
		i += printChar(va_arg(str, int));
	}
	else if (spec == 's')
	{
		i += printStr(va_arg(str, char*));
	}
	else if (spec == 'd' || spec == 'i')
	{
		i += printDigit(long va_arg(str, unsigned int), DECIMAL);
	}
	else if (spec == 'x')
	{
		i += printDigit(long va_arg(str, unsigned int), HEX);
	}
	else
	{
		i+= (write(1, &spec, 1));
	}
	return (i);
}

/**
 * _printf- pring strings either formatted or not
 * @format: pointer to char (string) to be printed to the stdio
 * Description: we iterated over an infinite number of char.
 * If % is found and we use the format_print() created above to format it
 * . It will have to map it to the variable (str A.K.A ...) passed to it after the %.
 * and then printf, sorry, print it to the stdout of the terminal.
 *
 * Some methods needed:
 * # Helper function (just like the format_print() func created)
 * # Recursion
 * # Pointer to function (when necessary)
 * # And other concept taught in C by ALX
 * 
 *
 * Return: classified as int.
 */
int _printf(const char *format, ...)
{
	int numb;

	numb = 0;
	va_list(str);
	va_start(str, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			numb += format_print(*(format + 1), str);
		}
		else
		{
			numb += write(1, format, 1);
			format++;
		}
	}
	va_end(str);
}
