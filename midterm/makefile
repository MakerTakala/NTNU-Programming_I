ObjectO = mid01.o mid02.o mid03.o mid04.o
Object = mid01 mid02 mid03 mid04

midterm: $(ObjectO) midfunction.o
	gcc mid01.o midfunction.o -o mid01
	gcc mid02.o midfunction.o -o mid02 -lm
	gcc mid03.o midfunction.o -o mid03 -lm
	gcc mid04.o midfunction.o -o mid04 -lm
	-rm *.o
	strip $(Object)

$(ObjectO): midfunction.h

midfunction.o: midfunction.h


.PHONY: zip clean

zip:
	zip mid *.c *.pdf *.h makefile

clean:
	-rm mid??