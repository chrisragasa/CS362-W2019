/* -----------------------------------------------------------------------
 Unit test for the supplyCount() function
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
    printf("TESTING supplyCount()...\n");
    // Test 1 - feast (count 0)
    struct gameState G1;
    struct gameState *G1_ptr = &G1;
    G1_ptr->supplyCount[feast] = 0;
    int t1 = supplyCount(feast, G1_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 1: Test supplyCount(), feast (0 count) \n");
    printf("supplyCount() = %d, Expected = %d\n", t1, 0);
#endif
    printTestResult(t1, 0);
    //assert(t1 == 0);

    // Test 2 - feast (count 1)
    struct gameState G2;
    struct gameState *G2_ptr = &G2;
    G2_ptr->supplyCount[feast] = 1;
    int t2 = supplyCount(feast, G2_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 2: Test supplyCount(), feast (1 count) \n");
    printf("supplyCount() = %d, Expected = %d\n", t2, 1);
#endif
    printTestResult(t2, 1);
    //assert(t2 == 1);

    // Test 3 - feast (count -1)
    struct gameState G3;
    struct gameState *G3_ptr = &G3;
    G3_ptr->supplyCount[feast] = -1;
    int t3 = supplyCount(feast, G3_ptr);
#if (NOISY_TEST == 1)
    printf("TEST 3: Test supplyCount(), feast (-1 count) \n");
    printf("supplyCount() = %d, Expected = %d\n", t3, -1);
#endif
    printTestResult(t3, -1);
    //assert(t3 == -1);

    return 0;
}