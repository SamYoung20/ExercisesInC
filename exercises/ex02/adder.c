/* adder.c
  Author: Samantha Young
  Year: 2/5/20
  Class: Software Systems Spring 20
  This scripts adds all numbers inputed by user in terminal and prints the sum
  License:
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

/* reads in user input and stores it in buffer
  num: buffer where user input is stored
*/

void get_ints(char *num){
  puts("Enter integer 0 - 9999: ");
  scanf("%4s", num);
}

/* Accumulates sum and prints output
  all_num: array of numbers to sum
*/

void print_sum(int *all_num){
  int sum = 0;
  for(int i = 0; i < SIZE; i++){
    printf("%d ", all_num[i]);
    sum+=all_num[i];
  }
  printf("\n Your sum is %d \n", sum);
}

void main()
{
  int all_num[SIZE] = {}; //max number of entries the program will add is 5
  char num[5];
  int val = 0;
  int sum = 0;
  int end = 1;
  int index = 0; // count of how many numbers to add
  do {
        if(index < SIZE){
          get_ints(num);
          if (fgets(num, 10, stdin) == NULL)
            break;
          val = atoi(num);
          if(val<1 || val>9999){
            printf("Value is not in range. Please enter new value \n");
          }
          else{
            all_num[index] = val;
            index++;
          }
        }
        else {
          printf("You have inputted the max number of entries \n");
          end = -1;
        }
    } while(end != -1);
      print_sum(all_num);

}
