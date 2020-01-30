    /* cards.c
      Author: Samantha Young
      Year: 1/28/20
      Class: Software Systems Spring 20
      The script displays the count of each card and ends 
      the program if the player types X
      License:
    */
#include <stdio.h>
#include <stdlib.h>

/* Prompts the user to input card time and saves result.
   User input is truncated to the first two characters.
   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void get_card_name(char *prompt, char *card_name){
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
}

/* Determines if the card counter should be incremneted
   val: integer value of the current card
   count: integer value of the culmative count of the cards
*/
int update_count_value(int val, int count){
  if ((val > 2) && (val < 7)){
    count++;
  } else if (val == 10){
    count--;
  }
  return count;
}

/* Determines if user input is a character that is countable 
   by the program.
  val: integer value of the current card
*/
void is_val_not_in_range(int val){
    if((val<1)||(val>10)){
      puts("I don't understand that value!");
    }
  }

  /* Determines what count is corresponds to the card a 
    user played
    card_name: buffer where card name is stored
    val: integar value of the card that was played
  */
int get_count(char *card_name, int val){
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
      default:
        val = atoi(card_name);
        is_val_not_in_range(val);
        }
    return val;
  }

int main()
{
    char card_name[3];
    int counter = 0;
    int val = 0;
    do {
        val = get_count(card_name, val);
        counter = update_count_value(val,counter);
        printf("Current count: %i\n", counter);
    } while(card_name[0]!='X');
      return 0;
}

/*compile with flag errors.
the use of // for comments is not allowed
flag required me to change the location of a variable declaration because I declared variables within the do loop
*/
