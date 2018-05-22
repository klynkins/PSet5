// Implements a dictionary's functionality

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"

// define a node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
node *hashtable[26];

int wordcount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hash = hash_function(word);
    if(hashtable[hash] == NULL)
    {
        return false;
    }

    else if(hashtable[hash] != NULL)
    {
        node *cursor = hashtable[hash];

        while(cursor != NULL)
        {
            int i;
            i = strcasecmp(cursor->word, word);
            if(i == 0)
            {
                return true;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
// for every word we scan we want to malloc a node for it
// whenever we create a node we want ot check did malloc succed
// make sure pointer to that node doesn't return null
bool load(const char *dictionary)
{
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", file);
        return 2;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        memset(new_node, 0, sizeof(node));
        if(new_node == NULL)
        {
            unload();
            return false;
        }

        wordcount++;
        strcpy(new_node->word, word);
        int hashed = hash_function(word);

        if(hashtable[hashed] == NULL)
            {
            hashtable[hased] = new_node;
            }
            else
            {
                new_node->next = hashtable[hashed];
                hashtable[hashed] = new_node;
                head = new_node;
            }
    }
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
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
    return true;
}
