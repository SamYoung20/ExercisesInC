# trout:main.c trout.h trout.c util.c
# 	gcc -g -o trout main.c trout.c util.c

util.o: util.c util.h
	gcc -c util.c

trout.o: trout.c trout.h
	gcc -c trout.c

main.o: main.c trout.o util.o
	gcc -c main.c

trout: main.o util.o trout.o
	gcc main.o util.o trout.o -o trout
