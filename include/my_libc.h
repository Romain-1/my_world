/*
** EPITECH PROJECT, 2020
** my_libc
** File description:
** my_libc_h
*/

#ifndef _MY_LIBC_H_
#define _MY_LIBC_H_

#define IS_NB(c) ((c >= '0' && c <= '9') ? (1) : (0))

char *my_int_to_array(int);
int my_strcmp(char const *, char const *);
int my_atoi(char const *);
int my_strlen(char const *);
float my_atof(char const *);
char **my_str_to_word_array(char const *, char const *);
char *my_strdup(char const *);
char *my_strcat(char const *, char const *);
void my_putnbr(int, int);
void my_putfloat(int, float);
void my_puts(int, char const *);

#endif /* _MY_LIBC_H_ */
