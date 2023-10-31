#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>


#define RED "\x1b[31m"
#define GREY "\x1b[90m"
#define BLACK "\x1b[0m"
#define HEARTS "\u2665"
#define DIAMONDS "\u2666"
#define CLUBS "\u2663"
#define SPADES "\u2660"

typedef struct {
    const char *suit_symbol;
    char cardChar;
    const char *color_code;
    int card_value;
} Card;

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
    printf("%s ________ %s    Value:%d\n", card.color_code, BLACK,  card.card_value);
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

int main() {
    int bet;
    int ans = 1;
    int cardCnt= 3;
    float mon = 100;
    int playerTot = 0;
    int dealerTot = 0;
    int play = 1;
    float winMult;
    int LossID, dealerBust;
    
    system("clear");
    sleep(2);
   //intro
    printf("Hello, welcome to the virtual Black Jack Table!\n");
    sleep(1);
    printf("You start with $100. \n");
    sleep(1);
      while(play == 1){
      winMult = 1;
      dealerBust = 0;
      LossID = 0;
        printf("You may bet any integer dollar amount that you have remaining.\n");
        sleep(1);
        printf("How much would you like to bet?: ");
        sleep(1);
        scanf("%d", &bet);
          while ((bet > mon) && (bet<=0)){ // no over betting
            printf("Sorry, invalid bet.\n");
            sleep(1);
            printf("Please enter a valid bet: ");
            scanf("%d", &bet);
            sleep(1);
           }
        printf("You bet $%d\n",bet);
        sleep(1);
        mon = mon-bet;
        printf("You have $%.2f left.\n",mon);
        sleep(1);
        printf("\nDealers Cards are: \n");//Dealer Cards
        sleep(2);
        Card randomCard6 = generateRandomCard();
        displayCardInfo(randomCard6);// Dealer card 1
        sleep(1);
        printf("\n");
        flippedCard();//Dealer Card 2 (hidden)
        sleep(1);
    
        printf("\nYour cards are: \n");// Player Cards
        sleep(2);
        Card randomCard1 = generateRandomCard();
        displayCardInfo(randomCard1);//Player Card 1
        sleep(1);
        printf("\n");
        Card randomCard2 = generateRandomCard();
        displayCardInfo(randomCard2);// Player Card 2
        sleep(1);
    
        playerTot = randomCard1.card_value+randomCard2.card_value;//player card total
          if (playerTot == 21){
            printf("Black Jack!\n");
            winMult = 1.5;
            ans = 0;
            }
        
          while (ans == 1){
            printf("\nYour total card value is: %d\n", playerTot);
            printf("Would you like to hit or stay? (1-Hit, 0-Stay): ");
            scanf("%d",&ans);
            if (ans == 1){
              Card randomCard3 = generateRandomCard();
              displayCardInfo(randomCard3);//Player Card 3
              playerTot = playerTot+randomCard3.card_value;//player card total
                card1:
                if (playerTot > 21){
                    if ((randomCard1.card_value == 11)||(randomCard2.card_value == 11)||(randomCard3.card_value == 11)){
                      playerTot = playerTot-10;
                      goto card1;
                      }
                    printf("Bust!\n");
                    LossID = 1;
                      break;
                }else if (playerTot == 21){
                  printf("21! Congrats!");
                  break;
                }else if (playerTot < 21){
                printf("\nYour total card value is: %d\n", playerTot);
                  printf("Would you like to hit or stay? (1-Hit, 0-Stay): ");
                  scanf("%d",&ans);
                    if (ans == 1){
                      Card randomCard4 = generateRandomCard();
                      displayCardInfo(randomCard4);//Player Card 4
                      playerTot = playerTot+randomCard4.card_value;//player card total
                      card2:
                        if (playerTot > 21){
                          if ((randomCard1.card_value == 11)||(randomCard2.card_value == 11)||(randomCard3.card_value == 11)||(randomCard4.card_value == 11)){
                            playerTot = playerTot-10;
                            goto card2;
                          }
                          printf("Bust!\n");
                          LossID = 1;
                          break;
                        }else if (playerTot == 21){
                          printf("21! Congrats!");
                          break;
                        }else if (playerTot < 21){
                          printf("\nYour total card value is: %d\n", playerTot);
                          printf("Would you like to hit or stay? (1-Hit, 0-Stay): ");
                          scanf("%d",&ans);
                            if (ans == 1){
                              Card randomCard5 = generateRandomCard();
                              displayCardInfo(randomCard5);//Player Card 5
                              playerTot = playerTot+randomCard5.card_value;//player card total
                              card3:
                                if (playerTot > 21){
                                  if ((randomCard1.card_value == 11)||(randomCard2.card_value == 11)||(randomCard3.card_value == 11)||(randomCard4.card_value == 11)||(randomCard5.card_value == 11)){
                                      playerTot = playerTot-10;
                                      goto card3;
                                    }
                                   printf("Bust!");
                                   LossID = 1;
                                  break;
                                }else if (playerTot <= 21){
                                  printf("Holy Moly! Five Finger Charlie punch!\n");
                                  winMult = 5;
                                  break;
                                }
                            } else if (ans == 0){
                                break;
                                }
                        }
                    } else if (ans == 0){
                        break;
                        }
                }
            } else if (ans == 0){
                break;
                }
          }
      
    
        printf("Your final combined card value is: %d\n", playerTot);
        sleep(2);
        printf("The dealers cards: \n");
        sleep(1);
        displayCardInfo(randomCard6);// Dealer card 1
        sleep(1);
        printf("The dealer flips their face down card: \n");
        sleep(1);
        Card randomCard7 = generateRandomCard();
        displayCardInfo(randomCard7);// Dealer card 2
        dealerTot = randomCard6.card_value+randomCard7.card_value;//dealer card total
        printf("\nThe dealers combined value is: %d\n", dealerTot);
        sleep(1);
          if (dealerTot<17){
            Card randomCard8 = generateRandomCard();
            dealerTot = dealerTot+randomCard8.card_value;//dealer card total
            displayCardInfo(randomCard8);// Dealer card 3
            printf("\nThe dealers combined value is: %d\n", dealerTot);
            sleep(1);
              if (dealerTot<17){
                Card randomCard9 = generateRandomCard();
                dealerTot = dealerTot+randomCard9.card_value;//dealer card total
                displayCardInfo(randomCard9);// Dealer card 4
                printf("\nThe dealers combined value is: %d\n", dealerTot);
                sleep(1);
                  if (dealerTot<17){
                    Card randomCard10 = generateRandomCard();
                    dealerTot = dealerTot+randomCard10.card_value;//dealer card total
                    displayCardInfo(randomCard10);// Dealer card 5
                    printf("\nThe dealers combined value is: %d\n", dealerTot);
                    sleep(1);
                  }  
              }
          }
        if (dealerTot > 21){
          dealerBust = 1;
          }
        sleep(1);
        printf("\nThe dealers total card value is: %d\n", dealerTot);
        if ((dealerTot > playerTot)&&(dealerBust == 0)) // lose
        {
            printf("You lose to the dealer.\n");
            printf("You have $%.2f left.\n", mon);
          if (mon <= 0)
                {
                    
                    printf("You have $%.2f \n",mon);
                }
        }
        else if(LossID==1){
          printf("You lose!\n");
           printf("You have $%.2f \n",mon);
           }
        else if ((playerTot > dealerTot)&&(playerTot<=21)) // win
        {
            mon = mon+bet+(bet*winMult);
            printf("You win!\n");
            printf("You have won $%.2f!\n", (bet*winMult));
            printf("You have $%.2f \n",mon);
        }
        else if ((playerTot == dealerTot)&&(playerTot<=21)){ //push
          printf("It's a push!");
          mon = mon + bet;
          printf("You have $%.2f \n",mon);
        }
        
        printf("Would you like to play again? (1=yes,0=No) ");
        scanf("%d", &play);
    
    }
    
    return 0;
}

