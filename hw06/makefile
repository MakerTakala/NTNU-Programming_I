SRC = $(wildcard *.c)

all:$(SRC:.c=.o)
	gcc hw0601.o mirror.o -o hw0601 -lm
	gcc hw0602.o ext.o -o hw0602
	gcc hw0603.o -o hw0603
	gcc hw0604.o -o hw0604
	gcc hw0605.o -o hw0605
	make clean


.PHONY : new zip clean cleanexe

new:
	cp ../template.c hw0.c
	code hw0.c

zip:
	zip hw06 ./*.c ./*.pdf ./*.h makefile

clean:
	@-rm *.o

cleanexe:
	@-rm hw060?