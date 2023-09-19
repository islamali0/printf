#include "main.h"

/**
 * get_flags - findout the flags of the num in the fun
 * @format: the format of the function
 * @a: parameter
 * Return: the flags of the function
 */
int get_flags(const char *format, int *a)
{
	int b, current_a;
	int flag = 0;
	const char flag_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_ar[] = {minus, plus, zero, hash, space, 0};

	for (current_a = *a + 1; format[current_a] != '\0'; current_a++)
	{
		for (b = 0; flag_ch[b] != '\0'; b++)
			if (format[current_a] == flag_ch[b])
			{
				flag |= flag_ar[b];
				break;
			}

		if (flag_ch[b] == 0)
			break;
	}

	*a = current_a - 1;

	return (flag);
}

