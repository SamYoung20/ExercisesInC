/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
/*
### Stack allocated data

1.  Read `stack.c`, which should be in this directory.  What is it
intended to do?  What would the output be if the program worked as
expected?

The program inteds to make an array of size 5 filled with the number 42
in each element of the array. It then intends to print the array and change the
values to be 1 2 3 4 5.

Finally it is supposed to print the array.

2. You get a warning in the function "foo"
    warning: function returns address of local variable [-Wreturn-local-addr]
     return array;
     This function returns the address of a local variable. Local variables are
     created in the stack and destroyed when the program goes out of scope. This
     function returns a pointer to an invalid memory location.

3. When running the code I got a segmentation fault. This means I am trying to
access data I don't have access to.
4. When commenting out the print statements in foo() and bar() I still get a
seg fault. I remove the seg fault by commenting out the final print statement in
main(), rintf("%d\n", array[i]); This is because we are trying to access array.
Array was created in foo and then destroyed so the pointer doesn't point to a
valid place in memory. A way to fix this would be to pass a variable that can
exist between the scopes of these funcitons or not point to stack allocated data. 


*/
