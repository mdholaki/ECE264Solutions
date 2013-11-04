#include "pa07.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Prints a linked-list "head" into the output fie "out"
 *
 * NOTE: we have given the code for this function
 */
void List_print(FILE * out, Node * head)
{
 while(head != NULL)
	{
	    fprintf(out, "%5d: %6d\n", head -> index, head -> value);
	    head = head -> next;
	}
    printf("\n");
}

void dump(Node * head)
{
  if(head == NULL)
	printf("List is NULL\n");
    while (head != NULL)
    {
      printf("[%p] Index: %d Value: %d ==> %p\n", head, head -> index, head -> value, head -> next);
      head = head -> next;
    }
    printf("\n");
} 

/**
 * Please fill in the code below
 */

/**
 * Destroys a linked list.
 * Arguments:
 * head    A pointer pointing to the first element of the linked list.
 *
 * Returns:
 * void
 *
 * Destroys (frees memory for) the whole linked list. 
 * You can either use recursion or a while loop.
 */
void List_destroy(Node * head)
{
  if (head != NULL)
  {
    List_destroy(head -> next);
    free(head);
  }
  
  return;

}

/**
 * Create and initialize a linked list. 
 *
 * Arguments:
 * value     The "value" of the new node
 * index     The "index" of the new node
 *
 * Returns:
 * Returns a newly constructed node. The node can be the head of a
 * linked list.
 * 
 * You should allocate memory in this function. 
 */
Node * List_create(int value, int index)
{
  Node * nd;
  nd =  malloc(sizeof(Node));
  nd -> value = value; 
  nd -> index = index;
  nd -> next = NULL;
  return nd;
}

/**
 * Build a sparse array from the given indices and values with 
 * specific length.
 *
 * Arguments:
 * value    Array of values
 * index    Array of fprintf(out, "%5d: %6d\n", head -> index, head -> value);
	    head = head -> next;indices
 * length   Length of the above arrays
 *
 * Returns:
 * A sparse array.
 *
 * If a sparse array node has { value = 1000, index = 2 }, then that means that
 * the index "2" caries the value "1000". This is meant to convey an array of 1000 
 * "2s", but instead of creating 1000 nodes in your linked list, you only create
 * 1 node, and that note conceptually has 1000 "copies" of it. Hence 
 * each node in a sparse array has a "value" in addition to its "index".
 *
 * Note that an index can never carry the value of "0", because this would not make
 * any sense; however, negative values are fine. A negative value may seem odd
 * at first blush; however, this is like substraction, and makes sense for certain
 * cases.
 *
 * You need to insert nodes in ascending order by index.
 * See the notes to "List_insert_ascend"
 */
Node * List_build(int * value, int * index, int length)
{
  Node * head = NULL;
  int j = 0;
   
  while (j < length)
  {
    if (value[j] != 0)
    {
      head = List_insert_ascend(head, value[j], index[j]);
    }
    j++;
  }
  
  return head;
}


/**
 * Inserting "value" and "index" into the correct location in the 
 * sparse array "head"
 * 
 * Arguments: 
 * head      A pointer pointing to the first element of the linked list.
 * value     The "value" of the value
 * index     The "value" of the index
 *
 * Returns:
 * A sparse array
 *
 * This function inserts the node ["value", "index"] into the sparse
 * array "head", and ensures that the nodes remain in ascending order
 * by their "index".
 *
 * Before and after the call to this function, "head" must be in
 * ASCENDING order by the "index" of each node.
 */
Node * List_insert_ascend(Node * head, int value, int index)
{
 
  if (head == NULL)
  {
    return List_create(value, index);
  }
  
  if (head -> index < index)
  {
    head -> next = List_insert_ascend(head -> next, value, index);
    return head;
  }
  
  if((head -> index) == index)
  {
    head -> value += value;
    return head;
  }
  
  if ((head -> index) >  index)
  {
    Node * new_insert = List_create(value, index);
    new_insert -> next = head;
    return new_insert;
  }
  
  return head;
}


/**
 * This function deletes the node with the passed "index"
 * 
 * Arguments: 
 * head      A pointer pointing to the first element of the sparse array.
 * index     The index to be deleted
 *
 * Returns: 
 * A sparse array with the node removed (the one with index)
 */
Node * List_delete(Node * head, int index)
{ 
  if (head == NULL)
  {
    return NULL;
  } 
  
  if (head -> index == index)
  {
    Node * p = head -> next;
    free(head);
    return p;
  }
  
  head -> next = List_delete(head -> next, index);
  return head;
}

/**
 * Copy a list
 *
 * Arguments:
 * head      A pointer pointing to the first element of the sparse array
 *
 * Returns:
 * A copy sparse array
 *
 * This function will copy the sparse array that is passed to it. The
 * copy will be made into new memory. 
 *
 * This is useful, for example, when we want to merge
 * two linked lists together. We can make a copy of one of the linked
 * lists, and then merge the second into the copy. In this way the
 * original copy of the list is not "mutated".
 */
Node * List_copy(Node * head)
{
  /* Node * start = NULL;
  start = head;
  Node * copied = NULL;
  start = head;
  
  int * value;
  int * index;
  int length = 0;
  
  for (length = 0; start != NULL; length++)
  {
    start = start -> next;
  }
  
  value = malloc(sizeof(int) * length);
  index = malloc(sizeof(int) * length);
  int i = 0;
  
  while (head != NULL)
  {
    value[i] = head -> value;
    index[i] = head -> index;
    head = head -> next;
    i++;
  }
  
  copied = List_build(value, index, length);
  free(index);
  free(value); */
  if (head == NULL)
  {
    return NULL;
  }
  Node * copied = malloc(sizeof(Node));
  copied -> index = head -> index;
  copied -> value = head -> value;
  copied -> next = List_copy(head -> next);
  
  return copied;
}


/**
 * Merged two linked list together
 * 
 * Arguments:
 * head1      A pointer pointing to linked list 1
 * head2      A pointer pointing to linked list 2
 *
 * Returns:
 * A merged sparse array
 *
 * This function will merge two linked lists. Before merging, you 
 * should make a copy of "head1" so that you will still have the 
 * original array while modifying (merging) the second linked list. 
 *
 * Please refer to the README file for detailed instructions on how to
 * merge two lists.
 *s may only
 * This function should not modify either "head1" or "head2". You only
 * need to make a clone of "head1".
 */


Node * List_merge(Node * head1, Node * head2)
{
  
  
  Node * head1_copy = List_copy(head1);
    
  while(head2 != NULL)
  {
    head1_copy = List_insert_ascend(head1_copy, head2 -> value, head2 -> index);
    
    head2 = head2 -> next;
    
    if ((head1_copy -> value) == 0)
    {
      head1_copy = List_delete(head1_copy, head1_copy -> index);
    } 
  }
  
  return head1_copy;
}















#ifdef MYTEST
// gcc -g answer07.c -DMYTEST && ./a.out
int main(int argc, char * * argv)
{
  {  
    int values[] = {1, 1, 1};
    int index[] = {1, 2, 3};
    int values2[] = {1, 1, 1};
    int index2[] = {4,5,6};
    Node *head = List_build(values,index,sizeof(values)/sizeof(int));
    //Node * head2 = List_build(values2,index2, sizeof(values2)/sizeof(int));
    dump(head);
    head = List_delete(head, 1);
    dump(head);
    /*printf("\nInitial list:\n");
    dump(head);
    printf("\nList 2\n");
    dump(head);
    
    printf("\nMerging...\n");
    
    head = List_merge(head, head2);
    dump(head); */
     
    
  }
  return 0;
} 
#endif 
