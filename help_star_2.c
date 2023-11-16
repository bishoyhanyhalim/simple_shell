#include "main.h"


/**
 * line_get_ADD - this is a func for add getlines
 * @numpoint: this is a pointer num
 * @bigs: this is a pointer big
 * @living: this is a size pointer
 *
 * Return: return value of num
 */

char *line_get_ADD(char *numpoint, int bigs, FILE *living)
{
	size_t numss;

	if (numpoint == NULL || living == NULL || bigs <= 0)
	{
		return (NULL);
	}

	for (numss = 0; numss < (size_t)(bigs - 1); ++numss)
	{
		int find = cust_fget_for_c(living);

		if (find == EOF)
		{
			if ((living) || numss == 0)
			{
				return (NULL);
			}

			else
			{
				break;
			}
		}

		numpoint[numss] = (char)find;

		if (numpoint[numss] == '\n')
		{
			break;
		}
	}

	numpoint[numss] = '\0';

	return (numpoint);
}


/**
 * cust_to_cyp - cust func to use cyp
 * @hope: char point
 * @homes: const char pointer
 *
 * Return: return the value of cyp
 */

char *cust_to_cyp(char *hope, const char *homes)
{

	char *find_cpy = hope;


	if (homes == NULL || hope == NULL)
	{

		return (NULL);

	}


	while ((*hope++ = *homes++) != '\0')
	{
	}

	return (find_cpy);
}


/**
 * cust_func_exit - func fot exit the program whit status
 * @name_of_prog: the name for program runing
 * @count_num_erro: point to error count num
 * @input_com: the user input commands
 * @arg: commands arg
 *
 * Return: return the status value for exit
 */

void cust_func_exit(char *name_of_prog, int *count_num_erro,
									 char *input_com, char *arg)
{

	int status_out_prog = func_atoi_convert(arg);

	if (status_out_prog < 0)
	{

		for_print_char("%s: %d: %s: Illegal number: %d\n",
				name_of_prog, *count_num_erro, input_com, status_out_prog);

		exit(2);

	}

	else
	{

		exit(status_out_prog);

	}

}

/**
 * func_helps_pid - helping func pid
 * @name_of_prog: this is the prog names
 * @count_num_erro: error numbers
 * @input_com: user input
 * @args: args
 * @env: look env now
 *
 * Return: return the value to help pid
 */

void func_helps_pid(char *name_of_prog, int *count_num_erro,
			  char *input_com, char *const args[], char *const env[])
{
	pid_t pid;
	int house;

	pid = fork();

	if (pid < 0)
	{

		for_print_char("%s: %d: %s: not found\n",
								 name_of_prog, *count_num_erro, input_com);

		exit(2);

	}
	else if (pid == 0)
	{

		cust_ecec_fun(name_of_prog, input_com, args, env, count_num_erro);

	}
	else
	{

		waitpid(pid, &house, 0);

		count_num_erro++;

	}
}
