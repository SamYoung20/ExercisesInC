#include <stdio.h>

int main() {
    int x = 5;
    //printf("Hello, World!");
    int y = x + 1;
    printf("Hello, World! Your int is: %i\n", y);
    return 0;
}

//optimization
/*
Experiment 1: Line 18 in the assembly ocde file hello.s corresponds to the line int x = 5
"movl	$5, -4(%rbp)" This line movl, moves a long from a souce location to a destination location.
In this case moving the 5 to the register assiciated with x.

Experiment 2:
In the non optimized version of hello.s the assembly code is 30 lines.
The optimized version is reduced to 27 lines. In the optimized code there seems
to be more setup before the main function like the inclusiton of ".palign" under .LCO:
However there are fewer commands in the main function. For instance the optimized code
does not include the pushq	%rbp.

Experiment 3:
The length of the code is increased. This section on the assmebly code is new from the
version without the print statement.
"	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi"
  This accesses the value of x to include in the print statement.
The optimized version has a shorter main function and uses some commnads not present in the not optimized
version like xorl.

Experiment 4:
In the optimized verion the value for x is never written because it is never used.
Y is stored in a general purpose register used for short term variables because it only lives
inside this function. 

Optimization seems to get rid of intermediate and steps deemed unnesary based on what the
end goal of the program is.

*/
