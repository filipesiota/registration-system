#include "char_stack.h"

#include <stdlib.h>

CharStack* initCharStack() {
    CharStack *stack = malloc(sizeof(CharStack));
    if (!stack) return NULL;

    stack->data = NULL;
    stack->top = -1;

    return stack;
}

void pushChar(CharStack* stack, char value) {
    stack->top++;

    char *temp = realloc(stack->data, stack->top + 1);
    if (temp == NULL) return;
    
    stack->data = temp;
    stack->data[stack->top] = value;
}

char* popChar(CharStack* stack) {
    if (stack->top == -1) return NULL;

    char* popValue = malloc(sizeof(char));
    if (popValue == NULL) return NULL;

    *popValue = stack->data[stack->top];

    if (stack->top == 0) {
        free(stack->data);
        stack->data = NULL;
    } else {
        char* temp = realloc(stack->data, stack->top);
        if (temp != NULL) stack->data = temp;
    }

    stack->top--;
    return popValue;
}

int isEmpty(CharStack* stack) {
    return stack->top == -1;
}
