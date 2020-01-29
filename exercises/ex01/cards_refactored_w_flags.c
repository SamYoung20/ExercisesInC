    /* cards_refactored.c
      Author: Samantha Young
      Year: 1/28/20
      Class: Software Systems Spring 20
      The script displays the count of each card and ends the program if the player types X
      License:
    */
#include <stdio.h>
#include <stdlib.h>

/* Prompts the user to input card time and saves replu.

   User input is truncated to the first two characters.

   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void get_card_name(char *prompt, char *card_name){
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
}
/* Updates count based on the value of each card

   returns updated count

   val: integar value of current card
   count: integar of culmative count from card counter
*/
int update_count_value(int val, int count){
  if ((val > 2) && (val < 7)){
    count++;
  } else if (val == 10){
    count--;
  }
  return count;
}
/* Determines if value of card is within range for incremental counter
    informs user if an unknown character was entered
    val: integar value of current card
*/
void is_val_not_in_range(int val){
    if((val<1)||(val>10)){
      puts("I don't understand that value!");
    }
  }

int main()
{
    char card_name[3];
    int counter = 0;
    int val = 0;
    do {
        get_card_name("Enter the card_name: ", card_name);
        switch(card_name[0]){
          case 'K':
          case 'Q':
          case 'J':
            val = 10;
            break;
          case 'A':
            val = 11;
            break;
          case 'X':
            continue;
          default:
            val = atoi(card_name);
            is_val_not_in_range(val);
            }
        counter = update_count_value(val,counter);
        printf("Current count: %i\n", counter);
    } while(card_name[0]!='X');
      return 0;
}
