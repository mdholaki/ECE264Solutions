typedef struct tnode
{
  struct tnode * left;
  struct tnode * right;
  int value; // store a letter if it is a leaf node
} TreeNode;

typedef struct snode
{
  TreeNode * data;
  struct snode * below;
} StackNode;

StackNode * Stack_create(TreeNode * tn)
{
  StackNode * st;
  st = malloc(sizeof(StackNode));
  st -> data = tn;
  st -> below = NULL;
  return st;
}

/* similar to List_insertFront */
StackNode * Stack_push(StackNode * st, TreeNode * tn)
{
  StackNode * newnode = Stack_create(tn);
  newnode -> below = st;
  return newnode;
}

TreeNode * TreeNode_create(int val)
{
  TreeNode * tn = malloc(sizeof(TreeNode));
  tn -> value = val;
  tn -> left = NULL;
  tn -> righ = NULL;
  return tn;
}



while (not the end of the tree)
  {
    read one letter; // command
    if the command is 1 
      {
	create a leaf node;
	push the node to a stack; // stack of tree nodes
      }
    if the command is 0 
      {
	pop the stack to get one node; // node A
	if the stack is empty 
	  {
	    the tree has been built, done;
	    A is the root of the tree
	  }
	else
	  {
	    pop the stack to get another node; // node B
	    create a node as the parent of the two nodes;
	    // node A and node B share the same parent
	    push the parent node to the stack
	  }
      }
  }
/* build the tree for 1a 1b 0 1c 1d 1$ 0 0 0 */





/* write a conversion function */
int convert(int by, int loc)
{
  switch (loc)
    {
    case 1:
      return (by & 0x80);
      break;
    case 2:
      return (by & 0x40);
      break;
    case 3:
      return (by & 0x20);
      break;
      ...
    }
}

  read one byte from the file
  get the commnad bit => location keeps changing
  if the command bit is 1
    {
      read another 8 bits
      create a tree node 
      push the tree node
    }
  else // command is zero
    {
      
      
    }
  move the command location forward by one
  
#include <stdlib.h>
#include <stdio.h>

#include "pa09.h"
HuffNode * HuffmanTree_NodeCreate(int value)
{
  HuffNode * newNode = malloc(sizeof(HuffNode));
  newNode -> value = value;
  newNode -> left = NULL;
  newNode -> right = NULL;
  return newNode;
}

Stack * Stack_create()
{
  Stack * newStack = malloc(sizeof(Stack));
  newStack -> next = NULL;
  newStack -> node = NULL;
  return newStack;
}

Stack * Stack_push(Stack * st, HuffNode * node)
{
  Stack * top = Stack_create();
  top -> node = node;
  top -> next = st;
  return top;
}

Stack * Stack_pop(Stack * st)
{
  if(st == NULL)
    {
      return NULL;
    }
  Stack * below = st -> next;
  free(st);
  return below;
}

HuffNode * HuffmanTree_Create(FILE * fptr)
{
  Stack * st = NULL;
  int command;
  int done = 0;
  HuffNode * first = NULL;
  HuffNode * second = NULL;
  while(done != 1)
    {
      command = fgetc(fptr);
      if(command == 49)
         {
         unsigned char val = fgetc(fptr);
         HuffNode * newNode = HuffmanTree_NodeCreate(val);
         st = Stack_push(st, newNode);
         }
      else if(command == 48)
        {
         first = st -> node;
         st = Stack_pop(st);
         if(st == NULL)
         {
         done = 1;
         }
         else
         {
         second = st -> node;
         st = Stack_pop(st);
         HuffNode * newNode = malloc(sizeof(HuffNode));
         newNode -> value = 9001;
         newNode -> right = first;
         newNode -> left = second;
         st = Stack_push(st, newNode);
         }
        }
    }
  return(first);
}
void Huffman_destroy(HuffNode * node)
{
  if(node == NULL)
    {
      return;
    }
  Huffman_destroy(node -> left);
  Huffman_destroy(node -> right);
  free(node);
  return;
}

void Huff_postOrderPrint(HuffNode *tree, FILE * fptr)
{
    // Base case: empty subtree
    if (tree == NULL) {
                return;
    }

    // Recursive case: post-order traversal

    // Visit left
    fprintf(fptr,"Left\n");
    Huff_postOrderPrint(tree->left, fptr);
    fprintf(fptr,"Back\n");
    // Visit right
    fprintf(fptr, "Right\n");
    Huff_postOrderPrint(tree->right, fptr);
    fprintf(fptr,"Back\n");
    // Visit node itself (only if leaf)
    if (tree->left == NULL && tree->right == NULL) {
      fprintf(fptr, "Leaf: %c\n", tree->value);
    }
}

HuffNode * HuffmanBit_to_Byte(FILE * fptr)
{
  unsigned char masks[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
  int commandLocation = 0;
  Stack * st = NULL;
  unsigned char command;
  unsigned char command2;
  int done = 0;
  HuffNode * first = NULL;
  HuffNode * second = NULL;
  int i;
  command = fgetc(fptr);
  while(done != 1)
    {
      if((masks[commandLocation] & command) == masks[commandLocation])
        {
         command2 = fgetc(fptr);
         command <<= (commandLocation + 1);
         for(i = 0; i < (commandLocation + 1); i++)
         {
         if((masks[i] & command2) == masks[i])
                {
                 command = command | masks[(7 - commandLocation) + i];
                }
         }
         commandLocation += 8;
         if(commandLocation == 15)
         {
         command2 = fgetc(fptr);
         commandLocation = 0;
         }
         else
         {
         commandLocation -= 7;
         }
         HuffNode * newNode = HuffmanTree_NodeCreate(command);
         st = Stack_push(st, newNode);
         command = command2;
        }
      else if((masks[commandLocation] & command) != masks[commandLocation])
        {
         commandLocation++;
         if(commandLocation == 8)
         {
         commandLocation = 0;
         command = fgetc(fptr);
         }
         first = st -> node;
         st = Stack_pop(st);
         if(st == NULL)
         {
         done = 1;
         }
         else
         {
         second = st -> node;
         st = Stack_pop(st);
         HuffNode * newNode = malloc(sizeof(HuffNode));
         newNode -> value = 9001;
         newNode -> right = first;
         newNode -> left = second;
         st = Stack_push(st, newNode);
         }
        }
    }
  return first;
}
