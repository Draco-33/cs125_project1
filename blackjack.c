#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include "functions.h"

#define RED "\x1b[31m"
#define GREY "\x1b[90m"
#define BLACK "\x1b[0m"
#define HEARTS "\u2665"
#define DIAMONDS "\u2666"
#define CLUBS "\u2663"
#define SPADES "\u2660"


int main(){
    int bet;
    int ans = 1;
    int cardCnt= 3;
    float mon=100;
    int playerTot = 0;
    int dealerTot = 0;
    int play = 1;
    float mon_array[100];
    int play_cntloop;
    float winMult;
    int play_cnt = 0;
    int LossID, dealerBust, blackjack1, blackjack2, charlie;
    
    system("clear");
    sleep(2);
   //intro
    printf("Hello, welcome to the virtual Black Jack Table!\n");
    sleep(1);
    printf("You start with $100. \n");
    sleep(1);
    mon_array[0] = mon;
      while(play == 1){
      winMult = 1;
      dealerBust = 0;
      LossID = 0;
      ans = 1;
      blackjack1 = 0;
      blackjack2 = 0;
      charlie = 0;
        printf("You may bet any integer dollar amount that you have remaining.\n");
        sleep(1);
        printf("How much would you like to bet?: ");
        sleep(1);
        scanf("%d", &bet);
          while ((bet > mon) || (bet<=0)){ // no over betting
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
    
        printf("\n\nYour cards are: \n\n");// Player Cards
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
            blackjack1 = 1;
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
                                  charlie = 1;
                                  
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
        printf("\nThe dealers cards: \n\n");
        sleep(1);
        displayCardInfo(randomCard6);// Dealer card 1
        sleep(1);
        printf("\nThe dealer flips their face down card: \n");
        sleep(1);
        Card randomCard7 = generateRandomCard();
        displayCardInfo(randomCard7);// Dealer card 2
        dealerTot = randomCard6.card_value+randomCard7.card_value;//dealer card total
        printf("\nThe dealers combined value is: %d\n", dealerTot);
        if(dealerTot == 21){
          blackjack2 = 1;
        }
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
        if(charlie==1){                             // Win conditions
          mon = winCon(mon,winMult,bet);
        
        }else if((blackjack1==1)&&(blackjack2==1)){
           mon = push(mon,bet);
        
        }else if((blackjack1==1)&&(blackjack2!=1)){
           printf("You got Blackjack!!!\n");
           mon = winCon(mon,winMult,bet);
        
        }else if((blackjack2==1)&&(blackjack1!=1)){
           printf("The Dealer got Blackjack!!!\n");
           loseCon(mon);
        
        }else if((LossID == 1)&&(dealerBust==1)){
           loseCon(mon);
           
        }else if(playerTot == dealerTot){
           mon = push(mon,bet);
           
        }else if((dealerTot > playerTot)&&(dealerBust!=1)){
           printf("You lose to the dealer\n");
           loseCon(mon);
        
        }else if((dealerBust == 1)&&(LossID!=1)){
           printf("Dealer Busts!!\n");
           mon = winCon(mon,winMult,bet);
        
        }else if((LossID == 1)&&(dealerTot<=21)){
           loseCon(mon);
        
        }else if((playerTot > dealerTot)&&(LossID!=1)){
           mon =  winCon(mon,winMult,bet);
        }
        mon_array[play_cnt+1] = mon;      //Array for mon totals
        if(mon==0){
          printf("You're broke sucker\n");
          break;
        } 
        printf("Would you like to play again? (1=yes,0=No) ");     // while loop end to see of you want to play again
        scanf("%d", &play);
        if(play == 1) 
          system("clear");
          printf("You have $%.2f\n",mon);
          play_cnt++;
    }
    FILE *f1 = fopen("Recept", "w");      // Writing to a file to make your recipt 
    fprintf(f1,"\n");
    fprintf(f1,"You ended the game with $%.2f \n",mon);
    fprintf(f1,"\n");
    fprintf(f1,"\n");
    fprintf(f1," Your money after each game: ");
    for(play_cntloop=0; play_cntloop<=play_cnt; play_cntloop++){
      fprintf(f1,"Game %d: %.2f ", play_cntloop+1, mon_array[play_cntloop]);
    }
    fprintf(f1,"\n");
    fprintf(f1,"\n");
    fprintf(f1,"\n");
    fprintf(f1,"Please take this recept to the cashier to cash out\n");
    fclose(f1);
    printf("Your recept is in the text file Recept\n");
    
    return 0;
}

