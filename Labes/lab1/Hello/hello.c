#include<stdio.h>
#include<cs50.h>

int main(void)
{
    string Name = get_string("What Is Your Name ? "); //getting user input
    printf("Hello, %s\n", Name); //Greating the user by his name
}