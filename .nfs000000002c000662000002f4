#include "functions.h"

Card generateRandomCard() {
    Card card;
    srand(time(NULL));

    int rsuit = rand() % 4;
    int rval = rand() % 13;

    switch (rsuit) {
        case 0: // Hearts
            card.suit_symbol = HEARTS;
            card.color_code = RED;
            break;
        case 1: // Diamonds
            card.suit_symbol = DIAMONDS;
            card.color_code = RED;
            break;
        case 2: // Clubs
            card.suit_symbol = CLUBS;
            card.color_code = GREY;
            break;
        case 3: // Spades
            card.suit_symbol = SPADES;
            card.color_code = GREY;
            break;
        default:
            break;
    }

    switch (rval) {
        case 0: // Ace
            card.card_value = 11; 
            card.card_char = 'A';
            break;
        case 1: // 2
            card.card_value = 2;
            card.card_char = '2';
            break;
        case 2: // 3
            card.card_value = 3;
            card.card_char = '3';
            break;
        case 3: // 4
            card.card_value = 4;
            card.card_char = '4';
            break;
        case 4: // 5
            card.card_value = 5;
            card.card_char = '5';
            break;
        case 5: // 6
            card.card_value = 6;
            card.card_char = '6';
            break;
        case 6: // 7
            card.card_value = 7;
            card.card_char = '7';
            break;
        case 7: // 8
            card.card_value = 8;
            card.card_char = '8';
            break;
        case 8: // 9
            card.card_value = 9;
            card.card_char = '9';
            break;
        case 9: // 10
            card.card_value = 10;
            card.card_char = 'T';
            break;
        case 10: // Jack
            card.card_value = 10;
            card.card_char = 'J';
            break;
        case 11: // Queen
            card.card_value = 10;
            card.card_char = 'Q';
            break;
        case 12: // King
            card.card_value = 10;
            card.card_char = 'K';
            break;
        default:
            break;
    }

    return card;
}

void displayCardInfo(Card card) {
    printf("%s ________ %s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s| %s%s%s %c    |%s\n", card.color_code, BLACK, card.suit_symbol, card.color_code,  card.card_char, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|        |%s\n", card.color_code, BLACK);
    printf("%s|    %s%s%s %c |%s\n", card.color_code, BLACK, card.suit_symbol, card.color_code,  card.card_char, BLACK);
    printf("%s|________|%s\n", card.color_code, BLACK);
}

void flippedCard() {
    const char *not_card[] = {
        "%s ________ %s",
        "%s|        |%s",
        "%s| ****** |%s",
        "%s| ****** |%s",
        "%s| ****** |%s",
        "%s| ****** |%s",
        "%s| ****** |%s",
        "%s| ****** |%s",
        "%s| ****** |%s",
        "%s|________|%s"
    };
    
    for (int i = 0; i < sizeof(not_card) / sizeof(not_card[0]); ++i) {
        printf(not_card[i], RED, BLACK);
        printf("\n");
    }
}

float winCon(float mon, float win_mult, int bet) {
    printf("You win!!\n");
    mon = mon + bet + (bet * win_mult);
    printf("You have $%.2f \n", mon);
    return mon;
}

float loseCon(float mon) {
    printf("You lose!!\n");
    printf("You have $%.2f \n", mon);
    return 0;
}

float push(float mon, int bet) {
    printf("It's a push!!\n");
    mon = mon + bet;
    printf("You have $%.2f \n", mon);
    return mon;
}
