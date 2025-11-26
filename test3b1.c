#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "gestionFichiers.h"

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Not enough arguments !\n");
		return 0;
	}

	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);

	while (1) {
		char* characters = litLigne(fd1);
		if (characters == NULL) break;
		//printf("Appending : %s\n", characters);
		ecritChaine(fd2, characters);
		free(characters);
	}
	close(fd1);
	close(fd2);

	return 1;
}
