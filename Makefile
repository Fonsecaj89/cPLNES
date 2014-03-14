auxiliar.o: auxiliar.c auxiliar.h
	gcc -c -std=c99 -g auxiliar.c

texto.o: texto.c texto.h auxiliar.h
	gcc -c -std=c99 -g texto.c

archivo.o: archivo.c archivo.h auxiliar.h texto.h
	gcc -c -std=c99 -g archivo.c

motor.o: motor.c  archivo.h 
	gcc -c -std=c99 -g motor.c

cplnes: motor.o auxiliar.o archivo.o texto.o
	gcc archivo.o texto.o motor.o auxiliar.o -o cplnes && ./cplnes

