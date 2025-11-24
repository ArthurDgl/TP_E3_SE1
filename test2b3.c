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
	off_t offset = 0;
	while (1) {
		char* characters = litLigneAt(fd, offset);
		if (characters == NULL) break;
		int length = strlen(characters) + 1;
		offset += length * sizeof(char);
		printf("%s\n", characters);
		free(characters);
	}
	close(fd);

	return 1;
}
