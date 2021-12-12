SRC = $(wildcard *.c)

all:$(SRC:.c=.o)
	gcc hw0501.o poker.o -o hw0501
	gcc hw0502.o data.o -o hw0502 -lm
	gcc hw0503.o polynomial.o -o hw0503 -lm
	gcc hw0504.o banqi.o -o hw0504 -lm
	make clean


.PHONY : new zip clean cleanexe

new:
	cp ../template.c hw0.c
	code hw0.c

zip:
	zip hw05 ./*.c ./*.pdf ./*.h makefile

clean:
	@-rm *.o

cleanexe:
	@-rm hw050?