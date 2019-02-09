/* -----------------------------------------------------------------------
 Unit test for the isGameOver() function
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
    printf("TESTING isGameOver()...\n");

    // Test 1 - no province cards
    struct gameState G1;
    struct gameState *G1_ptr = &G1;
    G1_ptr->supplyCount[province] = 0;
    int t1 = isGameOver(G1_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 1: Testing no province cards \n");
    printf("isGameOver() = %d, Expected = %d\n", t1, 1);
#endif
    assert(t1 == 1);

    // Test 2 - some province cards
    struct gameState G2;
    struct gameState *G2_ptr = &G2;
    for (int i = 0; i < 25; i++)
    {
        G2_ptr->supplyCount[i] = 1;
    }
    G2_ptr->supplyCount[province] = 1;
    int t2 = isGameOver(G2_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 2: Testing some province cards \n");
    printf("isGameOver() = %d, Expected = %d\n", t2, 0);
#endif
    assert(t2 == 0);

    // Test 3 - no supply counts are at 0
    struct gameState G3;
    struct gameState *G3_ptr = &G3;
    for (int i = 0; i < 25; i++)
    {
        G3_ptr->supplyCount[i] = 1;
    }
    int t3 = isGameOver(G3_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 3: Testing no supply counts are at 0 \n");
    printf("isGameOver() = %d, Expected = %d\n", t3, 0);
#endif
    assert(t3 == 0);

    // Test 4 - no province count, but all supply counts are 0
    struct gameState G4;
    struct gameState *G4_ptr = &G4;
    G4_ptr->supplyCount[province] = 1;
    for (int i = 0; i < 25; i++)
    {
        G3_ptr->supplyCount[i] = 0;
    }
    int t4 = isGameOver(G4_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 4: Testing no province count, but all supply counts are 0 \n");
    printf("isGameOver() = %d, Expected = %d\n", t4, 1);
#endif
    assert(t4 == 1);

    printf("All tests passed!\n");
    return 0;
}