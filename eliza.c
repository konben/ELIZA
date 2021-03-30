/* An simple implementation of ELIZA the computer psychiatrist.
 *
 * Heavily inspired by an implementation published in "Big Computer Games" for the C64.
 * If you wanna look it up you can find it under: https://www.atariarchives.org/bigcomputergames/showpage.php?page=20
 * 
 * Author: Benedict Konhäuser
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "data.h"

#define MESSAGE_MAX_LENGTH 100

/* Replaces the first occurence of substr in str. 
 * Returns NULL if substr does not occur in str, otherwise a new string is returned. */
char *replace_first(char *str, char *substr, char *replacement)
{
    char *occurence = strstr(str, substr);
    if (occurence)
    {
        char *new = (char *) malloc(strlen(str) - strlen(substr) + strlen(replacement) + 1);
        memcpy(new, str, strlen(str) - strlen(occurence));
        strcat(new, replacement);
        strcat(new, occurence + strlen(substr));
        return new;
    }
    return NULL;
}

/* Conjugates the pronouns in a string. */
char *conjugate_pronouns(char *msg)
{
    char *buffer = malloc(MESSAGE_MAX_LENGTH);
    strcpy(buffer, msg);
    for (char **pro = conjugations; *pro != END; pro += 2)
    {
        char *new;
        while ((new = replace_first(buffer, *pro, *(pro + 1))) != NULL)
        {
            strcpy(buffer, new);
            free(new);
        }
    }
    return buffer;
}

/* Finds the first keyword in msg and returns the string after the keyword.
 * The correct reply is placed in reply. */
char *find_reply(char *msg, char **reply)
{
    for (char **key = keyword_replies; *key != END; key += 2)
    {
        char *occurence;
        if ((occurence = strstr(msg, *key)) != NULL
            && (occurence == msg || *(occurence - 1) == ' ')) // Make sure that only whole words/phrases are matched.
        {
            *reply = *(key + 1);
            return occurence + strlen(*key) + 1;
        }
    }
    // No keyword found, get default reply.
    *reply = no_keyword;
    return NULL;
}

/* Converts all chars in str to uppercase. */
void to_upper(char *str)
{
    for (char *c = str; *c != '\0'; c++)
    {
        if (*c >= 'a' && *c <= 'z')
            *c += 'A' - 'a';
    }
}

/* MAIN ROUTINE */
int main()
{
    // Print introdution.
    puts("HI! I'M ELIZA, HOW MAY I HELP YOU?\n");

    char *msg = (char *) malloc(MESSAGE_MAX_LENGTH);
    while (1)
    {
        // Read and preprocess input.
        fgets(msg, MESSAGE_MAX_LENGTH, stdin);
        // Remove newline.
        msg[strlen(msg) - 1] = '\0';
        to_upper(msg);

        // Find and print answer.
        char *reply;
        char *rest = find_reply(msg, &reply);
        if (rest)
        {
            char *conj_rest = conjugate_pronouns(rest);
            printf(reply, conj_rest);
            puts("\n");
        } else
            printf("%s\n\n", reply);
    }
    
    return 0;
}
