/* Example code for Software Systems at Olin College.

Instructions:

1) Fill in the body of endswith so it passes the tests.

You can use any of the functions in string.h
https://www.tutorialspoint.com/c_standard_library/string_h.htm

2) Remove the TODO comment.

Copyright 2017 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int main(int argc, char *argv[])
{
  FILE *file_out;
  char buffer[100];
    if((argc == 3) && (strcmp("-a", argv[1])==0)){
      file_out = fopen(argv[2], "a");
    }
    if(argc == 2){
      file_out = fopen(argv[1], "w");
    }
  puts("Input value into file: ");
  fgets(buffer, 100, stdin);
  fprintf(file_out, "%s", buffer);
  printf("%s\n", buffer);
  }
/*
What worked: I was quickly able to write a funciton that read a standard input
wrote to a file and outputed a standard output. I was able to refer back to
chapter 3 to figure out the syntax for the arguments of main() which was very
helpful.
What slowed me down: The syntax of how to actually call tee slowed me down.
I ran into some segmentation faults during that process which turned out to
be a result of incorectly using strcmp. I needed to review string manipulation
functions.

Professional code vs My solution:
The most important part of the professional code that was different from my own
code was there error handling. The professional code was able to determing what
the user inputed and give apporpriate error messages based on the input. My code
required the user to input the right things in the right order. Additonally
the professional code has a longer buffer size for the standard input.

*/
