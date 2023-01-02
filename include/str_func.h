#ifndef STR_FUNC_H
#define STR_FUNC_H

#include <stddef.h>

char *_getnbr(int nb);
int _atoi(const char *str);
int _isdigit(int c);
int _isalpha(int c);
int ft_atoi(const char *str);
char *_strdup(char *str);
char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, const char *src, size_t n);
char **_strsplit(char *str, int c);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /*STR_FUNC_H*/

