#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "gestionFichiers.h"

int main() {
	int fd = open("data/fichierTest.txt", O_RDONLY);
	char* characters = litLigne(fd);
	printf("%s\n", characters);
	close(fd);
	free(characters);
}
