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

int main() {
    // Variable Declarations
    int bet;
    int ans = 1;
    int card_cnt = 3;
    float mon = 100;
    int player_tot = 0;
    int dealer_tot = 0;
    int play = 1;
    float win_mult;
    int loss_id, dealer_bust, blackjack1, blackjack2, charlie;

    // Clear the console screen
    system("clear");
    sleep(2);

    // Introductory Messages
    printf("Hello, welcome to the virtual Black Jack Table!\n");
    sleep(1);
    printf("You start with $100. \n");
    sleep(1);

    // Main Game Loop
    while (play == 1) {
        // Resetting variables for a new round
        win_mult = 1;
        dealer_bust = 0;
        loss_id = 0;
        ans = 1;
        blackjack1 = 0;
        blackjack2 = 0;
        charlie = 0;

        // Get user bet
        printf("You may bet any integer dollar amount that you have remaining.\n");
        sleep(1);
        printf("How much would you like to bet?: ");
        sleep(1);
        scanf("%d", &bet);

        // Validate user bet
        while ((bet > mon) && (bet <= 0)) { // no over betting
            printf("Sorry, invalid bet.\n");
            sleep(1);
            printf("Please enter a valid bet: ");
            scanf("%d", &bet);
            sleep(1);
        }

        printf("You bet $%d\n", bet);
        sleep(1);
        mon = mon - bet;
        printf("You have $%.2f left.\n", mon);
        sleep(1);

        // Display Dealer's Cards
        printf("\nDealers Cards are: \n");
        sleep(2);
        Card random_card6 = generateRandomCard();
        displayCardInfo(random_card6); // Dealer card 1
        sleep(1);
        printf("\n");
        flippedCard(); //Dealer Card 2 (hidden)
        sleep(1);

        // Display Player's Cards
        printf("\n\nYour cards are: \n\n");
        sleep(2);
        Card random_card1 = generateRandomCard();
        displayCardInfo(random_card1); //Player Card 1
        sleep(1);
        printf("\n");
        Card random_card2 = generateRandomCard();
        displayCardInfo(random_card2); // Player Card 2
        sleep(1);

        // Calculate player's initial card total
        player_tot = random_card1.card_value + random_card2.card_value;
        if (player_tot == 21) {
            printf("Black Jack!\n");
            win_mult = 1.5;
            blackjack1 = 1;
            ans = 0;
        }

        // Player's Turn
        while (ans == 1) {
            printf("\nYour total card value is: %d\n", player_tot);
            printf("Would you like to hit or stay? (1-Hit, 0-Stay): ");
            scanf("%d", &ans);

            // Player chooses to hit
            if (ans == 1) {
                Card random_card3 = generateRandomCard();
                displayCardInfo(random_card3); //Player Card 3
                player_tot = player_tot + random_card3.card_value; //player card total

                // Check for Ace and adjust if needed
                card1:
                if (player_tot > 21) {
                    if ((random_card1.card_value == 11) || (random_card2.card_value == 11) || (random_card3.card_value == 11)) {
                        player_tot = player_tot - 10;
                        goto card1;
                    }
                    printf("Bust!\n");
                    loss_id = 1;
                    break;
                } else if (player_tot == 21) {
                    printf("21! Congrats!");
                    break;
                } else if (player_tot < 21) {
                    printf("\nYour total card value is: %d\n", player_tot);
                    printf("Would you like to hit or stay? (1-Hit, 0-Stay): ");
                    scanf("%d", &ans);

                    // Player chooses to hit again
                    if (ans == 1) {
                        Card random_card4 = generateRandomCard();
                        displayCardInfo(random_card4); //Player Card 4
                        player_tot = player_tot + random_card4.card_value; //player card total

                        // Check for Ace and adjust if needed
                        card2:
                        if (player_tot > 21) {
                            if ((random_card1.card_value == 11) || (random_card2.card_value == 11) || (random_card3.card_value == 11) || (random_card4.card_value == 11)) {
                                player_tot = player_tot - 10;
                                goto card2;
                            }
                            printf("Bust!\n");
                            loss_id = 1;
                            break;
                        } else if (player_tot == 21) {
                            printf("21! Congrats!");
                            break;
                        } else if (player_tot < 21) {
                            printf("\nYour total card value is: %d\n", player_tot);
                            printf("Would you like to hit or stay? (1-Hit, 0-Stay): ");
                            scanf("%d", &ans);

                            // Player chooses to hit again
                            if (ans == 1) {
                                Card random_card5 = generateRandomCard();
                                displayCardInfo(random_card5); //Player Card 5
                                player_tot = player_tot + random_card5.card_value; //player card total

                                // Check for Ace and adjust if needed
                                card3:
                                if (player_tot > 21) {
                                    if ((random_card1.card_value == 11) || (random_card2.card_value == 11) || (random_card3.card_value == 11) || (random_card4.card_value == 11) || (random_card5.card_value == 11)) {
                                        player_tot = player_tot - 10;
                                        goto card3;
                                    }
                                    printf("Bust!");
                                    loss_id = 1;
                                    break;
                                } else if (player_tot <= 21) {
                                    printf("Holy Moly! Five Finger Charlie punch!\n");
                                    win_mult = 5; // payout increased to 5x
                                    charlie = 1; // win condition for the win logic
                                    break;
                                }
                            } else if (ans == 0) {
                                break;
                            }
                        }
                    } else if (ans == 0) {
                        break;
                    }
                }
            } else if (ans == 0) {
                break;
            }
        }

        // Display final combined player card value
        printf("Your final combined card value is: %d\n", player_tot);
        sleep(2);

        // Dealer's Turn
        printf("\nThe dealers cards: \n\n");
        sleep(1);
        displayCardInfo(random_card6); // Dealer card 1
        sleep(1);
        printf("\nThe dealer flips their face down card: \n");
        sleep(1);
        Card random_card7 = generateRandomCard();
        displayCardInfo(random_card7); // Dealer card 2
        dealer_tot = random_card6.card_value + random_card7.card_value; //dealer card total
        if (dealer_tot == 21) {
            blackjack2 = 1;
        }
        sleep(1);

        // Dealer draws additional cards if needed
        if (dealer_tot < 17) {
            Card random_card8 = generateRandomCard();
            dealer_tot = dealer_tot + random_card8.card_value; //dealer card total
            displayCardInfo(random_card8); // Dealer card 3
            sleep(1);

            // Check for Ace and adjust if needed
            card9:
            if (dealer_tot < 17) {
                Card random_card9 = generateRandomCard();
                dealer_tot = dealer_tot + random_card9.card_value; //dealer card total
                displayCardInfo(random_card9); // Dealer card 4
                sleep(1);

                // Check for Ace and adjust if needed
                card10:
                if (dealer_tot < 17) {
                    Card random_card10 = generateRandomCard();
                    dealer_tot = dealer_tot + random_card10.card_value; //dealer card total
                    displayCardInfo(random_card10); // Dealer card 5
                    sleep(1);
                } else if ((dealer_tot > 21) && ((random_card6.card_value == 11) || (random_card7.card_value == 11) || (random_card8.card_value == 11) || (random_card9.card_value == 11))) {
                    dealer_tot = dealer_tot - 10;
                    goto card10;
                }
            } else if ((dealer_tot > 21) && ((random_card6.card_value == 11) || (random_card7.card_value == 11) || (random_card8.card_value == 11))) {
                dealer_tot = dealer_tot - 10;
                goto card9;
            }
        } else if ((dealer_tot > 21) && ((random_card6.card_value == 11) || (random_card7.card_value == 11))) {
            dealer_tot = dealer_tot - 10;
        }

        // Display final combined dealer card value
        printf("\nThe dealers combined value is: %d\n", dealer_tot);

        // Determine the winner and adjust money
        if (dealer_tot > 21) {
            dealer_bust = 1;
        }

        sleep(1);

        // Win/Loss Conditions
        if (charlie == 1) {
            mon = winCon(mon, win_mult, bet);
        } else if ((blackjack1 == 1) && (blackjack2 == 1)) {
            mon = push(mon, bet);
        } else if ((blackjack1 == 1) && (blackjack2 != 1)) {
            printf("You got Blackjack!!!\n");
            mon = winCon(mon, win_mult, bet);
        } else if ((blackjack2 == 1) && (blackjack1 != 1)) {
            printf("The Dealer got Blackjack!!!\n");
            loseCon(mon);
        } else if (player_tot == dealer_tot) {
            mon = push(mon, bet);
        } else if ((dealer_tot > player_tot) && (dealer_bust != 1)) {
            printf("You lose to the dealer\n");
            loseCon(mon);
        } else if ((dealer_bust == 1) && (loss_id != 1)) {
            printf("Dealer Busts!!\n");
            mon = winCon(mon, win_mult, bet);
        } else if ((loss_id == 1) && (dealer_bust == 1)) {
            loseCon(mon);
        } else if ((loss_id == 1) && (dealer_tot <= 21)) {
            loseCon(mon);
        } else if ((player_tot > dealer_tot) && (loss_id != 1)) {
            mon = winCon(mon, win_mult, bet);
        }

        // Check if player is out of money
        if (mon == 0) {
            printf("You're broke sucker\n");
            break;
        }

        // Ask if the player wants to play again
        printf("Would you like to play again? (1=yes, 0=No) ");
        scanf("%d", &play);
        if (play == 1)
            system("clear");
    }

    // Save game information to a receipt file
    FILE *f1 = fopen("Receipt", "w");
    fprintf(f1, "\n");
    fprintf(f1, "You ended the game with $%.2f \n", mon);
    fprintf(f1, "\n\n");
    fprintf(f1, "Please take this receipt to the cashier to cash out\n");
    fclose(f1);
    printf("Your receipt is in the text file Receipt\n");

    return 0;
}
