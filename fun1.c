#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @the_buff: Buffer array to handle print
 * @the_flag:  Calculates active flags
 * @width: get width
 * @the_prec1: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char the_buff[],
	int the_flag, int width, int the_prec1, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		the_buff[a--] = (number % 10) + '0';
		number /= 10;
	}

	a++;

	return (write_unsgnd(0, i, the_buff, the_flag, width, the_prec1, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @the_buff: Buffer array to handle print
 * @the_flag:  Calculates active flags
 * @width: get width
 * @the_prec1: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char the_buff[],
	int the_flag, int width, int the_prec1, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		the_buff[a--] = '0';

	the_buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		the_buff[a--] = (number % 8) + '0';
		number /= 8;
	}

	if (the_flag & F_HASH && init_number != 0)
		the_buff[a--] = '0';

	a++;

	return (write_unsgnd(0, a, the_buff, the_flag, width, the_prec1, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @the_buff: Buffer array to handle print
 * @the_flag:  Calculates active flags
 * @width: get width
 * @the_prec1: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char the_buff[],
	int the_flag, int width, int the_prec1, int size)
{
	return (print_hexa(types, "0123456789abcdef", the_buff,
		the_flag, 'x', width, the_prec1, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @the_buff: Buffer array to handle print
 * @the_flag:  Calculates active flags
 * @width: get width
 * @the_prec1: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char the_buff[],
	int the_flag, int width, int the_prec1, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", the_buff,
		the_flag, 'X', width, the_prec1, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @the_buff: Buffer array to handle print
 * @the_flag:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @the_prec1: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char the_buff[],
	int the_flag, char flag_ch, int width, int the_prec1, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		the_buff[i--] = '0';

	the_buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		the_buff[i--] = map_to[number % 16];
		number /= 16;
	}

	if (the_flag & F_HASH && init_number != 0)
	{
		the_buff[a--] = flag_ch;
		the_buff[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, i, the_buff, the_flag, width, the_prec1, size));
}
