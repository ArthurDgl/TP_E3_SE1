#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gestionFichiers.h"
#include "constants.h"

char* litDixCaracteres(int fd) {
	char* characters = malloc(11 * sizeof(char));
	read(fd, characters, 10);;
	characters[10] = '\0';
	return characters;
}

char* litLigne(int fd) {
	char* characters = malloc(TAILLEBUF * sizeof(char));

	int readCount = read(fd, characters, TAILLEBUF);

	if (readCount == 0) {
		free(characters);
		return NULL;
	}
	int length = TAILLEBUF;
	for (int i = 0; i < TAILLEBUF; i++) {
		if (characters[i] == '\n') {
			length = i;
			break;
		}
	}
	if (length == TAILLEBUF) {
		free(characters);
		return NULL;
	}
	int p = lseek(fd, -(readCount - (length + 1)), SEEK_CUR);
	//printf("lseek : %d\n", p);
	char* result = malloc((length + 1) * sizeof(char));
	strncpy(result, characters, length);
	free(characters);
	return result;
}
