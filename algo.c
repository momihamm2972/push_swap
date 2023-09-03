#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix [3][12] = {{0,4,12,2,10,6,9,13,3,11,7,15},{1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0}};
    int i;
    int j;

    i = 1;
    j = 0;
    while (i <= 12)
    {
        if (matrix[0][j] < matrix[0][i])
        {
            if (matrix [1][i] <= matrix [1][j] + 1)
            {
                matrix[1][i] = matrix[1][j] + 1;
                if (matrix[2][j] <= j)
                    matrix[2][i] = j;
            }
        }
        j++;
        if (j == i)
        {
            j = 0;
            i++;
        }
    }
    i = 0;
    while (i < 12)
    {
        printf ("|%d|\t",matrix[0][i]);
        i++;
    }
    printf ("\n");
    i = 0;
    while (i < 12)
    {
        printf ("<%d>\t",matrix[1][i]);
        i++;
    }
    printf ("\n");
    i = 0;
    while (i < 12)
    {
        printf (">%d<\t",matrix[2][i]);
        i++;
    }
    i = 0;
    int m=0;
    while (i < 12)
    {
        if (matrix[1][i] > m)
            m = matrix[1][i];
        i++;
    }
    printf ("\nTHE LIS : %d\n",m);
    i = 11;
    int n =m;
    int *lis = calloc (m, sizeof (int));
    while (i >= 0)
    {
        if (matrix[1][i] == n)
        {
            lis[n - 1] = matrix[0][i];
            n--;
        }
        i--;
    }
    i = 0;
    while (i < 6)
    {
        printf ("!%d!\t",lis[i]);
        i++;
    }
    free (lis);
}