all:hw0301
	
hw0301:hw0301.o exit.o
	gcc hw0301.c exit.o -lm -o hw0301
	make clean

exit.o:exit.c exit.h
	gcc -c exit.c



.PONHY:clean

clean:
	-rm -f *.o