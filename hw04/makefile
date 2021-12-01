SRC = $(wildcard *.c)

all:$(SRC:.c=.o)
	gcc hw0401.o hw04fuc.o -o hw0401
	gcc hw0402-1.o hw04fuc.o -o hw0402-1
	gcc hw0402-2.o hw04fuc.o -o hw0402-2
	-gcc hw0403.o triangle.o -lm -o hw0403
	gcc hw0404.o hw04fuc.o -o hw0404
	gcc hw0405.c -o hw0405
	make clean

.PHONY : new zip clean cleanexe

new:
	cp ../template.c hw0.c
	code hw0.c

zip:
	zip hw04 ./*.c ./*.pdf ./*.h makefile

clean:
	@-rm *.o

cleanexe:
	@-rm hw050?
