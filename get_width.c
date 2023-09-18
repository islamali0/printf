#include "main.h"

/**
 * get_width - the width for printing
 * @format: Formatted string to print the arguments.
 * @a: List of printed arguments
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *a, va_list list)
{
	int current_a;
	int width = 0;

	for (current_a = *a + 1; format[current_a] != '\0'; current_a++)
	{
		if (is_digit(format[current_a]))
		{
			width *= 10;
			width += format[curent_a] - '0';
		}
		else if (format[current_a] == '*')
		{
			current_a++
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*a = current_a - 1;
	return (width);
}
