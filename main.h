#ifndef PRINT_F
#define PRINT_F
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int _printf(const char *format, ...);
int printStr(char *s);
int printDigit(long N, int baseNumb);
int printChar(int c);
int format_print(char spec, va_list ap);
int printHex(long N, int baseNumb);
#endif
