#include "main.h"


/**
 * cust_comm_func_help - this is function to helping command
 * @name_of_prog: is the name of program
 * @input_com: this is the input user
 * @count_num_erro: now it is number of error
 *
 * Return: return the value of user commands
 */

void cust_comm_func_help(char *name_of_prog, char *input_com,
							 int *count_num_erro)
{
		char *path_book = func_to_env("PATH");
		char *cp_to_path = func_cust_dup(path_book);


		if (path_book == NULL)
		{
			for_print_char("%s: %d: %s: not found\n",
						 name_of_prog, (*count_num_erro), input_com);

			exit(127);
		}

		if (cp_to_path == NULL)
		{
			for_print_char("%s: %d: %s: not found\n",
						 name_of_prog, (*count_num_erro), input_com);

			exit(127);
		}

	free(cp_to_path);
	free(path_book);
}

/**
 * cust_comm_func - this is function to command
 * @name_of_prog: is the name of program
 * @input_com: this is the input user
 * @count_num_erro: now it is number of error
 *
 * Return: return the value of user commands
 */

bool cust_comm_func(char *name_of_prog, char *input_com, int *count_num_erro)
{
	int num;
	char *making[] = {"exit", "env"};

	for (num = 0; num < (int)sizeof(making) / (int)sizeof(making[0]); num++)
	{
		if (cust_to_cmp(input_com, making[num]) == 0)
		{
			return (true); }
	}
	if (cust_for_char(input_com, '/') != NULL)
	{
		return (access(input_com, X_OK) == 0);
	}
	else
	{
		char *path_book = func_to_env("PATH");
		char *cp_to_path = func_cust_dup(path_book);
		char *take_tokens = func_of_tok(cp_to_path, ":");

		cust_comm_func_help(name_of_prog, input_com, count_num_erro);

		while (take_tokens != NULL)
		{
			char done_exec[ALL_SPASE];

			func_to_p_sn(done_exec, sizeof(done_exec), "%s/%s",
							 take_tokens, input_com);
			if (access(done_exec, X_OK) == 0)
			{
				free(cp_to_path);
				free(path_book);
				return (true); }
			take_tokens = func_of_tok(NULL, ":");
		}
		free(cp_to_path);
		free(path_book);
		return (false);
	}
}
