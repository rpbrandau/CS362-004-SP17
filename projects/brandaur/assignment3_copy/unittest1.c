/*
Riley Brandau
CS 362 - Assignment 3 - Unit Tests
Due 4/30/17

UNIT TEST 1 - int fullDeckCount(int player, int card, struct gameState *state)
*/

/*
Requirements of fullDeckCount()
1: Return the total of a specific card in a player's deck (hand+discard+deck)
2: Should return an integer
3: Start of game should return 3 estates
4: Start of game should return 7 copper
5: Start of game: hand = 5, deck = 5, discard = 0
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define FUNCTIONTEST "fullDeckCount()"


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
	int p_count = 0;
	int f_count = 0;
	int player1 = 0;
	int player2 = 1;
	int cardCount = 0;
	int totalCardsP1 = 0;
	int totalCardsP2 = 0;
	int estateCount = 0;
	int copperCount = 0;
	
	
	printf("TESTING FUNCTION: %s\n", FUNCTIONTEST);
	memset(&G, 0, sizeof(struct gameState)); // clear game state
	r = initializeGame(numPlayer, kingdomCards, seed, &G); //initialize a new game
	
	//Test 1a: Player 1, handCount
	cardCount = G.handCount[player1];
	printf("Player: %d. Hand Size: %d. Expected: 5\n", player1, cardCount );
	totalCardsP1 += cardCount;
	if(G.handCount[player1] == 5)
	{
		printf("Test 1a: PASS\n");
		p_count++;
	}
	else{printf("Test 1a: FAIL\n"); f_count++;}
	
	//Test 1b: Player 2, handCount
	cardCount = G.handCount[player2];
	printf("Player: %d. Hand Size: %d. Expected: 5\n", player2, cardCount );
	totalCardsP2 += cardCount;
	if(G.handCount[player2] == 5)
	{
		printf("Test 1b: PASS\n");
		p_count++;
	}
	else{printf("Test 1b: FAIL\n"); f_count++;}
	
	//Test 2a: Player 1, deckCount
	cardCount = G.deckCount[player1];
	printf("Player: %d. Deck Size: %d. Expected: 5\n", player1, cardCount );
	totalCardsP1 += cardCount;
	if(G.deckCount[player1] == 5)
	{
		printf("Test 2a: PASS\n");
		p_count++;
	}
	else{printf("Test 2a: FAIL\n"); f_count++;}	
	
	//Test 2b: Player 2, deckCount
	cardCount = G.deckCount[player2];
	printf("Player: %d. Deck Size: %d. Expected: 5\n", player2, cardCount );
	totalCardsP2 += cardCount;
	if(G.deckCount[player2] == 5)
	{
		printf("Test 2b: PASS\n");
		p_count++;
	}
	else{printf("Test 2b: FAIL\n"); f_count++;}	
	
	//Test 3a: Player 1, discardCount
	cardCount = G.discardCount[player1];
	printf("Player: %d. Discard Size: %d. Expected: 0\n", player1, cardCount );
	totalCardsP1 += cardCount;
	if(G.discardCount[player1] == 0)
	{
		printf("Test 3a: PASS\n");
		p_count++;
	}
	else{printf("Test 3a: FAIL\n"); f_count++;}	
	
	//Test 3b: Player 2, discardCount
	cardCount = G.discardCount[player2];
	printf("Player: %d. Discard Size: %d. Expected: 0\n", player2, cardCount );
	totalCardsP2 += cardCount;
	if(G.discardCount[player2] == 0)
	{
		printf("Test 3b: PASS\n");
		p_count++;
	}
	else{printf("Test 3b: FAIL\n"); f_count++;}	
	
	//Test 4a: Player 1, total card count
	printf("Player: %d. Total Cards: %d. Expected: 10\n", player1, totalCardsP1);
	if(totalCardsP1 == 10)
	{
		printf("Test 4a: PASS\n");
		p_count++;
	}
	else{printf("Test 4a: FAIL\n"); f_count++;}
	
	//Test 4b: Player 2, total card count
	printf("Player: %d. Total Cards: %d. Expected: 10\n", player2, totalCardsP2);
	if(totalCardsP2 == 10)
	{
		printf("Test 4a: PASS\n");
		p_count++;
	}
	else{printf("Test 4a: FAIL\n"); f_count++;}
	
	//Test 5a: Player 1 has 3 estates
	estateCount = fullDeckCount(player1, estate, &G);
	printf("Player: %d. Estates: %d. Expected: 3\n", player1, estateCount);
	if(estateCount == 3)
	{
		printf("Test 5a: PASS\n");
		p_count++;
	}
	else{printf("Test 5a: FAIL\n"); f_count++;}
	
	//Test 5b: Player 2 has 3 estates
	estateCount = fullDeckCount(player2, estate, &G);
	printf("Player: %d. Estates: %d. Expected: 3\n", player2, estateCount);	
	if(estateCount == 3)
	{
		printf("Test 5b: PASS\n");
		p_count++;
	}
	else{printf("Test 5b: FAIL\n"); f_count++;}
	
	//Test 6a: Player 1 has 7 coppers
	copperCount = fullDeckCount(player1, copper, &G);
	printf("Player: %d. Coppers: %d. Expected: 7\n", player1, copperCount);
	if(copperCount == 7)
	{
		printf("Test 6a: PASS\n");
		p_count++;
	}
	else{printf("Test 6a: FAIL\n"); f_count++;}
	
	//Test 6b: Player 2 has 7 coppers
	copperCount = fullDeckCount(player2, copper, &G);
	printf("Player: %d. Coppers: %d. Expected: 7\n", player2, copperCount);
	if(copperCount == 7)
	{
		printf("Test 6b: PASS\n");
		p_count++;
	}
	else{printf("Test 6b: FAIL\n"); f_count++;}

	
	printf("Tests passesed: %d\nTests failed: %d\n", p_count, f_count);
	printf("TESTING of %s COMPLETED\n", FUNCTIONTEST);
}











