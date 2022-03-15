#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size

    int Start = 0;
    do
    {
        Start = get_int("Start Size: ");
    }
    while (Start < 9);

    // Prompt for end size

    int End = 0;
    do
    {
        End = get_int("End Size: ");
    }
    while (End < Start);

    // Calculate number of years until we reach threshold

    int Years = 0;
    while (Start < End)
    {
        Start = Start + (Start / 3) - (Start / 4);
        Years++;
    }

    // Print number of years

    printf("Years: %i\n", Years);
}