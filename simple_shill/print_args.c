#include <stdio.h>

int main(int argc, char **argv)
{
	int index = 0;

	while (argv[index])
		printf("%s\n", argv[index]), index++;
}
