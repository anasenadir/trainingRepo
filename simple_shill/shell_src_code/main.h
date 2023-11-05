#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_BUF_SIZE 1024
typedef struct linked_paths_list {
    char *data;
    struct linked_paths_list *next;
} linked_paths;

int _strlen(char *str);
char **_splited_line(char *line);
char *_getenv(const char *name);
linked_paths *generate_linked_paths_list(void);
int _setenv(const char *name, const char *value, int overwrite);;
#endif
