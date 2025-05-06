#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "char_stack.h"
#include "utils.h"

int main() {
    CharStack *word = initCharStack();
    if (word == NULL) return 1;

    printf("Informe uma palavra: ");
    readString(word);

    char* originalWord = malloc(strlen(word->data) + 1);  // +1 for '\0'
    if (originalWord == NULL) return 1;

    strcpy(originalWord, word->data);

    CharStack *reversedWord = initCharStack();
    if (reversedWord == NULL) return 1;
    
    char* c;
    while ((c = popChar(word)) != NULL) {
        if (*c != '\0') {
            pushChar(reversedWord, *c);
        }

        free(c);
    }

    pushChar(reversedWord, '\0');

    if (strcmp(originalWord, reversedWord->data) == 0) {
        printf("\nA palavra E um palindromo!\n");
    } else {
        printf("\nA palavra NAO E um palindromo!\n");
    }

    free(originalWord);
    freeCharStack(word);
    freeCharStack(reversedWord);

    sysCommand("pause_terminal");
    return 0;
}
