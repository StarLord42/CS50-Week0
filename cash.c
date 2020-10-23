#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float change;
    int cents;

    do
    {
        change = get_float("Change owed: ");    // Asking for a non-negative change
    }
    while (change <= 0);

    cents = round(change * 100);    // Round cents to pennys

    int count = 0;

    while (cents !=  0)
    {
        while (cents >= 25)     // Count how many 0.25$ coin are needed
        {
            cents -= 25;
            count += 1;

        }

        while (cents >= 10)     // Count how many 0.10$ coin are needed
        {
            cents -= 10;
            count += 1;
        }

        while (cents >= 5)     // Count how many 0.05$ coin are needed
        {
            cents -= 5;
            count += 1;
        }

        while (cents >= 1)     // Count how many 0.01$ coin are needed
        {
            cents -= 1;
            count += 1;
        }
    }

    printf("%i\n", count);  // Print all the coins are needed to the change

}