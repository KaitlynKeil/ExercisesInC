/*
 * Program to evaluate face values.
 * Released under the Vegas Public License.
 * (c)2014 The College Blackjack Team.
 */

 #include <stdio.h>
 #include <stdlib.h>

int val_assign(char * name);
void change_count(int val);
void game_loop(char * card_name);

/* Based on the name of the card,
assigns a point value.
name: character array of length 3 for card name
output: int point value */
int val_assign(char * name) {
  int val = 0;
  switch (name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      break;
    default:
      val = atoi(name);
      if (val < 3 || val > 10) {
        puts("Not a valid card.");
        val = 0;
      };
  }
  return val;
}

/* Keeps track of the count, updating based on current card value.
val: value of current card */
void change_count(int val) {
  static int count = 0;
  if (val >= 3 && val <= 6) {count++;}
  else if (val == 10) {count--;}
  printf("Current count: %i\n", count);
}

/* Game loop that takes user input and runs until 'X' is entered.
Input is truncated to first 2 characters.

card_name: buffer in which to put user input. */
void game_loop(char * card_name) {
  do {
    int val;
	 	puts("Enter the card_name: ");
	 	scanf("%2s", card_name);
    val = val_assign(card_name);
    if (!val) {continue;}
	 	change_count(val);
	 } while(card_name[0] != 'X');
}

/* Main function, which creates the user input buffer and
runs game_loop.
*/
 int main()
 {
 	char card_name[3];

 	game_loop(card_name);

 	return 0;
 }
