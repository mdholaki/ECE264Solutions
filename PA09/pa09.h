#ifndef PA09_H
#define PA09_H
#include <stdio.h>
#include <string.h>

typedef struct _huffnode {
    int value; 
    struct _huffnode * left;
    struct _huffnode * right;
} HuffNode;

typedef struct _stack {
    struct _stack * next;
    HuffNode * node;
} Stack;

Stack * StackPush(Stack * st, HuffNode * Node);
Stack * Stackpop(Stack * st);
HuffNode * HuffNode_create(int);
void HuffDestroy(HuffNode * node);
HuffNode * HuffBuildTree(FILE * fptr);
void HuffPostOrderPrint(HuffNode * node, FILE * fptr);
HuffNode * HuffConvertBit2Byte(FILE * fptr);

#endif




