#include "main.h"

/**
 * is_printable - A function that evaluates when char is printable
 * @c: Char to be considered
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - A function that appends ascci in hexadecimal code to buffer
 * @buffer: Array of chars to be considered
 * @i: start index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: (3)
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[ascii_code % 16];

	return (3);
}

/**
 * is_digit -A function verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - A function casts a number to the specified size
 * @num: Number to be considered for casting.
 * @size: Number indicating the type to be casted.
 *
 * Return: number casted
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
