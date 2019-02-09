
/*
 unit test card great_hallEffect
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great_hall"

int main()
{
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    // create a copy of the original game state
    memcpy(&testG, &G, sizeof(struct gameState));
    great_hallEffect(&testG, 0);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- TEST 1:  draw card from deck --------------
    printf("TEST 1: -1 cards from deck count\n");
    printf("Expected value: %d, Result: %d\n", G.deckCount[0] - 1, testG.deckCount[0]);

    // ----------- TEST 2:  +1 action --------------
    printf("TEST 2: +1 action\n");
    printf("Expected value: %d, Result: %d\n", G.numActions + 1, testG.numActions);

    // ----------- TEST 3: Discard card --------------
    printf("TEST 3: Discard a card from hand\n");
    printf("Expected value: %d, Result: %d\n", G.handCount[0] - 1, testG.handCount[0]);

    return 0;
}
