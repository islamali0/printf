#include "main.h"

/**
 * get_size - Calculates the size of the argument
 * @format: Formatted string to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int current_a = *i + 1;
	int size = 0;

	if (format[current_a] == 'l')
		size = S_LONG;
	else if (format[current_a] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current_a - 1;
	else
		*i = current_a;

	return (size);
}
