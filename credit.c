#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <cs50.h>

int main(void)
{
    char card[20];
    char *ptr;
    long card2;
    int length;

    printf("Number : ");
    scanf("%s", &card);
    
    card2 = strtol(card, &ptr, 10);

    //printf("%ld\n", card2);

    for (length = 0; card2 > 0; length++)
    {
        card2 /= 10;
    }

    //printf("%i\n", length);

    int multip = 0;
    int rest = 0;
    int sum = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            multip = (card[i] - 48) * 2;

            if (multip >= 10)
            {
                rest = (multip % 10) + 1;
                sum += rest;
            }
            else
            {
                sum += multip;
            }
            
        }
        else
        {
            sum += (card[i] - 48);
        }
        //printf("Somme0 : %i\n", sum);
        
    }

    bool valid;

    if (sum % 10 == 0)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }

    if (valid == 1 && card[0] == 52)
    {
        printf("VISA\n");
    }
    
    
    
    
    //printf("Somme : %i\n", sum);

}