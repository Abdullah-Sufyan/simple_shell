#include "simple_shell.h"

/**
 * _printf - Customized printf function
 * @form: Format string
 */

void _printf(const char *form, ...)
{
	va_list args;
	va_start(args, form);

	while (*form)
	{
		if (*form == '%')
		{
			form++;

			if (*form == 'd')
			{
				int number = va_arg(args, int);
				printf("%d", number);
			}
			else if (*form == 's')
			{
				char *inputString = va_arg(args, char *);
				printf("%s", inputString);
			}
		}
		else
		{
			putchar(*form);
		}

		form++;
	}
	va_end(args);
}
