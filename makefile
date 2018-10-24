all : file.c test.txt
	gcc -o file file.c

run : ./file
	./file
