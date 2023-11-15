#include "main.h"


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

		cust_print_sn(done_exec, sizeof(done_exec), "%s/%s",
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
