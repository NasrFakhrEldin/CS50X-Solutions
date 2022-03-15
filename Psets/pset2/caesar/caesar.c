#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>



int main(int argc, string argv[])
{
    if (argc != 2) //only two input
    {
        printf("Use: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++) //make the second input be a number
    {
        if (isalpha(argv[1][i]))
        {
            printf("Use: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]) % 26; //converts a string "key" into a number and if "key" > 26 store the division remainder instead
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int j = 0; j < strlen(plaintext); j++) //check if the palintext is not alphabet
    {
        if (!isalpha(plaintext[j]))
        {
            printf("%c", plaintext[j]);
            continue;
        }
        int ascii = isupper(plaintext[j]) ? 'A' : 'a';
        int pi = plaintext[j] - ascii;
        int ci = (pi + key) % 26;

        printf("%c", ci + ascii);
    }
    printf("\n");
    return 0;
}