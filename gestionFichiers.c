#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gestionFichiers.h"
#include "constants.h"

char* litDixCaracteres(int fd) {
	char* characters = malloc(11 * sizeof(char));
	read(fd, characters, 10);
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
			length = i + 1;
			break;
		}
	}
	if (length == TAILLEBUF) {
		free(characters);
		return NULL;
	}
	int p = lseek(fd, -(readCount - length), SEEK_CUR);
	//printf("lseek : %d\n", p);
	char* result = malloc((length + 1) * sizeof(char));
	strncpy(result, characters, length);
	result[length] = '\0';
	free(characters);
	return result;
}

void ecritChaine(int fd, char* str) {
	size_t len = (strlen(str) + 1) * sizeof(char);
	//printf("len: %d\n", (int)len);
	size_t total = 0;

	while (total < len) {
		ssize_t written = write(fd, str + total, len - total);
		if (written < 0) return;
		total += written;
	}
}
