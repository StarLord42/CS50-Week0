#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height, i, j, k, l, m;

    do
    {
        height = get_int("Height : ");
    }
    while (height < 1 || height > 8);   // while height < 1 or height > 8, prompt for height

    for (i = 0; i < height; i++)    // row of the pyramid
    {
        for (j = 0; j < height - i - 1; j++)
        {
            printf(" ");    //space for the left pyramid
        }

        for (k = 0; k < i + 1; k++)
        {
            printf("#");    // hash of the first pyramid
        }

        //for (l = 0; l < 2; l++) // the gap
        {
            //printf(" ");
        }

        //for (m = 0; m <= i; m++)    // hash of the second pyramid
        {
            //printf("#");
        }

        printf("\n");
    }
}
