/*
Riley Brandau
CS 362 - Assignment 4
Due 5/14/17

RANDOM CARD TEST 3 - Adventurer
*/

/*
Requirements of Adventurer
1: Current player's coins increase (implemented)
2: Cards should come from current player's draw pile (implemented)
3: Current player's hand size should increase by (implemented)
4: Current player's ACTIONS should decrease by 1 (implemented)
5: Current player's BUYS should remain the same (implemented)
6: No state change should occur for other players (not implemented)
7: No state change should occur to victory card or kingdom card piles (implemented for victory cards)
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

/*
void deckCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count);
void handCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count);
void buyCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count);
void actionCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count);
void victPileCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count);
void treasureCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count);
void coinCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count);
*/

int main()
{
	//set up testing environment - credit to cardtest4.c
	struct gameState G, testG;
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
		
	srand(time(NULL)); //seed rand()
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, handPos = 0;
	int p_count = 0;
	int f_count = 0;
	int loopCounter = 0;
	int i = 0;
	int preHandCount = 0, postHandCount = 0;
	int preDeckCount = 0, postDeckCount = 0;
	int preBuyCount = 0, postBuyCount = 0;
	int preActionCount = 0, postActionCount = 0;
	int pre_ECount = 0, pre_DCount = 0, pre_PCount = 0, post_ECount = 0, post_DCount = 0, post_PCount = 0;
	int pre_CCount = 0, pre_SCount = 0, pre_GCount = 0, post_CCount = 0, post_SCount = 0, post_GCount = 0;
	int preCoins = 0, postCoins = 0, difference = 0;
	

	
	printf("--------------TESTING CARD: %s --------------\n", TESTCARD);
	
	//SelectStream(2); //not sure if necessary
	//PutSeed(3);      //not sure if necessary
	
	for(loopCounter = 0; loopCounter < 2000; loopCounter++)
	{
		for(i = 0; i < sizeof(struct gameState); i++) //randomize gameState
		{
			((char*)&G)[i] = floor(Random() * 256);
		}
		int seed = rand() % 10000; //randomize seed
		int numPlayers = rand() % 3 + 2; //randomize players (2 to 4 players)
		initializeGame(numPlayers, kingdomCards, seed, &G); //initialize the game with random players and seed
		G.deckCount[numPlayers] = floor(Random() * MAX_DECK); //give the player a random deck size
		G.discardCount[numPlayers] = floor(Random() * MAX_DECK); //give the player a random discard size
		G.handCount[numPlayers] = floor(Random() * MAX_HAND); //give the player a random hand size
		//int cardPos = rand() % (G.handCount[numPlayers]); //pick a random card position
		//G.hand[numPlayers][cardPos] = adventurer; //give the player an adventurer card. Not sure if needed, since we just call its card effect.
		memcpy(&testG, &G, sizeof(struct gameState)); //copy gamestate into testG. G will be pre-state, testG will be post-state
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
		//******RANDOM TESTS***********
		printf("Beginning random tests...\n");

		printf("Test 1: Hand Check\n");
		//handCheck(loopCounter, &testG, &G, numPlayers, &p_count, &f_count, cardPos);
		postHandCount = testG.handCount[numPlayers];
		preHandCount = G.handCount[numPlayers];
		//printf("Pre: %d --- Post: %d\n", preHandCount, postHandCount);
		//if(testG.handCount[numPlayers] == G.handCount[numPlayers]+3)
		if(postHandCount == preHandCount)
		{
			printf("TEST 1.%d.%d: PASS\n", loopCounter, numPlayers); 
			p_count++;
		}
		else
		{
			printf("Test 1.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		
		printf("Test 2: Deck Check\n");
		//deckCheck(loopCounter, &testG, &G, numPlayers, &p_count, &f_count, cardPos);
		postDeckCount = testG.deckCount[numPlayers];
		preDeckCount = G.deckCount[numPlayers];
		//printf("Pre: %d --- Post: %d\n", preDeckCount, postDeckCount);
		if(postDeckCount == preDeckCount)
		{
			printf("TEST 2.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 2.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		
		printf("Test 3: Buy Check\n");
		//buyCheck(loopCounter, &testG, &G, numPlayers, &p_count, &f_count, cardPos);
		postBuyCount = testG.numBuys;
		preBuyCount = G.numBuys;
		//printf("Pre: %d --- Post: %d\n", preBuyCount, postBuyCount);
		if(postBuyCount == preBuyCount)
		{
			printf("TEST 3.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 3.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		
		printf("Test 4: Action Check\n");
		//actionCheck(loopCounter, &testG, &G, numPlayers, &p_count, &f_count, cardPos);
		postActionCount = testG.numActions;
		preActionCount = G.numActions;
		//printf("Pre: %d --- Post: %d\n", preActionCount, postActionCount);
		if(postActionCount == preActionCount)
		{
			printf("TEST 4.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 4.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		printf("Test 5: Victory Pile Check\n");
		//victPileCheck(loopCounter, &testG, &G, numPlayers, &p_count, &f_count, cardPos);
		pre_ECount = supplyCount(estate, &G);
		pre_DCount = supplyCount(duchy, &G);
		pre_PCount = supplyCount(province, &G);
		post_ECount = supplyCount(estate, &testG);
		post_DCount = supplyCount(duchy, &testG);
		post_PCount = supplyCount(province, &testG);
		if(post_ECount == pre_ECount)
		{
			printf("TEST 5E.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 5E.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		if(post_DCount == pre_DCount)
		{
			printf("TEST 5D.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 5D.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		if(post_PCount == pre_PCount)
		{
			printf("TEST 5P.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 5P.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		printf("Test 6: Treasure Pile Check\n");
		//treasureCheck(loopCounter, &testG, &G, numPlayers, &p_count, &f_count, cardPos);
		pre_CCount = supplyCount(copper, &G);
		pre_SCount = supplyCount(silver, &G);
		pre_GCount = supplyCount(gold, &G);
		post_CCount = supplyCount(copper, &testG);
		post_SCount = supplyCount(silver, &testG);
		post_GCount = supplyCount(gold, &testG);
		if(post_CCount == pre_CCount)
		{
			printf("TEST 6C.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 6C.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		if(post_SCount == pre_SCount)
		{
			printf("TEST 6S.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 6S.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		if(post_GCount == pre_GCount)
		{
			printf("TEST 6G.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 6G.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
		printf("Test 7: Coin Check\n");
		//coinCheck(loopCounter, &testG, &G, numPlayers, &p_count, &f_count, cardPos);
		preCoins = G.coins;
		postCoins = testG.coins;
		difference = postCoins - preCoins;
		if(difference > 1 && difference < 7) //coin range = 2 to 6 (2 copper through 2 gold)
		{
			printf("TEST 7.%d.%d: PASS\n", loopCounter, numPlayers);
			p_count++;
		}
		else
		{
			printf("Test 7.%d.%d: FAIL\n", loopCounter, numPlayers);
			f_count++;
		}
	}
	printf("\n");
	printf("------------TESTING of %s COMPLETE--------------\n", TESTCARD);
	printf("Tests passed: %d\nTests failed: %d\n", p_count, f_count);
	
	return 0;
}

/*	
void handCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count, int handPos)
{
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int preHandCount = 0;
	int postHandCount = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); 
	postHandCount = testG.handCount[player];
	preHandCount = G.handCount[player];
	if(postHandCount == preHandCount)
	{
		printf("TEST 1.%d.%d: PASS", loopCounter, player); 
		p_count++;
	}
	else
	{
		printf("Test 1.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
}


void deckCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count, int handPos)
{
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int preDeckCount = 0;
	int postDeckCount = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); 
	postDeckCount = testG.deckCount[player];
	preDeckCount = G.deckCount[player];
	if(postDeckCount == preDeckCount)
	{
		printf("TEST 2.%d.%d: PASS", loopCounter, player);
		p_count++;
	}
	else
	{
		printf("Test 2.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
}

void buyCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count, int handPos)
{
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int preBuyCount = 0;
	int postBuyCount = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); 
	postBuyCount = testG.numBuys;
	preBuyCount = G.numBuys;
			if(postBuyCount == preBuyCount)
			{
				printf("TEST 4.%d.%d: PASS", loopCounter, player);
				p_count++;
			}
			else
			{
				printf("Test 4.%d.%d: FAIL", loopCounter, player);
				f_count++;
			}
}

void actionCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count, int handPos)
{
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int preActionCount = 0;
	int postActionCount = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); 
	postActionCount = testG.numActions;
	preActionCount = G.numActions;
	if(postActionCount == preActionCount)
	{
		printf("TEST 3.%d.%d: PASS", loopCounter, player);
		p_count++;
	}
	else
	{
		printf("Test 3.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
}

void victPileCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count, int handPos)
{
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int pre_ECount = 0;
	int pre_DCount = 0;
	int pre_PCount = 0;
	int post_ECount = 0;
	int post_DCount = 0;
	int post_PCount = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); 
	pre_ECount = supplyCount(estate, &G);
	pre_DCount = supplyCount(duchy, &G);
	pre_PCount = supplyCount(province, &G);
	post_ECount = supplyCount(estate, &testG);
	post_DCount = supplyCount(duchy, &testG);
	post_PCount = supplyCount(province, &testG);
	if(post_ECount == pre_ECount)
	{
		printf("TEST 5E.%d.%d: PASS", loopCounter, player);
		p_count++;
	}
	else
	{
		printf("Test 5E.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
	if(post_DCount == pre_DCount)
	{
		printf("TEST 5D.%d.%d: PASS", loopCounter, player);
		p_count++;
	}
	else
	{
		printf("Test 5D.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
	if(post_PCount == pre_PCount)
	{
		printf("TEST 5P.%d.%d: PASS", loopCounter, player);
		p_count++;
	}
	else
	{
		printf("Test 5P.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
}

void treasureCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count, int handPos)
{
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int pre_CCount = 0;
	int pre_SCount = 0;
	int pre_GCount = 0;
	int post_CCount = 0;
	int post_SCount = 0;
	int post_GCount = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); 
	pre_CCount = supplyCount(copper, &G);
	pre_SCount = supplyCount(silver, &G);
	pre_GCount = supplyCount(gold, &G);
	post_CCount = supplyCount(copper, &testG);
	post_SCount = supplyCount(silver, &testG);
	post_GCount = supplyCount(gold, &testG);
	if(post_CCount == pre_CCount)
	{
		printf("TEST 6C.%d.%d: PASS", loopCounter, player);
		p_count++;
	}
	else
	{
		printf("Test 6C.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
	if(post_SCount == pre_SCount)
	{
		printf("TEST 6S.%d.%d: PASS", loopCounter, player);
		p_count++;
	}
	else
	{
		printf("Test 6S.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
	if(post_GCount == pre_GCount)
	{
		printf("TEST 6G.%d.%d: PASS", loopCounter, player);
		p_count++;
	}
	else
	{
		printf("Test 6G.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
}

void coinCheck(int loopCounter, struct gameState *testG, struct gameState *G, int player, int *p_count, int *f_count, int handPos)
{
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int preCoins = 0;
	int postCoins = 0;
	int difference = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); 
	preCoins = G.coins;
	postCoins = testG.coins;
	difference = postCoins - preCoins;
	if(difference > 1 && difference < 7) //coin range = 2 to 6 (2 copper through 2 gold)
	{
		printf("TEST 7.%d.%d: PASS", loopCounter, player);
		p_count++;
	}
	else
	{
		printf("Test 7.%d.%d: FAIL", loopCounter, player);
		f_count++;
	}
	
}
*/