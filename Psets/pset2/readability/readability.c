#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int get_letter(string Text);
int get_word(string Text);
int get_sentences(string Text);
int Grade_level(int number_of_letter, int number_of_word, int number_of_sentences);
void print(int Grade_level);

int main(int argc, string argv[])
{
    string Text = get_string("Enter The Tex: "); // initialization the functions
    int x = get_letter(Text);
    int y = get_word(Text);
    int z = get_sentences(Text);
    int G = Grade_level(x, y, z);

    print(G);
}


int get_letter(string Text) // function for counting letters
{
    int number_of_letter = 0;
    for (int i = 0; i < strlen(Text); i++)
    {
        if (isalpha(Text[i])) // the condition for counting the letters
        {
            number_of_letter += 1;
        }
    }
    return number_of_letter;
}

int get_word(string Text) // function for counting words
{
    int number_of_word = 0;
    for (int j = 0; j < strlen(Text); j++)
    {
        if (Text[j] == ' ') // the condition for counting the words
        {
            number_of_word += 1;
        }
    }
    return number_of_word + 1;

}

int get_sentences(string Text) // function for counting sentences
{
    int number_of_sentences = 0;
    for (int k = 0; k < strlen(Text); k++)
    {
        if (Text[k] == '.' || Text[k] == '!' || Text[k] == '?') // the condition for counting the sentences
        {
            number_of_sentences += 1;
        }
    }
    return number_of_sentences;

}

int Grade_level(int number_of_letter, int number_of_word, int number_of_sentences) // function for select the right grade
{
    float L = (number_of_letter / (float)number_of_word) * 100;
    float S = (number_of_sentences / (float)number_of_word) * 100;

    return round(0.0588 * L - 0.296 * S - 15.8);
}

void print(int Grade_level) // function for printing the grade
{
    if (Grade_level <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (Grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", Grade_level);
    }
}