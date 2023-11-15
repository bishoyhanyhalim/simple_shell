#include "main.h"

/**
 * cust_func_write - fun to write chars
 * @write_strings: write string
 *
 * Return: retren the value of write
 */

void cust_func_write(const char *write_strings)
{

	write(STDERR_FILENO, write_strings, cust_from_len(write_strings));

}


/**
 * write_the_int_func - helper write integers
 * @nums_int: nums of ints
 *
 * Return: the value of nums
 */

void write_the_int_func(int nums_int)
{
	char numbers_size[15];
	int look_for_negtive = 0;
	int books = 0, goes;

	if (nums_int < 0)
	{

		look_for_negtive = 1;

		nums_int = -nums_int;

	}

	do {
		numbers_size[books++] = '0' + nums_int % 10;

		nums_int /= 10;
	} while (nums_int != 0);

	if (look_for_negtive)
	{

		numbers_size[books++] = '-';

	}

	for (goes = books - 1; goes >= 0; goes--)
	{

		write(STDERR_FILENO, &numbers_size[goes], 1);

	}
}



/**
 * for_print_char - this is func to printing charcters
 * @forprinting: this is a pointing for help printing
 *
 * Return: return the value of printing
 */

int for_print_char(const char *forprinting, ...)
{
	const char *print_char = forprinting;
	va_list argment_s;

	va_start(argment_s, forprinting);

	while (*print_char != '\0')
	{
		if (*(print_char + 1) == 's' && *print_char == '%')
		{
			const char *arg_print = va_arg(argment_s, const char *);

			cust_func_write(arg_print);

			print_char = print_char + 2;
		}

		else if (*(print_char + 1) == 'd' && *print_char == '%')
		{
			int arg_print_int = va_arg(argment_s, int);

			write_the_int_func(arg_print_int);

			print_char = print_char + 2;
		}

		else
		{
			write(STDERR_FILENO, print_char, 1);

			print_char = print_char + 1;
		}
	}

	va_end(argment_s);
	return (0);
}


/**
 * help_print_env - this is fun to print rnv
 *
 * Return: retern the path of envs
 */

void help_print_env(void)
{
	int numBer = 0;
	char *newline = "\n";

	while (environ[numBer])
	{

		write(1, environ[numBer], cust_from_len(environ[numBer]));
		write(1, newline, 1);
		numBer++;

	}
}

/**
 * func_atoi_convert - custom func to convert nums
 * @works: point to string
 *
 * Return: return the finally output
 */

int func_atoi_convert(const char *works)
{
	int finally_output = 0, door = 1;

	while (*works == '\t' || *works == ' ')
	{

		works = works + 1;

	}

	if (*works == '-')
	{

		door = -1;

		works = works + 1;

	}
	else if (*works == '+')
	{

		works = works + 1;

	}

	while (*works <= '9' && *works >= '0')
	{
		finally_output = finally_output * 10 + (*works - '0');

		works = works + 1;
	}

	return (door * finally_output);
}
