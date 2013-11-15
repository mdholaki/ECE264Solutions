#include <stdio.h>
#include <stdlib.h>
#include "pa09.c"

int main ( int argc , char ** argv )
{
  //check arguments
  if (argc != 3)
    {
      printf("usage: ./pa04 <input file> <output file>\n");
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
  root = HuffbuildTree(fptr);
  
  fclose(fptr);
  
  File * NewOutput = NULL;
  NewOutput = fopen(argv[2], "w");
  
  
  newPostOrderPrint(root, NewOutput);
  
  HuffDestroy(root);
  
  fclose(fptr);
  fclose(NewOutput);
  
  return EXIT_SUCCESS;
  
  
    
  
