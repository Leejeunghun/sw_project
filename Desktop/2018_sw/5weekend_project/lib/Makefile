libfoo.a:funco1.o funco2.o
	ar rv libfoo.a funco1.o funco2.o
funco1.o :funco1.c
	gcc -I /home/lee/Desktop/2018_sw/5weekend_project/include -c funco1.c
funco2.o :funco2.c
	gcc -I /home/lee/Desktop/2018_sw/5weekend_project/include -c funco2.c
clean:
	rm *.o *.a
