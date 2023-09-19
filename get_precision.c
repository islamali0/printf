#include "main.h"

/**
 * get_precision - a function that gets the percision
 * @format: the format of the function
 * @a: the args to print
 * @list: list of arguments.
 *
 * Return: the precision (the_prec1) of the function
 */
int get_precision(const char *format, int *a, va_list list)
{
	int current_a = *a + 1;
	int the_prec1 = -1;

	if (format[current_a] != '.')
		return (the_prec1);

	the_prec1 = 0;

	for (current_a += 1; format[current_a] != '\0'; current_a++)
	{
		if (is_digit(format[current_a]))
		{
			the_prec1 *= 10;
			the_prec1 += format[current_a] - '0';
		}
		else if (format[current_a] == '*')
		{
			current_a++;
			the_prec1 = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*a = current_a - 1;

	return (the_prec1);
}
