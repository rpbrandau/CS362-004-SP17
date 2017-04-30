/*
Riley Brandau
CS 362 - Assignment 3 - Unit Tests
Due 4/30/17

UNIT TEST 3 - whoseTurn(struct gameState *state)
*/

/*
Requirements of whoseTurn()
1: Return who's turn it is
2: Should return an integer
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONTEST "whoseTurn()"


int main() 
{
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
	int cardCount = 0;
	int totalCards = 0;
	int turn = -5;
	int p_count = 0;
	int f_count = 0;
	
	printf("TESTING FUNCTION: %s\n", FUNCTIONTEST);
	memset(&G, 0, sizeof(struct gameState)); // clear game state
	r = initializeGame(numPlayer, kingdomCards, seed, &G); //initialize a new game
	
	//Testing each player's turn. Start of game should = 0.
	for(p = 0; p < numPlayer; p++)
	{
		turn = whoseTurn(&G); //should return current player's turn
		printf("It is Player: %d's turn. Expected: %d\n", p, turn);
		if(turn == p)
		{
			printf("Test %d: PASS\n", turn);
			p_count++;
		}
		else{printf("Test %d: FAIL\n", turn); f_count++;}
		endTurn(&G); //should change turn to next player
	}

	
	
	
	printf("Tests passesed: %d\nTests failed: %d\n", p_count, f_count);
	printf("TESTING of %s COMPLETED\n", FUNCTIONTEST);
}
