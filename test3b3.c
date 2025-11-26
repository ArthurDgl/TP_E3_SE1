#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "gestionFichiers.h"

int main(int argc, char **argv) {
	while(1) {
		char *str = litLigne(0);
		if (str[0] == ':') if (str[1] == 'q') {
			free(str);
			break;
		}
		ecritChaine(1, str);
		free(str);
	}
	return 1;
}
