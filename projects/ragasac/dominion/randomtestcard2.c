
/*
 random test for great_hall card
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

void printTestResult(int a, int b)
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

    int currTest = 0;
    int numTests = 50;
    int handpos = 0;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    int deckSize, discardSize, randHandCount;

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // Print test type
    printf("Performing random tests for Great Hall Card...\n");

    // perform random tests
    while (currTest < numTests)
    {
        // copy the blank game state into the test game state
        memcpy(&testG, &G, sizeof(struct gameState));

        // create random characteristics of the test game state
        deckSize = rand() % (MAX_DECK);
        discardSize = rand() % (MAX_DECK);
        randHandCount = rand() % (MAX_HAND);

        // set the characteristics to the game state
        testG.deckCount[0] = deckSize;
        testG.discardCount[0] = discardSize;
        testG.handCount[0] = randHandCount;

        // call the smithy card
        smithyEffect(&testG, handpos);

        // ----------- TEST 1: +3 cards to hand count --------------
        printf("TEST 1 (%d): +3 cards to hand count (before discard)\n", currTest);
        printf("Expected value: %d, Result: %d\n", randHandCount + 2, testG.handCount[testG.whoseTurn]);
        printTestResult(randHandCount + 2, testG.handCount[testG.whoseTurn]);

        // ----------- TEST 2: -3 cards to the deck--------------
        printf("TEST 2 (%d): -3 cards to deck\n", currTest);
        printf("Expected value: %d, Result: %d\n", deckSize - 3, testG.deckCount[testG.whoseTurn]);
        printTestResult(deckSize - 3, testG.deckCount[testG.whoseTurn]);

        currTest++;
    }
    return 0;
}
