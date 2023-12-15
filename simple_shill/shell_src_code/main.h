#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define MAX_BUF_SIZE 1024

extern char **environ;


typedef struct linked_paths_list {
    char *data;
    struct linked_paths_list *next;
} linked_paths;


// str_lib module
int _strlen(char *str);
char **_splited_line(char *line);
int _str_exist(char *src, char ch);
char *_itoc(int num);


char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);;




// path_linked_list module
linked_paths *generate_linked_paths_list(void);


// lib module
void free2DArrays(char **array);
void freeLinkedList(linked_paths *head);
void _perror(char *command, int index);

void execute(char **command, linked_paths *paths_head, int index);
#endif
