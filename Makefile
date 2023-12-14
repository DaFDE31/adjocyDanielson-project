a.out: main.o
	$(CC) -o $@ $?
main.o:main.c
	$(CC) -c $?