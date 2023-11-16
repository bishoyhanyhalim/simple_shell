#include "main.h"

/**
 * func_of_tok - print func tok
 * @hello: this is a char
 * @values: print the value
 *
 * Return: the value of str
*/

char *func_of_tok(char *hello, const char *values)
{

	return (strtok(hello, values));

}

/**
 * cust_from_len - print custom func strlen
 * @line_char: this is a char
 *
 * Return: the value of len
*/

int cust_from_len(const char *line_char)
{

	int line_count = 0;

	if (!line_char)
	{

		return (0);

	}
	while (line_char[line_count] != '\0')
	{

		line_count++;

	}

	return (line_count);
}


/**
 * for_help_exec - this is func for execve
 * @name_of_prog: is the name of program
 * @input_com: this is the input user
 * @argv: pointer to argmernt v
 * @env: pointer fo enviroment char
 * @count_num_erro: now it is number of error
 *
 * Return: return the value of cust ececve
 */

void for_help_exec(char *name_of_prog, char *input_com,
				 char *const argv[], char *const env[], int *count_num_erro)
{
	char *path_book = func_to_env("PATH");
	char *cp_to_path = func_cust_dup(path_book);
	char *take_tokens = func_of_tok(cp_to_path, ":");

	while (take_tokens != NULL)
	{
		char done_exec[ALL_SPASE];

		func_to_p_sn(done_exec, sizeof(done_exec), "%s/%s",
											 take_tokens, input_com);
		if (access(done_exec, X_OK) == 0)
		{
			if (execve(done_exec, argv, env) == -1)
			{
				for_print_char("%s: %d: %s: not found\n",
							  name_of_prog, (*count_num_erro), input_com);
				exit(127);
			}
		}

		take_tokens = func_of_tok(NULL, ":");
	}
	free(cp_to_path);
	free(path_book);
}


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



/**
 * on_the_term - this func to check if in interactive
 * @sizeing: the size of buffer
 * @now_on_termi: check the terminal now
 *
 * Return: return the value check terminal
 */

void on_the_term(char *sizeing, int now_on_termi)
{

	if (now_on_termi)
	{
		for_print_char("$ ");
		fflush(stdout);
	}

	if (now_on_termi)
	{
		if (line_get_ADD(sizeing, ALL_SPASE, stdin) == NULL)
		{

			exit(127);

		}
	}

	else
	{

		if (line_get_ADD(sizeing, ALL_SPASE, stdin) == NULL)
		{

			exit(0);

		}
	}
}
