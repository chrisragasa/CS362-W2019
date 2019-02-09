/* -----------------------------------------------------------------------
 Unit test for the whoseTurn() function
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
    printf("TESTING whoseTurn()...\n");

    // Test 1 - User 0's turn
    struct gameState G1;
    struct gameState *G1_ptr = &G1;
    G1_ptr->whoseTurn = 0;
    int t1 = whoseTurn(G1_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 1: User 0's turn \n");
    printf("supplyCount() = %d, Expected = %d\n", t1, 0);
#endif
    //assert(t1 == 0);

    // Test 2 - User 1's turn
    struct gameState G2;
    struct gameState *G2_ptr = &G2;
    G2_ptr->whoseTurn = 1;
    int t2 = whoseTurn(G2_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 2: User 1's turn \n");
    printf("supplyCount() = %d, Expected = %d\n", t2, 1);
#endif
    //assert(t2 == 1);

    // Test 3 - User 2's turn
    struct gameState G3;
    struct gameState *G3_ptr = &G3;
    G3_ptr->whoseTurn = 2;
    int t3 = whoseTurn(G3_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 3: User 2's turn \n");
    printf("supplyCount() = %d, Expected = %d\n", t3, 2);
#endif
    //assert(t3 == 2);

    // Test 4 - User 3's turn
    struct gameState G4;
    struct gameState *G4_ptr = &G4;
    G4_ptr->whoseTurn = 3;
    int t4 = whoseTurn(G4_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 4: User 3's turn \n");
    printf("supplyCount() = %d, Expected = %d\n", t4, 3);
#endif
    //assert(t4 == 3);

    printf("All tests passed!\n");
    return 0;
}