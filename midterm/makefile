ObjectC = mid01.c mid02.c mid03.c mid04.c
ObjectO = mid01.o mid02.o mid03.o mid04.o

all: $(ObjectO) midfunction.o
	gcc mid01.o midfunction.o -o mid01 -lm
	gcc mid02.o midfunction.o -o mid02 -lm
	gcc mid03.o midfunction.o -o mid03 -lm
	gcc mid04.o midfunction.o -o mid04 -lm
	-rm *.o

$(ObjectO) : $(ObjectC) midfunction.h

midfunction.o: midfunction.c midfunction.h


.PHONY: zip clean

zip:
	zip mid ./*.c ./*.pdf makefile

clean:
	-rm mid??