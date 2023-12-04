#include <stdio.h>
#include <stdarg.h>
#include <main.h>

/**
 * _printf - function that produce output according to format
 * return: int
 *
 */
int _printf (const char *format, ...)
{
	va_list num;
	var_start (num, format);
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					char c =(char)va_arg(num, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					const char *str = va_arg(num, const char*);
					int len = 0;
					while (str[len] != '\0')
						len++;
					write(1, str, len);
					count += len;

					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					break:
			}
		}
		else
			write(1, format, 1);
			count++;
		format++;

	}
	va_end (args);
	return count;
}
