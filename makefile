all:
	gcc test.c -o test.exe

newhw:
	@mkdir newhw
	@cp ./hw01/makefile ./newhw
	@code ./newhw README.txt
	