#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "gestionFichiers.h"
#include "constants.h"

char* litDixCaracteres(int fd) {
	char* characters = malloc(11 * sizeof(char));
	read(fd, characters, 10);;
	characters[10] = '\0';
	return characters;
}

char* litLigneAt(int fd, off_t offset) {
	char* characters = malloc(TAILLEBUF * sizeof(char));
	int readCount = pread(fd, characters, TAILLEBUF, offset);
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
	char* result = malloc((length + 1) * sizeof(char));
	strncpy(result, characters, length);
	free(characters);
	return result;
}

char* litLigne(int fd) {
	return litLigneAt(fd, 0);
}
