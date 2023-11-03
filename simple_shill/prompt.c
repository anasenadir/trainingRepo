#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t nread;
	FILE *stream;
	if (argc != 2)
		fprintf(stderr, "Usage: %s <fiel> \n", argv[0]), exit(EXIT_FAILURE);
	
	stream = fopen(argv[1], "r");

	while ((nread = getline(&line, &length, stream)) != -1)
	{
		printf("reatrived line of length is : %zd\n", length);
		write(STDOUT_FILENO, line, length);
	}
	return (EXIT_SUCCESS);
}
