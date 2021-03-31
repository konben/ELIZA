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
char msg[MESSAGE_MAX_LENGTH];
char reply_end[MESSAGE_MAX_LENGTH];

/* Conjugates the pronouns in reply_end. */
void conjugate_pronouns()
{
    for (char *c = reply_end; *c != '\0'; c++)
    {
        for (char **pro_conj = conjugations; *pro_conj != END; pro_conj += 2)
        {
            char *pronoun = *pro_conj;
            // Pronoun found?
            if (strncmp(pronoun, c, strlen(pronoun)) == 0 &&
                (c == reply_end || *(c - 1) == ' ') && // Ugly as fuck, but I have to test if a word has been found.
                (*(c + strlen(pronoun)) == '\0' || *(c + strlen(pronoun)) == ' '))
            {
                // Replace it and move on.
                char *conj = *(pro_conj + 1);
                char buff[MESSAGE_MAX_LENGTH];
                strcpy(buff, conj);
                strcat(buff, c + strlen(pronoun));
                strcpy(c, buff);
                c += strlen(conj);
            }
        }
    }
}

/* Finds the first keyword in msg and places the string after the keyword in reply_end.
 * The correct reply to the keyword is returned. */
char *find_reply(char *msg)
{
    for (char **key_rep = keyword_replies; *key_rep != END; key_rep += 2)
    {
        char *key = *(key_rep);
        char *occurence;
        if ((occurence = strstr(msg, key)) != NULL
            && (occurence == msg || *(occurence - 1) == ' ') // Make sure that only whole words/phrases are matched.
            && (*(occurence + strlen(key)) == '\0' || *(occurence + strlen(key)) == ' '))
        {
            strcpy(reply_end, occurence + strlen(key) + 1);
            char *reply = *(key_rep + 1);
            return reply;
        }
    }
    // No keyword found, return default reply.
    reply_end[0] = '\0';
    return no_keyword;
}

/* Applies preprocessing on input. */
void preprocess()
{
    // Remove newline character
    msg[strlen(msg) - 1] = '\0';
    for (char *c = msg; *c != '\0'; c++)
    {
        // Convert to uppercase.
        if (*c >= 'a' && *c <= 'z')
            *c += 'A' - 'a';
        // Convert tabs to spaces.
        else if (*c == '\t')
            *c = ' ';
        // Remove punctuation and surplus spaces.
        if (*c == '.' || *c == '\'' || *c == '?'
            || *c == ' ' && (c == msg || *(c - 1) == ' ' || *(c + 1) == '\0'))
        {
            for (char *c2 = c; *c2 != '\0'; c2++)
                *c2 = *(c2 + 1);
            c--;
        }
    }
}

/* MAIN ROUTINE */
int main()
{
    // Print introdution.
    puts("HI! I'M ELIZA, HOW MAY I HELP YOU?\n");
    while (1)
    {
        // Read and preprocess input.
        fgets(msg, MESSAGE_MAX_LENGTH, stdin);
        preprocess();

        // Find and print answer.
        char *reply = find_reply(msg);
        conjugate_pronouns();
        printf(reply, reply_end);
        puts("\n");
    }
    
    return 0;
}
