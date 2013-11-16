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
  free(st);
  return nextstack;
}

void HuffDestroy(HuffNode * node)
{
  if ( node == NULL)
    {
      return;
    }

  HuffDestroy(node->left);
  
  HuffDestroy(node->right);

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
    
    if (command == '0')
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
  
  return NULL;
  
}

void HuffPostOrderPrint(HuffNode * node, FILE * fptr)
{
  if (node == NULL)
  {
    return;
  }
  
  fprintf(fptr, "Left\n");
  HuffPostOrderPrint(node -> left, fptr);
  fprintf(fptr, "Back\n");
  
  fprintf(fptr, "Right\n");
  HuffPostOrderPrint(node -> right, fptr);
  fprintf(fptr, "Back\n");
  
  if ((node -> left == NULL) && (node -> right == NULL))
  {
    fprintf(fptr, "Leaf: %c\n", node -> value);
  }
  
  return;
}


HuffNode * HuffBuildBit(FILE * fptr)
{
  unsigned char ch = fgetc(fptr);
  int cmd_loc = 1;
  int count = 0;
  unsigned char masks[] = {0x80, 0x40, 0x20,0x10,0x08,0x04,0x02,0x01};
  unsigned char command = 0; 
  Stack * st = NULL;
  unsigned char next;
  unsigned char value; 
  unsigned char next_temp;
  while (1)
  {
    command = (ch & masks[count]);
    if (command != 0)
    {
      next = fgetc(fptr);
      value = ch << cmd_loc;
      next_temp = next >> (8 - cmd_loc);
      value = value | next_temp;
      HuffNode * TreeNode = HuffNode_create(value);
      st = StackPush(st, TreeNode);
      ch = next;
    }
    else
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
    
    if (cmd_loc == 8)
    {
      ch = fgetc(fptr);
      count = 0;
      cmd_loc = 1;
    }
    else
    {
      cmd_loc++;
      count++;
    }
  }
  return NULL;  
      
    
    
}


  
	
  