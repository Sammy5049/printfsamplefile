#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - A function that Prints an unsigned number
 * @types: List a of arguments to be considered
 * @buffer: Buffer array that handles print
 * @flags:  flags to be calculated
 * @width: width to be considered
 * @precision: Precision specification
 * @size: Size to be considered
 * Return: Number of chars and print.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int counter = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[counter--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[counter--] = (number % 10) + '0';
		number /= 10;
	}

	counter++;

	return (write_unsgnd(0, counter, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal -functon that Prints an unsigned number in octal notation
 * @types: List of arguments to be considered
 * @buffer: Buffer array that handles print
 * @flags: active flags to be calculated
 * @width: width to be considered
 * @precision: Precision specification
 * @size: Size to be considered
 * Return: Number of chars and print
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int counter = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	num = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[counter--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[counter--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[counter--] = '0';

	counter++;

	return (write_unsgnd(0, counter, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - function that Prints an unsigned number in hexadecimal notation
 * @types: List of arguments to be considered
 * @buffer: Buffer array that handles print
 * @flags: flags to be calculated
 * @width: width to be considered
 * @precision: Precision specification
 * @size: Size to be considered
 * Return: Number of chars and print
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'Y', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper -function that Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments to be considered
 * @buffer: Buffer array that handles print
 * @flags:  flags to be calculated
 * @width: width to be considered
 * @precision: Precision specification
 * @size: Size to be considered
 * Return: Number of chars and print
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'Y', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - function that Prints a hexadecimal number in lower or upper
 * @types: List of arguments to be considered
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array that handle print
 * @flags:  flags to be calculated
 * @flag_ch: active flags to be considered
 * @width: width to be considered
 * @precision: Precision specification
 * @size: Size to be considered
 * @size: Size to be considered
 * Return: Number of chars and print
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int counter = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[counter--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[counter--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[counter--] = flag_ch;
		buffer[counter--] = '0';
	}

	counter++;

	return (write_unsgnd(0, counter, buffer, flags, width, precision, size));
}

