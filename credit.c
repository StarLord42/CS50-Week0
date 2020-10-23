#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

bool valid(int sum)     // check if the sum is valid
{

    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void longToString(char card2[20], long cardNumber)    // long to string
{
    sprintf(card2, "%ld", cardNumber);
}

int lengthNumber(long cardNumber)   // check the length of the card number
{
    int length;

    for (length = 0; cardNumber > 0; length++)
    {
        cardNumber /= 10;
    }

    return length;
}

int checkSum(int multip, int rest, int length, char card[20])   // checksum of the card number
{
    int sum = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        if ((length - 1) % 2 != 0)
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
        }
        else
        {
            if (i % 2 != 0)
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
        }
    }

    return sum;
}


int main(void)
{
    long cardNumber;
    char card2[20];
    int length;
    int multip = 0, rest = 0;


    do
    {
        cardNumber = get_long("Number : ");     // ask for a valid long card number
    }
    while (cardNumber < 1);

    longToString(card2, cardNumber);    // pass the card number of long to string

    length = lengthNumber(cardNumber);  // check the length of the card number

    int sum = checkSum(multip, rest, length, card2);    // checksum of the card number

    bool validSum = valid(sum);     // check if sum is valid

    if (validSum)
    {
        if (length == 15 && card2[0] == 51 && (card2[1] == 52 || card2[1] == 55))   // AMEX check
        {
            printf("AMEX\n");
        }
        else if (length == 16 && card2[0] == 53 && (49 <= card2[1] && card2[1] <= 53))  // MASTERCARD check
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && card2[0] == 52)  // VISA check
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
