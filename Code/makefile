list :main.o list.o
	gcc -o list main.o list.o
main.o :main.c list.h
	cc -c main.c
b.o :b.c b.h
	cc -c list.c
clean:
	rm -f list.o main.o
