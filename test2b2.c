#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "gestionFichiers.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Not enough arguments !\n");
		return 0;
	}

	int fd = open(argv[1], O_RDONLY);
	char* characters = litLigne(fd);
	printf("%s\n", characters);
	close(fd);
	free(characters);

	return 1;
}
