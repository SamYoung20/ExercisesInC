# trout:main.c trout.h trout.c util.c
# 	gcc -g -o trout main.c trout.c util.c

util.o: util.c util.h
	gcc -c -Wall util.c

trout.o: trout.c trout.h
	gcc -c -Wall trout.c

main.o: main.c trout.o util.o
	gcc -c -Wall main.c

trout: main.o util.o trout.o
	gcc -Wall main.o util.o trout.o -o trout
