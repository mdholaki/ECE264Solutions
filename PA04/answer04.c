/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>



/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */


void partitionAll(int value)
{
  printf("partitionAll %d\n", value);
  void part(int value, int* arr, int ind);
  int ind = 0;
  
  int * arr = malloc(value * sizeof(int));
  part(value, arr, ind);
  free(arr);
  
}

void printpart(int * arr, int length)
{
  int i = 0;
  
  printf("= ");
  for (i = 0; i < (length - 1); i++)
  {
    printf("%d + ", arr[i]);
  }
  printf("%d\n", arr[length - 1]);
  
  return;
}

void part(int value, int * arr, int ind)
{
 int n = 0;
  
  if (value == 0)
  {
    printpart(arr,ind);
    return;
  }
  
  for (n = 1; n <= value; n++)
    {
      arr[ind] = n;
      part(value-n, arr, ind + 1);
    }
}

/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionIncreasing(int value)
{
  int ind = 0;
  
  printf("partitionIncreasing %d\n", value);
  void partInc( int value, int * arr, int ind);
  
  int * arr = malloc(value * sizeof(int));
  partInc(value, arr, ind);
  free(arr);
  
}

void partInc(int value, int * arr, int ind)
{
  int n = 0;
  
  if (value == 0)
  {
    printpart(arr, ind);
    return;
  }
  
  for (n = 1; n <= value; n++)
  {
    arr[ind] = n;
    //if (ind == 0)
    //{
    //  partInc(value - n, arr, ind + 1);
    //}
    if ( arr[ind] > arr[ind - 1])
    {
      arr[ind] = n;
      partInc(value - n, arr, ind + 1);
    }
  }
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionDecreasing(int value)
{
  int ind = 0;
  
  printf("partitionDecreasing %d\n", value);
  void partDec( int value, int * arr, int ind);
  
  int * arr = malloc(value * sizeof(int));
  partDec(value, arr, ind);
  free(arr);
  
}

void partDec(int value, int * arr, int ind)
{
  int n = 0;
  
  if (value == 0)
  {
    printpart(arr, ind);
    return;
  }
  
  for (n = 1; n <= value; n++)
  {
    arr[ind] = n;
    if (ind == 0)
    {
      partDec(value - n, arr, ind + 1);
    }
    else if ( arr[ind] < arr[ind - 1])
    {
      arr[ind] = n;
      partDec(value - n, arr, ind + 1);
    }
  }
}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOdd(int value)
{
  int ind = 0;
  
  printf("partitionOdd %d\n", value);
  
  void partOdd( int value, int * arr, int ind);
  
  int * arr = malloc(value * sizeof(int));
  partOdd(value, arr, ind);
  free(arr);
}

void partOdd(int value, int* arr, int ind)
{
  int n = 0;
  
  if (value == 0)
  {
    printpart(arr, ind);
    return;
  }
  
  for (n = 1; n <= value; n++)
  {
    if ((n % 2) != 0)
    {
      arr[ind] = n;
      partOdd(value - n, arr, ind + 1);
    }
  }
}
  

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEven(int value)
{
  int ind = 0;
  
  printf("partitionEven %d\n", value);
  void partEven( int value, int * arr, int ind);
  
  int * arr = malloc(value * sizeof(int));
  partEven(value, arr, ind);
  free(arr);
}

void partEven(int value, int* arr, int ind)
{
  int n = 0;
  
  if (value == 0)
  {
    printpart(arr, ind);
    return;
  }
  
  for (n = 1; n <= value; n++)
  {
    if ((n % 2) == 0)
    {
      arr[ind] = n;
      partEven(value - n, arr, ind + 1);
    }
  }
}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOddAndEven(int value)
{
  int ind = 0;
  
  printf("partitionOddAndEven %d\n", value);
  void partOddAndEven( int value, int * arr, int ind);
  
  int * arr = malloc(value * sizeof(int));
  partOddAndEven(value, arr, ind);
  free(arr);
}

void partOddAndEven(int value, int * arr, int ind)
{
  int n = 0;
  
  if (value == 0)
  {
    printpart(arr, ind);
    return;
  }
  
  
  for (n = 1; n <= value; n++)
  {
    arr[ind] = n;
    if (ind == 0 && ((arr[0] % 2) != 0))
    {
      partOddAndEven(value - n, arr, ind + 1);
    }
    else if ( (((arr[ind] + arr[ind - 1]) % 2) != 0) && ((arr[0] % 2) != 0))
    {
      arr[ind] = n;
      partOddAndEven(value - n, arr, ind + 1);
    }
  }
}
/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */



void partitionPrime(int value)
{
  int ind = 0;
  
  printf("partitionPrime %d\n", value);
  void partPrime( int value, int * arr, int ind);
  
  int * arr = malloc(value * sizeof(int));
  partPrime(value, arr, ind);
  free(arr);
}

void partPrime(int value, int* arr, int ind)
{
  int n = 0;
  int primenum = 0;
  int prime(int n);
  
  if (value == 0)
  {
    printpart(arr, ind);
    return;
  }
  
  for (n = 1; n <= value; n++)
  {
      primenum = prime(n);
      if (primenum == 1)
      {
	arr[ind] = n;
	partPrime(value - n, arr, ind + 1);  
      }
  }
}


int prime(int n)
{
  int x = 2;
  int primenum = 1;
  
  for (x = 2; x < n; x++)
  {
    if ((n % x) == 0)
    {
      primenum = 0;
    }
  }
  
  if (n == 1)
  {
    primenum = 0;
  }
  
  return primenum;
}
    
  
  

#ifdef MYTEST
// gcc -g answer02.c -DMYTEST && ./a.out
int main()
{
   int value = 10;
   //partitionAll(value);
   //partitionIncreasing(value);
   //partitionDecreasing(value);
   //partitionOdd(value);
   //partitionEven(value);
   partitionOddAndEven(value);
   //partitionPrime(value);
   
   return;
}
#endif
