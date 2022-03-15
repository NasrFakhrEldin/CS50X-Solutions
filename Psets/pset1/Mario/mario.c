#include<stdio.h>
#include<cs50.h>


int Print(void);
int main(void)
{
    int x = Print(); //initialization function
    for (int i = 0; i < x; i++)  // for loops specifying number of spaces and hashes per line
    {
        for (int j = 0; j < x; j++)
        {
            if (i + j < x - 1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
int Print(void) //start the function
{
    int H;

    // prompts user for pyramid height between 1 and 8
    do
    {
        H = get_int("Enter The Hieght Between 1 AND 8 : ");
    }
    while (H <= 0 || H > 8); //make the hieght between 1 and 8
    return H;
}