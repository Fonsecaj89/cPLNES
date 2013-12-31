texto.o: texto.c texto.h
	gcc -c -std=c99 texto.c
motor.o: motor.c texto.h
	gcc -c -std=c99 motor.c
cplnes: texto.o motor.o
	gcc texto.o motor.o -o cplnes && ./cplnes

