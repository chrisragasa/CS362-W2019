
/*
 unit test for card effect adventurer
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

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

    memcpy(&testG, &G, sizeof(struct gameState));

    // add treasure to first 2 cards of user 0's deck
    testG.deck[0][0] = copper;
    testG.deck[0][1] = copper;

    // make first card in hand adventurer
    testG.hand[0][0] = adventurer;

    adventurerEffect(&testG);

    // ----------- TEST 1: Increase in cards to hand count --------------
    printf("TEST 1: +2 cards to hand count\n");
    printf("Expected value: %d, Result: %d\n", G.handCount[0] + 2, testG.handCount[0]);

    // ----------- TEST 2: Decrease in cards to the deck--------------
    printf("TEST 2: -2 cards to deck\n");
    printf("Expected value: %d, Result: %d\n", G.deckCount[0] - 2, testG.deckCount[0]);

    // ----------- TEST 3: Check that the user drew treasure cards --------------
    printf("TEST 3: Check that the user drew treasure cards\n");
    int treasureCards = 0;
    // Cycle through the users deck to check that at least 2 cards are copper
    for (int i = 0; i < testG.deckCount[0]; i++)
    {
        if (testG.deck[0][i] == copper)
        {
            treasureCards++;
        }
    }
    printf("Expected value: %d, Result: %d\n", 2, treasureCards);

    return 0;
}
