#include "main.h"

/**
 * helps_sn_pri - this help func to print the sn
 * @food: point look the char str
 * @funs: this is the size
 * @host: this is the host
 * @goes:it is the goess
 * @args: it is args
 *
 * Return: return the value of printing
 */

void helps_sn_pri(char **food, const char **funs,
					size_t *host, int *goes, va_list *args)
{

	while (**funs != '\0' && *host > 1)
	{

		if (**funs == '%' && *(*funs + 1) == 's')
		{

			char *arg = va_arg(*args, char *);
			size_t arg_len = cust_from_len(arg);

			if (arg_len < *host - 1)
			{
				cust_to_cyp(*food, arg);

				*food += arg_len;
				*host -= arg_len;
				*goes += arg_len;

			}
			else
			{
				break;
			}

			*funs += 2;

		}
		else
		{
			*(*food) = **funs;
			(*food)++;
			(*funs)++;
			(*host)--;
			(*goes)++;
		}
	}
}

/**
 * func_to_p_sn - this func to print the sn
 * @soon: point look the char str
 * @home: this is the size
 * @jamp: look for const char
 *
 * Return: return the value of printing
 */

int func_to_p_sn(char *soon, size_t home, const char *jamp, ...)
{
	int goes = 0;
	char *food = soon;
	const char *funs = jamp;
	size_t host = home;
	va_list args;

	va_start(args, jamp);


	if (soon == NULL || jamp == NULL || home == 0)
	{

		return (-1);

	}


	helps_sn_pri(&food, &funs, &host, &goes, &args);

	va_end(args);

	if (host > 0)
	{

		*food = '\0';

	}
	else
	{

		return (-1);

	}

	return (goes);
}
