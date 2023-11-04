#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int _strlen(char *str)
{
	int len = 0;

	if (!str || str == "")
		return (0);

	while (str[len] != '\0')
		len++;
	return (len);
}
linked_paths * generate_linked_paths_list(void)
{
	char *PATH = getenv("PATH");
	char *data;
	linked_paths *head = NULL, *new_node = NULL, *prev_node = NULL;

	data = strtok(PATH, ":");
	
	head = malloc (sizeof(linked_paths));

	if (!head)
	{
		fprintf(stderr, "memory allocation failed (head)");
	}

	head->data = malloc(sizeof(char) * _strlen(data) + 1);
	if (!head->data)
	{
		fprintf(stderr, "memory allocation failed(data)");
		free(head);
		exit(EXIT_FAILURE);
	}
	
	strcpy(head->data, data);
	head->next = NULL;
	
	prev_node = head; 
	
	while (data = strtok(NULL, ":"))
	{
		new_node = malloc(sizeof(linked_paths));
		if (!new_node)
		{
			fprintf(stderr, "memory allocation failed (new_node)");
			free(head);
			exit(EXIT_FAILURE);
		}
		
		new_node->data = malloc(sizeof(char) * _strlen(data));

		if (!new_node->data)
		{
			fprintf(stdout, "memory allocation failed (new_node->data)");
			free(new_node);
			free(head);
			exit(EXIT_FAILURE);
		}
		strcpy(new_node->data, data);
		new_node->next = NULL;
		prev_node->next = new_node;
		prev_node = new_node;
	}
	return (head);
}
