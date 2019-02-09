/* -----------------------------------------------------------------------
Unit test for dominion card: smithy
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main()
{
    /* UNIT TEST 1: Smithy */
    // Define game start values
    struct gameState G;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    memset(&G, 23, sizeof(struct gameState));       // Clear the game state
    int r = initializeGame(numPlayer, k, seed, &G); // Initialize new game

#if (NOISY_TEST == 1)
#endif

    return 0;
}