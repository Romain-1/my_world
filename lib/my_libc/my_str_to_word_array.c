/*
** EPITECH PROJECT, 2020
** my_libc
** File description:
** my_str_to_word_array (transform a string into a word array)
*/

#include <stdbool.h>
#include <stdlib.h>

static bool is_separating_char(char c, char const *separating_chars)
{
    for (unsigned int index = 0; separating_chars[index] != '\0'; index++)
        if (separating_chars[index] == c)
            return (true);
    return (false);
}

static unsigned int find_next_word(
    char const *string, char const *separating_chars)
{
    unsigned int counter = 0;

    for (; string[counter] != '\0'; counter++)
        if (is_separating_char(string[counter], separating_chars) == true)
            break;
    if (string[counter] == '\0')
        counter -= 1;
    return (counter);
}

static char *copy_str(char const *string, char const *separating_chars)
{
    char *new_string = NULL;
    unsigned int index = 0;

    for (; string[index] != '\0'; index++)
        if (is_separating_char(string[index], separating_chars) == true)
            break;
    new_string = malloc(sizeof(char) * (index + 1));
    if (new_string == NULL)
        return (NULL);
    for (index = 0; string[index] != '\0'; index++) {
        if (is_separating_char(string[index], separating_chars) == true)
            break;
        new_string[index] = string[index];
    }
    new_string[index] = '\0';
    return (new_string);
}

static char **alloc_word_array(char const *string, char const *separating_chars)
{
    char **word_array = NULL;
    unsigned int nb_words = 0;
    unsigned int index = 0;

    for (; string[index] != '\0'; index++) {
        if (is_separating_char(string[index], separating_chars) == false) {
            index += find_next_word(&string[index], separating_chars);
            nb_words += 1;
        }
    }
    if (nb_words == 0)
        return (NULL);
    word_array = malloc(sizeof(char *) * (nb_words + 1));
    if (word_array == NULL)
        return (NULL);
    word_array[nb_words] = NULL;
    return (word_array);
}

char **my_str_to_word_array(char const *string, char const *separating_chars)
{
    char **word_array = NULL;
    unsigned int curr_word = 0;
    unsigned int index = 0;

    if (string == NULL || separating_chars == NULL)
        return (NULL);
    for (; string[index] != '\0'; index++)
        if (is_separating_char(string[index], separating_chars) == false)
            break;
    word_array = alloc_word_array(&string[index], separating_chars);
    for (; word_array && string[index] != '\0'; index++)
        if (is_separating_char(string[index], separating_chars) == false) {
            word_array[curr_word] = copy_str(&string[index], separating_chars);
            index += find_next_word(&string[index], separating_chars);
            if (word_array[curr_word] == NULL)
                return (NULL);
            curr_word += 1;
        }
    return (word_array);
}
