#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer -function that Prints the value of a pointer variable
 * @types: List a of arguments to be considered
 * @buffer: Buffer array that handle print
 * @flags:  flags to be considered
 * @width:  width to be considered
 * @precision: Precision specification
 * @size: Size to be considered
 * Return: Number of chars and print.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char additional_c = 0, padding = ' ';
	int counter = BUFF_SIZE - 2, length = 2, padding_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[counter--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		additional_c = '+', length++;
	else if (flags & F_SPACE)
		additional_c = ' ', length++;

	counter++;

	return (write_pointer(buffer, counter, length,
		width, flags, padding, additional_c, padding_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - function Prints ascii codes in hexa of non printable chars
 * @types: List of arguments to be considered
 * @buffer: Buffer array that handle print
 * @flags:  flags to be coonsidered
 * @width:  width to be considered
 * @precision: Precision specification
 * @size: Size to be considered
 * Return: Number of chars and print
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int counter = 0, offset = 0;
	char *string = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[counter] != '\0')
	{
		if (is_printable(string[counter]))
			buffer[counter + offset] = string[counter];
		else
			offset += append_hexa_code(string[counter], buffer, counter + offset);

		counter++;
	}

	buffer[counter + offset] = '\0';

	return (write(1, buffer, counter + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse -A function Prints reverse string.
 * @types: List of arguments to be considered
 * @buffer: Buffer array that handle print
 * @flags:  flags to be considered
 * @width: width to be considered
 * @precision: Precision specification
 * @size: Size considered
 * Return: Numbers of chars and print
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *string;
	int counter, total_count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(types, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null(";
	}
	for (i = counter; string[counter]; counter++)
		;

	for (counter = counter - 1; counter >= 0; counter--)
	{
		char z = string[counter];

		write(1, &z, 1);
		total_count++;
	}
	return (total_count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - A function that Print a string in rot13.
 * @types: List of arguments to considered
 * @buffer: Buffer array thatt handle print
 * @flags:  flags to be considered
 * @width:  width to be considered
 * @precision: Precision specification
 * @size: Size to be considered
 * Return: Numbers of chars and print
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char y;
	char *string;
	unsigned int row_i, column_j;
	int total_count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (row_i = 0; str[row_i]; row_i++)
	{
		for (column_j = 0; in[column_j]; column_j++)
		{
			if (in[column_j] == str[row_i])
			{
				y = out[column_j];
				write(1, &y, 1);
				total_count++;
				break;
			}
		}
		if (!in[column_j])
		{
			x = str[row_i];
			write(1, &y, 1);
			total_count++;
		}
	}
	return (total_count);
}

