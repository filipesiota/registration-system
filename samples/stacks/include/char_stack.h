#ifndef CHAR_STACK_H
#define CHAR_STACK_H

typedef struct {
    int top;
    char* data;
} CharStack;

CharStack* initCharStack();
void pushChar(CharStack* stack, char value);
char* popChar(CharStack* stack);
int isEmpty(CharStack* stack);

#endif
