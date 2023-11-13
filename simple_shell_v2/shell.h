#ifndef SEHLL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>

#define OUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define DELIMITER " \n\t"
extern char **environ;

/* string_function 1 */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);

/* string function 2 */
int _puts(char *str);
int _putchar(int c);
int _atoi(char *s);
char* _itoa(int i);


char *_getline(void);
char **tokenizer(char *line);
void free_2D_array(char **command);
#endif 
