#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *f;
	int i;
	int c;

	i = 1;
	while (i <argc)
	{
		f = fopen(argv[i], "r");
		if (!f)
		{
			perror(argv[i]);
			exit(1);
		}
		while ((c = fgetc(f)) != EOF)
		{
			if (putchar(c) < 0)
				exit(1);
		}
		fclose(f);
		i++;
	}
	exit(0);
}