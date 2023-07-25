#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int current_counter = *i + 1;
	int precision = -1;

	if (format[current_counter] != '.')
		return (precision);

	precision = 0;

	for (current_counter += 1; format[current_counter] != '\0'; current_counter++)
	{
		if (is_digit(format[current_counter]))
		{
			precision *= 10;
			precision += format[current_counter] - '0';
		}
		else if (format[current_counter] == '*')
		{
			current_counter++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current_counter - 1;

	return (precision);
}

