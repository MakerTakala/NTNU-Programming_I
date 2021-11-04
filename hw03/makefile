all:
	@gcc hw0301.c -o hw0301 -lm
	@gcc hw0302.c -o hw0302 -lm
	@gcc hw0303.c -o hw0303
	@gcc hw0304.c -o hw0304
	@gcc hw0305.c -o hw0305

.PHONY : new zip clean

new:
	@cp ../template.c hw0300.c
	@code hw0300.c

zip:
	zip hw03 ./*.c ./*.pdf makefile

clean:
	@-rm hw030?
