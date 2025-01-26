all:
	@clear
	@gcc -c src/rsa.c
	@gcc -c src/functions.c
	@gcc -o rsa rsa.o functions.o
	@rm rsa.o
	@rm functions.o
	
