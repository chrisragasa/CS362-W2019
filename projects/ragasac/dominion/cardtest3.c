
/*
 unit test card outpost
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "outpost"

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
    // create a copy of the original game state
    memcpy(&testG, &G, sizeof(struct gameState));

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    outpostEffect(&testG, 0);

    // ----------- TEST 1: Modify outpost flag --------------
    printf("TEST 1: outpost flag is set\n");
    printf("Expected value: %d, Result: %d\n", G.outpostPlayed + 1, testG.outpostPlayed);
    printTestResult(G.outpostPlayed + 1, testG.outpostPlayed);

    // ----------- TEST 2: Discard card --------------
    printf("TEST 2: Discard a card from hand\n");
    printf("Expected value: %d, Result: %d\n", G.handCount[0] - 1, testG.handCount[0]);
    printTestResult(G.handCount[0] - 1, testG.handCount[0]);

    return 0;
}
