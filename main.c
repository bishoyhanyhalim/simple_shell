#include "main.h"

/**
 * main - the hero of the code
 * @env: printing env
 * @argc: get the argc
 * @argv: get the argv
 *
 * Return: return the value
 */

int main(int argc, char **argv, char **env)
{
	int count_num_erro = 1, now_on_termi = isatty(STDIN_FILENO);
	char line_sizeing[ALL_SPASE], *take_tokens;
	(void)argc;

	while (1)
	{
		char *args[TOTAL_ARG];
		int nice = 0;

		on_the_term(line_sizeing, now_on_termi);
		take_tokens = func_of_tok(line_sizeing, " ");
		while (take_tokens != NULL && nice < TOTAL_ARG - 1)
		{
			args[nice] = take_tokens;
			take_tokens = func_of_tok(NULL, " ");
			nice++; }
		args[nice] = NULL;
		if (nice == 0)
		{
			continue; }
		if (!cust_comm_func(argv[0], args[0], &count_num_erro))
		{
			for_print_char("%s: %d: %s: not found\n", argv[0], count_num_erro, args[0]);
			count_num_erro++;
			continue; }
		if (cust_to_cmp(args[0], "exit") == 0)
		{
			if (nice > 1)
			{
				cust_func_exit(argv[0], &count_num_erro, args[0], args[1]);
			} else
			{
				exit(0); } }
		else if (cust_to_cmp(args[0], "env") == 0)
		{
			help_print_env();
			continue; }
		func_helps_pid(argv[0], &count_num_erro, args[0], args, env);
		count_num_erro++; }
	return (0); }
