#include "main.h"


/**
 * cust_ecec_fun - this is func for execve
 * @name_of_prog: is the name of program
 * @input_com: this is the input user
 * @argv: pointer to argmernt v
 * @env: pointer fo enviroment char
 * @count_num_erro: now it is number of error
 *
 * Return: return the value of cust ececve
 */

void cust_ecec_fun(char *name_of_prog, char *input_com,
			char *const argv[], char *const env[], int *count_num_erro)
{
	if (cust_for_char(input_com, '/') != NULL)
	{
		if (execve(input_com, argv, env) == -1)
		{
			for_print_char("%s: %d: %s: not found\n",
						  name_of_prog, (*count_num_erro), input_com);
			exit(127);
		}
	}
	else
	{
		char *path_book = func_to_env("PATH");
		char *cp_to_path = func_cust_dup(path_book);

		if (cp_to_path == NULL)
		{
			for_print_char("%s: %d: %s: not found\n",
						  name_of_prog, (*count_num_erro), input_com);
			exit(127);
		}

		if (path_book == NULL)
		{
			for_print_char("%s: %d: %s: not found\n",
						  name_of_prog, (*count_num_erro), input_com);
			exit(127);
		}
		for_help_exec(name_of_prog, input_com,
					argv, env, count_num_erro);

		for_print_char("%s: %d: %s: not found\n",
						 name_of_prog, (*count_num_erro), input_com);

		free(cp_to_path);
		free(path_book);
		exit(127);
	}
}
