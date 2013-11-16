#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa09.h"

int main ( int argc , char ** argv )
{
  //check arguments
  if (argc != 3)
    {
      printf("usage: ./pa09 <input file> <output file>\n");
      return EXIT_FAILURE;
    }
  
  //initializing input file
  FILE * fptr = NULL;
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("File error!\n");
      return EXIT_FAILURE;
    }
  
  HuffNode * root = NULL;
    
  if(strstr(argv[1], "ch") != NULL)
  {
    root = HuffBuildTree(fptr); //build char tree 
  }
  else
  {
      root = HuffBuildBit(fptr);//build bit tree
  }
  
    
  
  fclose(fptr);
  
  FILE * NewOutput = NULL;
  NewOutput = fopen(argv[2], "w");
  
  
  HuffPostOrderPrint(root, NewOutput);
  
  HuffDestroy(root);
  
  fclose(NewOutput);
  
  return EXIT_SUCCESS;
}
  
    
  
