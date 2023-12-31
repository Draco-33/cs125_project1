#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include "structure.h"


#define RED "\x1b[31m"
#define GREY "\x1b[90m"
#define BLACK "\x1b[0m"
#define HEARTS "\u2665"
#define DIAMONDS "\u2666"
#define CLUBS "\u2663"
#define SPADES "\u2660"



Card generateRandomCard() ;
void displayCardInfo(Card card);
void flippedCard();
float winCon(float mon,float win_mult, int bet);
float loseCon(float mon);
float push(float mon, int bet);
