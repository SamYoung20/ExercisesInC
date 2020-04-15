/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>

/*
I initializing and printing local, and global variables in the stack, heap,
and global parts of the code at various points of the program.
The global variables like glob_var and *ptr are used by both parent and child
processes. This is seen when printing out the addresses of these variables in
the parent and child processes and they are the same. 

*/
// errno is an external global variable that contains
// error information
extern int errno;
int glob_var = 10; // THIS IS A GLOBAL VARIABLE THAT SHOULD BE SHARED BETWEEN CHILDREN
char *ptr = "I am a shared string"; //ALL CHILDREN SHARE STATIC VARIABLES
// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i , int* heap_var)
{
    int local_var = i+10; //THIS SHOULD BE IN THE STACK AND SHOULD NOT BE SHARED
    sleep(i);
    glob_var--; // THIS PROCESS WILL ONLY IMPACT THIS CHILD
    printf("Hello from child %d.\n", i);
    printf("child %d. GlobalVariable:%d, Address: %p\n", i, glob_var,&glob_var);
    printf("child %d. Static string:%s, Address: %p\n",i, ptr, &ptr);
    printf("child %d. LocalVariable:%dAddress: %p\n", i, local_var, &local_var);
    printf("heap_var:%d: Address%p\n", *heap_var, heap_var);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;
    int stack_var = 1;
    int *heap_var = malloc(sizeof(int));
    *heap_var = 1;
    int local_var1 = 0;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        *heap_var = *heap_var+1;
        pid = fork();
        stack_var++;
        local_var1++;
        printf(" %d. MAINLocalVariable1:%d Address: %p\n", i, local_var1, &local_var1);
        printf("%d, MAINStack_var:%d\n",i,  stack_var); //STACK VARIABLE
        printf("%d, MAINheap_var:%d: Address%p\n", i, *heap_var,heap_var); //HEAP VARIABLE
        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i, heap_var);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);
    printf("Parent: heap_var:%d: Address%p\n", *heap_var, heap_var);
    printf("Parent: %d. Static string:%s, Address: %p\n",i, ptr, &ptr);
    printf("Parent: %d. LocalVariable:%dAddress: %p\n", i, local_var1, &local_var1);
    exit(0);
}
