#include "monty.h"

extern char **file_data;


void readfile(int file_d)
{
    char buffer_line[MAX_LINE_SIZE], *tmp;
    int byte_reads, i = 0, line_number = 0, SIZE = 50;

    file_data = malloc(sizeof(char *) * SIZE + 1);
    if (!file_data)
        return;
    
    while ((byte_reads = read(file_d, &buffer_line[i], 1)) > 0)
    {
        if (buffer_line[i] == '\n')
        {
            buffer_line[i]  = '\0';
            tmp = malloc(strlen(buffer_line) * sizeof(char));
            if (!tmp)
                return;
            strcpy(tmp, buffer_line);

            if (SIZE < line_number)
            {
                file_data = _realloc(file_data, SIZE, SIZE * 2);
                SIZE *= 2;
                file_data[line_number] = tmp;
            }

            file_data[line_number] = tmp;
            i = 0;
            line_number++;
            continue;
        }
        i++;
    }
    file_data[line_number] = NULL;
}
