SRC = $(wildcard *.c)

all:$(SRC:.c=.o)
	gcc fin01.o -o fin01 -lm
	gcc fin02.o go.o -o fin02 -lm
	gcc fin03.o frac.o -o fin03 -lm
	gcc fin04.o mem.o -o fin04
	make clean


.PHONY : new zip clean cleanexe

new:
	cp ../template.c hw0.c
	code hw0.c

zip:
	zip fin ./*.c ./*.pdf ./*.h makefile

clean:
	@-rm *.o

cleanexe:
	@-rm fin0?