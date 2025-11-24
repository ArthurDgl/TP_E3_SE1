#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "gestionFichiers.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Not enough arguments !\n");
		return 0;
	}

	int fd = open(argv[1], O_RDONLY);

	int lines = 0;
	while (1) {
		char* characters = litLigne(fd);
		if (characters == NULL) break;
		free(characters);
		lines++;
	}
	close(fd);

	printf("File has %d lines.\n", lines);

	return 1;
}
