ObjectO = mid01.o mid02.o mid03.o mid04.o
Object = mid01 mid02 mid03 mid04

midterm: $(ObjectO) midfunction.o
	gcc mid01.o midfunction.o -o mid01
	gcc mid02.o midfunction.o -o mid02
	gcc mid03.o midfunction.o -o mid03 -lm
	-gcc mid04.o midfunction.o mid04function.o -o mid04 -lm
	-rm *.o
	strip $(Object)

$(ObjectO): midfunction.h

mid04: mid04function.h

midfunction.o: midfunction.h

mid04function.o: mid04function.h 

.PHONY: zip clean

zip:
	zip mid *.c *.pdf *.h makefile

clean:
	-rm mid??