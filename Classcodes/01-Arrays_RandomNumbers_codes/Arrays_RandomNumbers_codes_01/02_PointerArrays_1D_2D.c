/* C code to deal with 1D/2D dynamic arrays */
/* The elements are random numbers - using rand() defined in stdlib */
/* rand() generates uniform number between 0 and RAND_MAX (inclusive) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_bound();

int main(void)
{
    /* -------------------------------------------------------------- */
    /* Dynamic 1D array to store 12 numbers */
    int *ptr_1D = NULL;

    ptr_1D = (int *)malloc(12 * sizeof(int));

    for (int i = 0; i < 12; i++)
    {
        ptr_1D[i] = rand_bound();
    }

    printf("ptr_1D: ");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", ptr_1D[i]);
    }
    printf("\n");
    /* -------------------------------------------------------------- */

    /* Dynamic 2D array; 3 x 4; random elements */

    int **ptr_2D = NULL;

    ptr_2D = (int **)malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; i++)
    {
        ptr_2D[i] = (int *)malloc(4 * sizeof(int));
    }

    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 4; c++)
        {
            ptr_2D[r][c] = rand_bound();
        }

    printf("ptr_2D:\n");
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            printf("%3d ", ptr_2D[r][c]);
        }
        printf("\n");
    }

    /* -------------------------------------------------------------- */
    /* Free the memory */

    free(ptr_1D);

    for (int i = 0; i < 3; i++)
        free(ptr_2D[i]);

    free(ptr_2D);

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