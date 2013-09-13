
#include "pa03.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Read a file of integers.
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of integers (one
 * per line)
 * 
 * numberOfIntegers: pointer to store the number of integers in the
 * file. You need to update the value stored at the address which is
 * the pointer's value
 *
 * Returns:
 *
 * a array of integers from the file, or NULL if *any* error is
 * encountered.
 *
 * You do NOT know how many integers are in the file until you have
 * read it. Once you know how many integers there are, you can modify
 * the "numberOfIntegers" variable. (Note that this is a pointer, not
 * an integer) You must allocate memory to store the integers.
 * 
 * Once memory is allocated to store the integers, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek".
 * 
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read integeres is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * The allocated memory will be released in pa03.c. You do not need to
 * worry about releasing memory.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of integers in the file.  For example, if
 * you write this
 *
 * int array[10000];
 * 
 *
 */

int * readIntegers(const char * filename, int * numberOfIntegers)
{
  FILE * fp;
  //int integer = 0;
  int count = 0;
  int value = 0;
  int i = 0;
  int * array;
  
  fp = fopen(filename, "r");
  
  if (fp == NULL)
  {
    return NULL;
  }
  
  else if (fp != NULL)
  {
    while (fscanf(fp, "%d", &value) == 1)
    {
      count++;
    }
    *numberOfIntegers = count;
    
    array = malloc(sizeof(int) * count);
    
    fseek(fp, 0, SEEK_SET);
    
    while(fscanf(fp, "%d", &value) == 1)
    {
      array[i] = value;
      i++;
    }
    
    fclose(fp);
    
    return array; 
  }
  
}
  

/**
 * Sort an (ascending) array of integers
 *
 * Arguments:
 * arr    The array to search
 * length Number of elements in the array
 *
 * Uses "quicksort" to sort "arr".  Use the first element of the array
 * as the pivot.  
 *
 * Your solution MUST use recursive function (or functions)
 * 
 * quicksort works in the following way: 
 * 
 * find an element in the array (this element is called the
 * pivot). 
 *
 * rearrange the array's elements into two parts: the part smaller
 * than this pivot and the part greater than this pivot; make the pivot
 * the element between these two parts
 * 
 * sort the first and the second parts separately by repeating the 
 * procedure described above
 * 
 * You will receive no point if you use any other sorting algorithm.
 * You cannot use selection sort, merge sort, or bubble sort.
 * 
 * Some students are fascinated by the name of bubble sort.  In
 * reality, bubble sort is rarely used because it is slow.  It is a
 * mystery why some students (or even professors) like bubble sort.
 * Other than the funny name, bubble sort has nothing special and is
 * inefficient, in both asymptotic complexity and the amount of data
 * movement.  There are many algorithms much better than bubble sort.
 * You would not lose anything if you do not know (or forget) bubble
 * sort.
 *
 */
void sort(int * arr, int length)
{
  int ind_left = 0;
  int ind_right;
  void sort2( int * arr, int ind_left, int ind_right);
  
  ind_right = length - 1;
  
  sort2(arr, ind_left, ind_right);
  
  return;
}

/*Second Recursive Sort Function with three inputs */

void sort2(int * arr, int ind_left, int ind_right)
{
  int left = 0;
  int right = 0;
  int pivot = 0;
  int temp = 0;
  
  if ((ind_left == ind_right) || (ind_left > ind_right))
  {
    return;
  }
  
  else
  {
  left = ind_left + 1;
  right = ind_right;
  pivot = arr[ind_left];
    
  while (left < right)
  {
    while ((arr[left] < pivot) && (left < (ind_right - 1)))
    {
      left++;  
    }
    
    while (arr[right] > pivot)
    {
      right--;
    }
    
    if (left < right)
    {
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    }
  }
  
  temp = arr[left];
  arr[left] = arr[ind_left];
  arr[ind_left] = temp;
  
  sort2(arr, ind_left, (right - 1));
  sort2(arr, (right + 1), ind_right);  
  }
} 


/**
 * Use binary search to find 'key' in a sorted array of integers
 *
 * Arguments:
 * 
 * arr The array to search. Must be sorted ascending.  You do not need
 *        to check. This array is from the result of your sort
 *        function. Make sure your sort function is correct before you
 *        start writing this function.
 *
 * length Number of elements in the array
 * key    Value to search for in arr
 *
 * Returns:
 * The index of 'key', or -1 if key is not found.
 *
 * Since the array is sorted, you can quickly discard many elements by
 * comparing the key and the element at the center of the array. If
 * the key is the same as this element, you have found the index.  If
 * the key is greater than this element, you can discard the first
 * half of the array.  If the key is smaller, you can discard the
 * second half of the array.  Now you have only half of the array to
 * search.  Continue this procedure until either you find the index or
 * it is impossible to find a match.
 * 
 * Your solution MUST use recursive function (or functions)
 *
 * Don't forget that arrays are 'zero-indexed'. Also, you must
 * use a binary search to pass this question.
 * 
 * You will receive no point if you do the following because it is not
 * binary search.  This is called linear search because it checks
 * every element.
 *
 * int ind;
 * for (ind = 0; ind < length; ind ++)
 * {
 *    if (arr[ind] == key)
 *    {
 *       return ind;
 *    }
 * }
 * return -1;
 */
int search(int * arr, int length, int key)
{
  int start = 0;
  int index = 0;
  int end = 0;
  int search2(int * arr, int length, int key, int start, int end);
  
  end = length - 1;
  index = search2(arr, length, key, start, end);
  
  
    return index;
}

int search2(int * arr, int length, int key, int start, int end)
{
  int mid = 0;
  int index = 0;
  
   if (start < length)
   {
     mid = (start + end)/2;
     
     if (key == arr[mid])
     {
       index = mid;
     }
     
     else if (key < arr[mid])
     {
       return search2(arr, length, key, start, mid -1);
     }
     else
     {
       return search2(arr, length, key, mid + 1, end);
     }
   }
     
   else 
     {
       index = -1;
     }
 
  
  return index;
}
      
#ifdef MYTEST
// gcc -g answer02.c -DMYTEST && ./a.out
int main()
{
  
  int arr[5] = {5,7,4,3,6};
  int length = 5; 
  int i = 0;
  int key = 6;
  int index = 0;
  
  sort(arr,length);
  index = search(arr,length, key);
  
  printf("Integer '%d' is in the %d position\n", key, index);
  
  for (i = 0; i < 5; i++)
  {
    printf("%d\n", arr[i]);
  }
  
  return 0;
}
#endif
  
 
