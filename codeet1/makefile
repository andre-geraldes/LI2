CC = gcc
CFLAGS = -ansi -Wall -Wextra -pedantic -O2
 
all: tarefa1 tarefa2

tarefa2: tarefa2.o
	$(CC) $(CFLAGS) -o tarefa2 tarefa2.c
		  
tarefa1: tproc.o cadeias.o
	$(CC) $(CFLAGS) -o teste tproc.c cadeias.c

clean:
	rm -f *.o
