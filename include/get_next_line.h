/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** includes and macros
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef READ_SIZE
#define READ_SIZE 500
#endif

char *get_next_line(int);
#endif
