/*
Riley Brandau
CS 362 - Assignment 3 - Card Tests
Due 4/30/17

CARD TEST 4 - Council Room
*/

/*
Requirements of Council Room
1: Current player draws four cards (implemented)
2: Four cards should come from current player's draw pile (implemented)
3: Current player's hand size should increase (duplicate of 1:)
4: Current player's BUYS should increase by 1 (implemented)
5: Current player's ACTIONS should decrease by 1 (implemented)
6: No state change should occur for other players (not implemented)
7: No state change should occur to victory card or kingdom card piles (victory cards implemented)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "council_room"

int main()
{
	//set up testing environment - credit to cardtest4.c
	int newCards = 0;
	int discarded = 1;
	int xtraCoins = 0;
	int shuffledCards = 0;
	int newBuys = 0;
	int newActions = 0;
	int p_count = 0;
	int f_count = 0;
	
	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	//initialize a game state and player cards
	initializeGame(numPlayers, kingdomCards, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus); 
	newBuys = 1;
	newCards = 4;
	xtraCoins = 0;
	newActions = 0;
	
	//BEGIN TESTS
	printf("--------------TESTING CARD: %s --------------\n", TESTCARD);
	
	//Test 1: hand size increases by 4
	printf("TEST 1: Drawing 4 cards\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)
	{
		printf("TEST 1: PASS\n");
		p_count++;
	}
	else
	{
		printf("TEST 1: FAIL\n");
		f_count++;
	}
	
	//Test 2: current player's draw pile
	printf("TEST 2: Draw Pile State\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	if(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)
	{
		printf("TEST 2: PASS\n");
		p_count++;
	}
	else
	{
		printf("TEST 2: FAIL\n");
		f_count++;
	}

	//Test 3: current player's number of actions
	printf("TEST 3: Player's Actions\n");
	printf("Action count = %d, expected = %d\n", testG.numActions, G.numActions + newActions); //might need to be G.numActions - 1
	if(testG.numActions == G.numActions + newActions)
	{
		printf("TEST 3: PASS\n");
		p_count++;
	}
	else
	{
		printf("TEST 3: FAIL\n");
		f_count++;
	}
	
	//Test 4: current player's number of buys
	printf("TEST 4: Player's Buys\n");
	printf("Buy count = %d, expected = %d\n", testG.numBuys, G.numBuys + newBuys);
	if(testG.numBuys == G.numBuys + newBuys)
	{
		printf("TEST 4: PASS\n");
		p_count++;
	}
	else
	{
		printf("TEST 4: FAIL\n");
		f_count++;
	}
	
	//Test 5: victory card pile states
	printf("TEST 5: Victory card states\n");
	printf("Estate:    %d,   expected: %d\n", testG.supplyCount[estate+1], G.supplyCount[estate+1]);
	printf("Duchy:    %d,   expected: %d\n", testG.supplyCount[duchy+1], G.supplyCount[duchy+1]);
	printf("Province: %d,   expected: %d\n", testG.supplyCount[province+1], G.supplyCount[province+1]);
	int vp = 0;
	if(testG.supplyCount[estate+1] == G.supplyCount[estate+1])
	{
		printf("Estates... check\n");
		vp++;
	}
	if(testG.supplyCount[duchy+1] == G.supplyCount[duchy+1])
	{
		printf("Duchys... check\n");
		vp++;
	}
	if(testG.supplyCount[province+1] == G.supplyCount[province+1])
	{
		printf("Provinces... check\n");
		vp++;
	}
	if(vp == 3)
	{
		printf("TEST 5: PASS\n");
		p_count++;
	}
	else
	{
		printf("TEST 5: FAIL");
		f_count++;
	}
	
	
	printf("\n");
	printf("------------TESTING of %s COMPLETE--------------\n", TESTCARD);
	printf("Tests passed: %d\nTests failed: %d\n", p_count, f_count);
}
