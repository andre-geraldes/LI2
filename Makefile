CC = gcc
CFLAGS = -ansi -Wall -Wextra -pedantic -O2
 
all: tarefa1 tarefa2 tarefa3 tarefa4

tarefa1: tproc.c cadeias.c
	$(CC) $(CFLAGS) -o tarefa1 tproc.c cadeias.c

tarefa2: tarefa2.c
	$(CC) $(CFLAGS) -o tarefa2 tarefa2.c

tarefa3: teste3.c tarefa3.c cadeias.c
	$(CC) $(CFLAGS) -o tarefa3 teste3.c tarefa3.c cadeias.c

tarefa4: tarefa4b.c tarefa3.c cadeias.c
	$(CC) $(CFLAGS) -o tarefa4 tarefa4b.c tarefa3.c cadeias.c

clean:
	rm -f tarefa1 tarefa2 tarefa3 tarefa4 *.o
