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


HuffNode * HuffConvertBit2Byte(FILE * fptr)
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
         HuffNode * newNode = HuffNode_create(command);
         st = StackPush(st, newNode);
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
         st = StackPop(st);
         if(st == NULL)
         {
         done = 1;
         }
         else
         {
         second = st -> node;
         st = StackPop(st);
         HuffNode * newNode = malloc(sizeof(HuffNode));
         newNode -> value = 9001;
         newNode -> right = first;
         newNode -> left = second;
         st = StackPush(st, newNode);
         }
        }
    }
  return first;
}


  
	
  