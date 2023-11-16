#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>


#define ALL_SPASE 4000
#define TOTAL_ARG (ALL_SPASE / 2 + 1)

extern char **environ;

char *cust_for_char(const char *charing, int numing);

int for_print_char(const char *forprinting, ...);

void cust_ecec_fun(char *name_of_prog, char *input_com,
			char *const argv[], char *const env[], int *count_num_erro);

void write_the_int_func(int nums_int);

bool cust_comm_func(char *name_of_prog, char *input_com, int *count_num_erro);

void help_print_env(void);

void cust_func_exit(char *name_of_prog, int *count_num_erro,
									 char *input_com, char *arg);

int cust_from_len(const char *line_char);

char *line_get_ADD(char *numpoint, int bigs, FILE *living);

char *func_of_tok(char *hello, const char *values);

void cust_func_write(const char *write_strings);

int cust_to_cmp(const char *fristchar, const char *secondchar);

char *func_cust_dup(const char *moon);

char *func_to_env(const char *good);

char *cust_to_cyp(char *hope, const char *homes);

int func_to_p_sn(char *soon, size_t home, const char *jamp, ...);

int cust_fget_for_c(FILE *lives_far);

void for_help_exec(char *name_of_prog, char *input_com,
				 char *const argv[], char *const env[], int *count_num_erro);

void cust_comm_func_help(char *name_of_prog, char *input_com,
											 int *count_num_erro);

int func_atoi_convert(const char *str);

void on_the_term(char *sizeing, int now_on_termi);

void func_helps_pid(char *name_of_prog, int *count_num_erro,
			  char *input_com, char *const args[], char *const env[]);

void helps_sn_pri(char **food, const char **funs,
					size_t *host, int *values, va_list *args);

#endif
