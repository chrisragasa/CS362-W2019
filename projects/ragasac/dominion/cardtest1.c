
/*
unit test for card effect smithy
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int printTestResult(int a, int b)
{
    if (a == b)
    {
        printf("Test Passed!\n");
    }
    else
    {
        printf("Test Failed!\n");
    }
}

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

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    smithyEffect(&testG, 0);

    // ----------- TEST 1: +3 cards to hand count --------------
    printf("TEST 1: +3 cards to hand count\n");
    printf("Expected value: %d, Result: %d\n", G.handCount[G.whoseTurn] + 3, testG.handCount[testG.whoseTurn]);
    printTestResult(G.handCount[G.whoseTurn] + 3, testG.handCount[testG.whoseTurn]);

    // ----------- TEST 2: -3 cards to the deck--------------
    printf("TEST 1: -3 cards to deck\n");
    printf("Expected value: %d, Result: %d\n", G.deckCount[G.whoseTurn] - 3, testG.deckCount[testG.whoseTurn]);
    printTestResult(G.deckCount[G.whoseTurn] - 3, testG.deckCount[testG.whoseTurn]);

    return 0;
}
