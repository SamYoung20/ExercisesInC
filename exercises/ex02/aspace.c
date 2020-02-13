/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>


int var1;
void print_addr(int variable){
  printf ("Address of local variable is %p\n", &variable);
}
int main ()
{
    int var2 = 5;
    int var3 = 7;
    void *p = malloc(128);
    char *s = "Hello, World";
    void *x = malloc(128);
    void *y = malloc(8);
    void *z = malloc(8);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    print_addr(var3);
  //  printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("y points to %p\n", y);
    printf ("z points to %p\n", z);

    return 0;
}

/*
4. Heap grow upward.
5. Stack grows downward.
6. Random number 8. I allocated two mallocs that wer
each 8 bytes big. The two address of these locations
were 32 bits apart. 0x20.



4/
*/
