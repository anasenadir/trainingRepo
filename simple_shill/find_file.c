#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char ** argv)
{
	int i;
	struct stat state; 
	if (argc < 2)
		printf("Usage: %s path_to_file ...\n", argv[0]);

	i = 1;
	while (argv[i])
	{
		if (stat(argv[i], &state) == -1)
			printf("the file %s doesn't exists\n", argv[i]);
		else
			printf("the file %s is exists\n", argv[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
