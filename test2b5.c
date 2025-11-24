#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "gestionFichiers.h"

int main() {
	char* characters = litLigne(0);
	printf("%s\n", characters);
	free(characters);
}
