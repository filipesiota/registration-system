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
        pushChar(reversedWord, *c);
        free(c);
    }

    pushChar(reversedWord, '\0');
    printf("\nORIGINAL: %s\nREVERSED: %s\n", originalWord, reversedWord->data);

    if (strcmp(originalWord, reversedWord->data) == 0) {
        printf("\nA palavra E um palindromo!\n");
    } else {
        printf("\nA palavra NAO E um palindromo!\n");
    }

    free(originalWord);
    free(word->data);
    free(word);
    free(reversedWord->data);
    free(reversedWord);

    sysCommand("pause_terminal");
    return 0;
}
