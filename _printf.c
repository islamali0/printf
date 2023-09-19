#include "main.h"

void print_buf(char buffer[], int *buff_ind);

/**
 * _printf - a function to print
 * @format: the format of the function
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int a, print = 0, printed_character = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char the_buf[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			the_buf[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buf(the_buf, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_character++;
		}
		else
		{
			print_buf(the_buf, &buff_ind);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			size = get_size(format, &a);
			++a;
			print = handle_print(format, &a, list, the_buf,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			printed_character += print;
		}
	}

	print_buf(the_buf, &buff_ind);

	va_end(list);

	return (printed_character);
}

/**
 * print_buf - a function that prints the contents of the buffer
 * @buffer: an array
 * @buff_ind: an index to add next character and represents the length.
 */
void print_buf(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
