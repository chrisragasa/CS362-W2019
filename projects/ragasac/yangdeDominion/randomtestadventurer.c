
/*
 random test for adventurer card
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
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    int deckSize, discardSize, randHandCount, treasurePos1, treasurePos2;

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // Print test type
    printf("Performing random tests for Adventurer Card...\n");

    // perform random tests
    while (currTest < numTests)
    {
        // copy the blank game state into the test game state
        memcpy(&testG, &G, sizeof(struct gameState));

        // create random characteristics of the test game state
        deckSize = rand() % (MAX_DECK);
        discardSize = rand() % (MAX_DECK);
        randHandCount = rand() % (MAX_HAND);
        treasurePos1 = rand() % (deckSize);
        treasurePos2 = rand() % (deckSize);

        // set the characteristics to the game state
        testG.deckCount[0] = deckSize;
        testG.discardCount[0] = discardSize;
        testG.handCount[0] = randHandCount;
        testG.deck[0][treasurePos1] = copper;
        testG.deck[0][treasurePos2] = copper;

        // call the adventurer card
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        printf("TEST: +2 cards to hand count (%d)\n", currTest);
        printf("Expected value: %d, Result: %d\n", randHandCount, testG.handCount[0]);
        printTestResult(randHandCount + 2, testG.handCount[0]);

        currTest++;
    }
    return 0;
}
