all: libfuncs.a main

main: main.o libfuncs.a
	gcc -o main main.o -L. -lfuncs
libfuncs.a: funco1.o funco2.o
	ar rv libfuncs.a funco1.o funco2.o
main.o: foo.c
	gcc -c foo.c
funco1.o:funco1.c
	gcc -o funco1.o -c funco1.c
funco2.o:funco2.c
	gcc -o funco2.o -c funco2.c
