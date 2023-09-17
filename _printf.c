#include "main.h"
/**
  * _printf - a function that prints anything
  * @format: the format and it's the character string
  * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int acp = 0;/*a character to print*/
	va_list the_list_of_arg;

	if (format == NULL)
		return (-1);

	va_start(the_list_of_arg, format);

	while (*format)
		if (*format != '%')/*if formst is not %*/
			write(1, format, 1);/*write the caracter*/
			acp++;
		else/*if format is %*/
			format++;/* check the next character*/
			if (*format == '\0')
				break;
			if (*format == '%')/*print the %*/
				write(1, format, 1);
				acp++;
			else if (*format == 'c')/*format is c*/
				char c = va_arg(the_list_of_arg, int);

				write(1, &c, 1);
				acp++;
			else if (*format == 's')/*format is string*/
				char *str = va_arg(the_list_of_arg, char*);
				int string_length = 0;

				while (str[string_length] != '\0')/*calc  the length*/
					string_length++;
				write(1, str, string_length);/*print the string*/
				acp += string_length;
		format++;
	va_end(the_list_of_string);
	return (acp);
}

