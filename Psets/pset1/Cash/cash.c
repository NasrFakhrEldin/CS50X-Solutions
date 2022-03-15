#include<stdio.h>
#include<cs50.h>
#include<math.h>


int main(void)
{
    float Dollars;
    // Get Dollars from user
    do
    {
        Dollars = get_float("Change owed: ");
    }
    // Make Dollars Positive
    while (Dollars < 0);

    int cents = round(Dollars * 100);

    int coins = 0;
    while (cents != 0)
    {
        // 25
        coins = coins + (cents / 25);
        cents = cents % 25;
        // 10
        coins = coins + (cents / 10);
        cents = cents % 10;
        // 5
        coins = coins + (cents / 5);
        cents = cents % 5;
        // 1
        coins = coins + (cents / 1);
        cents = cents % 1;
    }
    printf(" you need at least :%i\n", coins);
}