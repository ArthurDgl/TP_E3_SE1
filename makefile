all: test test2b1 test2b2 test2b3

test: test.o gestionFichiers.o
	gcc -o test test.o gestionFichiers.o

test.o: test.c gestionFichiers.h
	gcc -o test.o -c test.c

test2b1: test2b1.o
	gcc -o test2b1 test2b1.o gestionFichiers.o

test2b1.o: test2b1.c gestionFichiers.h
	gcc -o test2b1.o -c test2b1.c

test2b2: test2b2.o
	gcc -o test2b2 test2b2.o gestionFichiers.o

test2b2.o: test2b2.c gestionFichiers.h
	gcc -o test2b2.o -c test2b2.c

test2b3: test2b3.o
	gcc -o test2b3 test2b3.o gestionFichiers.o

test2b3.o: test2b3.c gestionFichiers.h
	gcc -o test2b3.o -c test2b3.c

gestionFichiers.o: gestionFichiers.c constants.h
	gcc -o gestionFichiers.o -c gestionFichiers.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf test
	rm -rf test2b1
	rm -rf test2b2
	rm -rf test2b3
