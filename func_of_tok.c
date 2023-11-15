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
