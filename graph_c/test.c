#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
	char line[30];
	FILE *fd;

	fd = fopen("scc_short.txt", O_RDONLY);
	fgets(line, 29, fd);
	printf("salut");
	printf("-%s-", line);
}