fun:f.c libfuncs.so
	gcc -o foo f.c -L./ -lfuncs
libfuncs.so:funcs.o
	ld -shared -soname=libfuncs.so.1.0 *.o -o libfuncs.so.1.0 -lc
funcs.o:funcs.c
	gcc -c -fPIC funcs.c
