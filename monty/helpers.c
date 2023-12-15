#include "monty.h" 

extern char **file_data;

void (*get_right_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
    int index;
    instruction_t insractions[] = {
        {"pall", pall},
        {"push", push},
        {"pop", pop},
        {"pint", pint},
        {NULL, NULL}
    };

    index = 0;
    while (insractions[index].opcode)
    {
        if (strcmp(insractions[index].opcode, opcode) == 0)
        {
            return (insractions[index].f);
        }
        index++;
    }
    return (NULL);
}


char **get_file_cpy()
{
    int num_of_lines = 0, index = 0;
    char **file_cpy, *tmp;

    while (file_data[num_of_lines++])
        num_of_lines ++;

    file_cpy = malloc(sizeof(char *) * num_of_lines);

    while (file_data[index])
    {
        tmp = malloc(strlen(file_data[index]));
        if (!tmp)
            return (NULL);
        
        strcpy(tmp, file_data[index]);

        file_cpy[index] = tmp;
        index ++;
    }

    file_cpy[index] = NULL;
    // for (int i = 0; file_cpy[i] != NULL; i++) {
    //     printf("%s\n", file_cpy[i]);
    // }
    return (file_cpy);
}


/**
* _realloc - reallocates a memory block
* @ptr: pointer to the memory previously allocated with a call to malloc
* @old_size: size of ptr
* @new_size: size of the new memory to be allocated
*
* Return: pointer to the address of the new memory block
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int i;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
		return (ptr);

	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)temp_block + i) = *((char *) ptr + i);
			free(ptr);
			return (temp_block);
		}
		else
			return (NULL);
	}
}


void resolve(stack_t **op_stack)
{
    char *line, *opcode, *data;
    int line_number = 0;
    instruction_t *in;
    char **file_copy = get_file_cpy();

    if (!file_data)
        return;

    while (line = file_copy[line_number])
    {
        in = malloc(sizeof(instruction_t));
        if (!in)
            return;

        opcode = strtok(line, " \t");
        data = strtok(NULL, " \t");

        if (opcode)
        {
            in->f = get_right_func(opcode);
            if (in->f)
                in->f(op_stack, line_number);
        }

        line_number ++;
        free(in);
        in = NULL;
    }
}
