all:
	gcc test.c -o test.exe

newhw:
	@mkdir newhw
	@cp ./hw02/makefile ./newhw
	@code ./newhw README.txt
	
