/* Random number generation - using rand() defined in stdlib */
/* rand() generates uniform number between 0 and RAND_MAX (inclusive) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_bound();

int main(void)
{
    /* -------------------------------------------------------------- */
    /* Random number basic code */

    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("RAND_MAX: %d\n", RAND_MAX); // ( 2 ^ 32 / 2 )- 1

    printf("%d\n", rand_bound());
    printf("%d\n", rand_bound());

    /* After seeding */
    printf("After seeding\n");
    srand(time(0)); // vs srand(42);

    printf("%d\n", rand());
    printf("%d\n", rand());

    printf("%d\n", rand_bound());
    printf("%d\n", rand_bound());
    /* -------------------------------------------------------------- */

    return 0;
}

int rand_bound()
{
    /* Random number between a lower/upper bound */
    int l_bound = 10;
    int u_bound = 100;

    int width = (u_bound - l_bound) + 1;

    int val = 0;

    val = rand() % width + l_bound;

    return val;
}