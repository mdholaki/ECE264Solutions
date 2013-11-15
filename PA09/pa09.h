#ifndef PA09_H
#define PA09_H

typedef struct _huffnode {
    int value; 
    struct _huffnode * left;
    struct _huffnode * right;
} HuffNode;

typedef struct _stack {
    struct _stack * next;
    HuffNode * node;
} Stack;

HuffNode * HuffBuildTree(FILE * fptr);
Stack * StackPush(Stack * st, HuffNode * Node);
Stack * Stackpop(Stack * st);
HuffNode * HuffNode_create(int);
void Huffdestroy(HuffNode * node);



#endif

