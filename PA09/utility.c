#include "pa09.h"
#include <stdio.h>
#include <stdlib.h>

HuffNode * HuffNode_create(int value)
{
  HuffNode * n = malloc(sizeof(HuffNode));
  n -> value = value;
  n -> left = NULL;
  n -> right = NULL;
  return n; 
}

Stack * StackPush(Stack * st, HuffNode * node)
{
  Stack * stack_new = malloc(sizeof(Stack));
  stack_new -> next = st;
  stack_new -> node = node;
  return stack_new;
} 

Stack * StackPop(Stack * st)
{
  if (st == NULL)
  {
    return NULL;
  }
  
  Stack * nextstack = st -> next;
  free(nextstack);
  return nextstack;
}

void Huffdestroy(HuffNode * node)
{
  if ( node == NULL)
    {
      return;
    }

  Huffdestroy(node->left);
  
  Huffdestroy(node->right);

  free(node);
}

HuffNode * HuffBuildTree(FILE * fptr)
{
  Stack * st = NULL;
  unsigned char command = fgetc(fptr);
  
  do
  {
    if (command == '1')
    {
      unsigned char value = fgetc(fptr);
      HuffNode * leaf = HuffNode_create(value);
      st = StackPush(st, leaf);
    }
    
    if (command = '0')
    {
      HuffNode * A = st -> node;
      st = StackPop(st);
      if (st == NULL)
      {
	return A;
      }
      
      else
      {
	HuffNode * B = st -> node;
	st = StackPop(st);
	HuffNode * parent = malloc(sizeof(HuffNode));
	parent -> value = ' ';
	parent -> right = A;
	parent -> left = B;
	st = StackPush(st,parent);
      }
    }
    command = fgetc(fptr);
  }while(st != NULL);
  
}

	
  