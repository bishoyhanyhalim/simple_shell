#include "main.h"

/**
 * cust_fget_for_c - this this func to use fger_c
 * @lives_far: this is a file point
 *
 * Return: return the value of fget
 */

int cust_fget_for_c(FILE *lives_far)
{
	char chars_fget;
	ssize_t bytesRead = read(STDIN_FILENO, &chars_fget, 1);

	if (lives_far == NULL)
	{

		return (EOF);

	}

	if (bytesRead == 1)
	{

		return ((unsigned char)chars_fget);

	}

	else
	{

		return (EOF);

	}
}


/**
 * cust_for_char - addition func for char
 * @charing: this is a pointer for char
 * @numing: it is a number
 *
 * Return: return value null or char
 */

char *cust_for_char(const char *charing, int numing)
{

	while (*charing != numing && *charing != '\0')
	{
		charing++;
	}

	if (*charing == numing)
	{
		return ((char *)charing);
	}

	else
	{
		return (NULL);
	}
}


/**
 * cust_to_cmp - my func to make cust cmp
 * @fristchar: this is a poiter to number one
 * @secondchar: pointer to number two
 *
 * Return: returns the value of char
 */

int cust_to_cmp(const char *fristchar, const char *secondchar)
{

	while ((*fristchar == *secondchar) && *fristchar)
	{

		fristchar++;

		secondchar++;

	}

	return (*(unsigned char *)fristchar - *(unsigned char *)secondchar);
}


/**
 * func_to_env - this the getenv addition func
 * @good: the name of the env
 *
 * Return: return the env output
 */

char *func_to_env(const char *good)
{

	char **strs_env;

	if (environ == NULL || good == NULL)
	{

		return (NULL);

	}

	for (strs_env = environ; *strs_env != NULL; ++strs_env)
	{

		size_t bh;

		for (bh = 0; good[bh] != '\0' && (*strs_env)[bh] == good[bh]; ++bh)
		{
		}

		if (good[bh] == '\0' && (*strs_env)[bh] == '=')
		{

			return (func_cust_dup(*strs_env + bh + 1));

		}
	}

	return (NULL);
}



/**
 * func_cust_dup - this is the cust func dup
 * @moon: look for char
 *
 * Return: return the value of dup
 */

char *func_cust_dup(const char *moon)
{
	size_t lines_size = cust_from_len(moon);
	size_t NUMber;
	char *mallo_char = (char *)malloc(lines_size + 1);

	if (moon == NULL)
	{

		return (NULL);

	}

	if (mallo_char != NULL)
	{

		for (NUMber = 0; NUMber <= lines_size; ++NUMber)
		{

			mallo_char[NUMber] = moon[NUMber];

		}
	}

	return (mallo_char);
}
