/*
Riley Brandau
CS 362 - Assignment 3 - Unit Tests
Due 4/30/17

UNIT TEST 2 - scoreFor( int player, struct gameState *state)
*/

/*
Requirements of scoreFor()
1: Return the score for a particular player
2: Count the victory cards in hand, discard, and deck
3: Should return an integer
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONTEST "scoreFor()"


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
	int score = 0;
	int p_count = 0;
	int f_count = 0;
	
	printf("TESTING FUNCTION: %s\n", FUNCTIONTEST);
	memset(&G, 0, sizeof(struct gameState)); // clear game state
	r = initializeGame(numPlayer, kingdomCards, seed, &G); //initialize a new game
	
	//Testing each player's score. Start of game should = 3 vp.
	for(p = 0; p < numPlayer; p++)
	{
		score = scoreFor(p, &G);
		printf("Player: %d. Score: %d. Expected: 3\n", p, score);
		if(score == 3)
		{
			printf("Test %d: PASS\n", p);
			p_count++;
		}
		else{printf("Test %d: FAIL\n", p); f_count++;}
	}

	printf("Tests passesed: %d\nTests failed: %d\n", p_count, f_count);
	printf("TESTING of %s COMPLETED\n", FUNCTIONTEST);
}
