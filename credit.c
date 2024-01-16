#include <cs50.h>
#include <stdio.h>

// function for checkSum of card number
long checkSum(long n)
{
    long currentNum = n;

    // find length of number
    int numLength = 0;
    while (currentNum != 0)
    {
        numLength += 1;
        currentNum /= 10;
    }

    // reset currentNum to original card number
    currentNum = n;

    // find sum of every second number, doubled, starting from second to last
    int sum = 0;
    int newDigitDoubled = 0;
    for (int i = numLength; i >= 0; i -= 2)
    {
        newDigitDoubled = (currentNum / 10 % 10) * 2;
        sum += newDigitDoubled % 10 + (newDigitDoubled / 10) % 10;
        currentNum /= 100;
    }

    // reset currentNum to original card number
    currentNum = n;

    // add sum of every second number, starting from the last
    int currentOddDigit = 0;
    for (int i = numLength; i >= 0; i -= 2)
    {
        currentOddDigit = currentNum % 10;
        sum += currentOddDigit;
        currentNum /= 100;
    }
    return (sum % 10);
}

int main(void)
{
    long cardNum = get_long("Card number: \n");
    long newNum = cardNum;
    int numLength = 0;

    for (int i = 0; newNum != i;)
    {
        numLength += 1;
        newNum /= 10;
    }

    string cardType = "";

    if (numLength != 13 && numLength != 14 && numLength != 16)
    {
        cardType = "INVALID";
    }

    if (checkSum(cardNum) == 0)
    {
        if (numLength == 15 && cardNum / 100000000000000 % 10 == 3 &&
            (cardNum / 10000000000000 % 10 == 4 || cardNum / 10000000000000 % 10 == 7))
        {
            cardType = "AMEX";
        }
        else if (numLength == 16 && cardNum / 1000000000000000 % 10 == 5 &&
                 (cardNum / 100000000000000 % 10 >= 1 && cardNum / 100000000000000 % 10 <= 5))
        {
            cardType = "MASTERCARD";
        }
        else if (numLength == 13 && cardNum / 1000000000000 % 10 == 4)
        {
            cardType = "VISA";
        }
        else if (numLength == 16 && cardNum / 1000000000000000 % 10 == 4)
        {
            cardType = "VISA";
        }
        else
        {
            cardType = "INVALID";
        }
    }
    else
    {
        cardType = "INVALID";
    }

    printf("%s\n", cardType);
}