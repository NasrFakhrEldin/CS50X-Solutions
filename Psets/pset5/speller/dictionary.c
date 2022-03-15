// Implements a dictionary's functionality

#include <stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<strings.h>
#include<string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;
unsigned int nWords = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor -> word, word) == 0)

        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int L = strlen(word);
    unsigned int hashvalue = 0;
    for (int i = 0; i < L; i++)
    {
        hashvalue += tolower(word[i]);
        hashvalue = hashvalue * tolower(word[i] % N);
    }
    return hashvalue;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }
        strcpy(n -> word, word);
        int index = hash(word);

        if (table[index] == NULL)

        {
            n -> next = NULL;
        }
        else

        {
            n -> next = table[index];
        }

        table[index] = n;
        nWords ++;

    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return nWords;
}

void fnode(node *n)
{
    if (n ->next != NULL)
    {
        fnode(n -> next);
    }
    free(n);
}
// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            fnode(table[i]);
        }
    }
    return true;
}
