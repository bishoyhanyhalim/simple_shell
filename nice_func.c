#include "main.h"

/**
 * cust_print_sn - this func to print the sn
 * @word: point look the char str
 * @space: this is the size
 * @sun: look for const char
 *
 * Return: return the value of printing
 */

int helping_print_sn(char *word, size_t space, const char *sun, ...)
{
    const char *ptints = sun;
    char *book = word;
    int values = 0;
    size_t saveing = space;
    va_list args;

    while (*ptints != '\0' && saveing > 1)
    {
        if (*ptints == '%' && *(ptints + 1) == 's')
        {
            char *arg = va_arg(args, char *);
            size_t arg_len = cust_from_len(arg);

            if (arg_len < saveing - 1)
            {
                cust_to_cyp(book, arg);
                book += arg_len;
                saveing -= arg_len;
                values += arg_len;
            }
            else
            {
                break;
            }

            ptints += 2;
        }
        else
        {
            *book = *ptints;
            book++;
            ptints++;
            saveing--;
            values++;
        }
    }
}

/**
 * cust_print_sn - this func to print the sn
 * @word: point look the char str
 * @space: this is the size
 * @sun: look for const char
 *
 * Return: return the value of printing
 */

int cust_print_sn(char *word, size_t space, const char *sun, ...)
{
    char *book = word;
    int values = 0;
    size_t saveing = space;
    va_list args;

    va_start(args, sun);

    if (word == NULL || sun == NULL || space == 0)
    {
        return (-1);
    }

helping_print_sn(word, space, sun);

    va_end(args);

    if (saveing > 0)
    {
        *book = '\0';
    }
    else
    {
        return (-1);
    }
    return (values);
}
