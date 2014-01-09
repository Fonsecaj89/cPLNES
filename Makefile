auxiliar.o: auxiliar.c auxiliar.h
	gcc -c -std=c99 auxiliar.c
texto.o: texto.c texto.h auxiliar.h
	gcc -c -std=c99 texto.c
motor.o: motor.c texto.h 
	gcc -c -std=c99 motor.c
cplnes: texto.o motor.o auxiliar.o
	gcc texto.o motor.o auxiliar.o -o cplnes && ./cplnes && valgrind --leak-check=yes

