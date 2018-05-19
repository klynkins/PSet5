// Implements a dictionary's functionality

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
node *hashtable[27];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    return false

    while (fscanf(file, "%s", word) != EOF)
{
// for every word we scan we want to malloc a node for it
//whenever we create a node we want ot check did malloc succed
//make sure pointer to that node doesn't return null

    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
    unload();
    return false;
    }
    else
    {
    strcpy(new_node->word, word);
    }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    while(cursor != NULL)
    {
    node *temp = cursor;
    cursor = cursor->next;
    free(temp);
    cursor = next;
    }
    // TODO
    return false;
}
