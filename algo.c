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
   
}