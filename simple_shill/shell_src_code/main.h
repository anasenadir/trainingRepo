#ifndef MAIN_H
#define MAIN_H

typedef struct linked_paths_list {
    char *data;
    struct linked_paths_list *next;
} linked_paths;

int _strlen(char *str);
char *_getenv(const char *name);
linked_paths *generate_linked_paths_list(void);
int _setenv(const char *name, const char *value, int overwrite);;
#endif
