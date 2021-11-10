sall: 
	@gcc mid01.c midfunction.c -o mid01 -lm
	@gcc mid02.c midfunction.c -o mid02 -lm
	@gcc mid03.c midfunction.c -o mid03 -lm
	@gcc mid04.c midfunction.c -o mid04 -lm


.PHONY : zip clean

zip:
	zip hw03 ./*.c ./*.pdf makefile

clean:
	@-rm hw020?