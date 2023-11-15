#include "functions.h"
#include "structure.h"
Card generateRandomCard() {
    Card card;
    srand(time(NULL));

    int rsuit = rand() % 4;
    int rval = rand() % 13;

    switch (rsuit) {
        case 0: // Hearts
            card.suit_symbol = HEARTS;
            //printf("\u2665");
            card.color_code = RED;
            break;
        case 1: // Diamonds
            card.suit_symbol = DIAMONDS;
            //printf("\u2666");
            card.color_code = RED;
            break;
        case 2: // Clubs
            card.suit_symbol = CLUBS;
           // printf("\u2667");
            card.color_code = GREY;
            break;
        case 3: // Spades
            card.suit_symbol = SPADES;
            //printf("\u2664");
            card.color_code = GREY;
            break;
        default:
            break;
    }

    switch (rval) {
        case 0: // Ace
            card.card_value = 11; 
            card.cardChar = 'A';
            break;
        case 1: // 2
            card.card_value = 2;
            card.cardChar = '2';
            break;
        case 2: // 3
            card.card_value = 3;
            card.cardChar = '3';
            break;
        case 3: // 4
            card.card_value = 4;
            card.cardChar = '4';
            break;
        case 4: // 5
            card.card_value = 5;
            card.cardChar = '5';
            break;
        case 5: // 6
            card.card_value = 6;
            card.cardChar = '6';
            break;
        case 6: // 7
            card.card_value = 7;
            card.cardChar = '7';
            break;
        case 7: // 8
            card.card_value = 8;
            card.cardChar = '8';
            break;
        case 8: // 9
            card.card_value = 9;
            card.cardChar = '9';
            break;
        case 9: // 10
            card.card_value = 10;
            card.cardChar = 'T';
            break;
        case 10: // Jack
            card.card_value = 10;
            card.cardChar = 'J';
            break;
        case 11: // Queen
            card.card_value = 10;
            card.cardChar = 'Q';
            break;
        case 12: // King
            card.card_value = 10;
            card.cardChar = 'K';
            break;
        default:
            break;
    }

    return card;
}

void displayCardInfo(Card card) {
    //printf("%s ________ %s    Value:%d\n", card.color_code, BLACK,  card.card_value);
    printf("%s ________ %s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s| %s%s%s %c    |%s\n", card.color_code, BLACK, card.suit_symbol, card.color_code,  card.cardChar, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|    %s%s%s %c |%s\n", card.color_code, BLACK, card.suit_symbol, card.color_code,  card.cardChar, BLACK);
    printf("%s|________|%s\n", card.color_code, BLACK);
    //printf("Random Card: %s%c %c%s Value:%d\n", card.color_code, card.suit_symbol, card.cardChar, BLACK, card.card_value);
}
void flippedCard(){
    printf("%s ________ %s\n", RED, BLACK);
    printf("%s|        |%s\n", RED, BLACK);
    printf("%s| ****** |%s\n", RED, BLACK);
    printf("%s| ****** |%s\n", RED, BLACK);
    printf("%s| ****** |%s\n", RED, BLACK);
    printf("%s| ****** |%s\n", RED, BLACK);
    printf("%s| ****** |%s\n", RED, BLACK);
    printf("%s| ****** |%s\n", RED, BLACK);
    printf("%s| ****** |%s\n", RED, BLACK);
    printf("%s|________|%s\n", RED, BLACK);
}

float winCon(float mon,float winMult, int bet){
  printf("You win!!\n");
  mon = mon + bet + (bet*winMult);
  printf("You have $%.2f \n",mon);
  return mon;
}

float loseCon(float mon){
  printf("You lose!!\n");
  printf("You have $%.2f \n",mon);
  return 0;
}

float push(float mon, int bet){
  printf("It's a push!!\n");
  mon = mon + bet;
  printf("You have $%.2f \n",mon);
  return mon;
}
