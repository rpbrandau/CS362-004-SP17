/*
Riley Brandau
CS 362 - Assignment 3 - Unit Tests
Due 4/30/17

UNIT TEST 4 - numHandCards(struct gameState *state)
*/

/*
Requirements of numHandCards()
1: Return the number of cards in the current player's hand
2: Should return an integer
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONTEST "numHandCards()"


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
	int p_count = 0;
	int f_count = 0;
	int handSize = 5;
	int testCount = 1;
	int deckSize = 5;
	
	printf("TESTING FUNCTION: %s\n", FUNCTIONTEST);
	memset(&G, 0, sizeof(struct gameState)); // clear game state
	r = initializeGame(numPlayer, kingdomCards, seed, &G); //initialize a new game
	
	for(p = 0; p < numPlayer; p++)
	{
		//Testing hand size
		cardCount = numHandCards(&G);
		printf("Player: %d. Hand Size: %d. Expected: %d\n", p, cardCount, handSize);
		if(numHandCards(&G) == handSize)
		{
			printf("Test %d: PASS\n", testCount);
			p_count++;
			testCount++;
		}
		else{printf("Test %d: FAIL\n", testCount); f_count++; testCount++;}
		
		//Testing deck size
		cardCount = G.deckCount[p];
		printf("Player: %d. Deck Size: %d. Expected: %d\n", p, cardCount, deckSize);
		if(G.deckCount[p] == deckSize)
		{
			printf("Test %d: PASS\n", testCount);
			p_count++;
			testCount++;
		}
		else{printf("Test %d: FAIL\n", testCount); f_count++; testCount++;}
		
		//Testing discard size
		cardCount = G.discardCount[p];
		printf("Player: %d. Discard Size: %d. Expected: %d\n", p, cardCount, 0);
		if(G.discardCount[p] == 0)
		{
			printf("Test %d: PASS\n", testCount);
			p_count++;
			testCount++;
		}
		else{printf("Test %d: FAIL\n", testCount); f_count++; testCount++;}		
		
		//Draw a card
		printf("Drawing a card...\n");
		drawCard(p, &G);
	        handSize++;
		deckSize--;
		
    	//Testing hand size
		cardCount = numHandCards(&G);
		printf("Player: %d. Hand Size: %d. Expected: %d\n", p, cardCount, handSize);
		if(numHandCards(&G) == handSize)
		{
			printf("Test %d: PASS\n", testCount);
			p_count++;
			testCount++;
		}
		else{printf("Test %d: FAIL\n", testCount); f_count++; testCount++;}
		
		//Testing deck size
		cardCount = G.deckCount[p];
		printf("Player: %d. Deck Size: %d. Expected: %d\n", p, cardCount, deckSize);
		if(G.deckCount[p] == deckSize)
		{
			printf("Test %d: PASS\n", testCount);
			p_count++;
			testCount++;
		}
		else{printf("Test %d: FAIL\n", testCount); f_count++; testCount++;}
		
		//Testing discard size
		cardCount = G.discardCount[p];
		printf("Player: %d. Discard Size: %d. Expected: %d\n", p, cardCount, 0);
		if(G.discardCount[p] == 0)
		{
			printf("Test %d: PASS\n", testCount);
			p_count++;
			testCount++;
		}
		else{printf("Test %d: FAIL\n", testCount); f_count++; testCount++;}
		deckSize = 5;
		handSize = 5;			
	}

	printf("Tests passesed: %d\nTests failed: %d\n", p_count, f_count);
	printf("TESTING of %s COMPLETED\n", FUNCTIONTEST);
}























