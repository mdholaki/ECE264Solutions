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
  if (head == NULL)
  {
    return;
  }
  List_destroy(head -> next);
  free(head);
  
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
  Node * nd = malloc(sizeof(Node));
  nd -> next = NULL;
  nd -> value = value; 
  nd -> index = index;
  
  return nd;
}

/**
 * Build a sparse array from the given indices and values with 
 * specific length.
 *
 * Arguments:
 * value    Array of values
 * index    Array of indices
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
  int i = 0;
  int j = 0;
  int length_real = 0;
  
  length_real = length - 1;
  
  for (i = (length_real); i > 0; i--)
  {
    if(index[i -1] == index[i])
    {
      value[i - 1] = (value[i-1] + value[i]);
      value[i] = 0;
    }
  }
  
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
  Node * new_insert;
  new_insert = List_create(value, index);
  
  if (head == NULL)
  {
    return new_insert;
  }
  
  if (head -> index < new_insert -> index)
  {
    head -> next = new_insert;
    return head;
  }
  
  if ((head -> index) > (new_insert -> index))
  {
    new_insert -> next = head;
    return new_insert;
  }
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
  Node * p;
  p = head;
  
  if (p == NULL)
  {
    return p;
  }
  
  
  Node * q;
  q = p -> next;
    
  while ((q != NULL) && ((q -> index) != index))
  {
    p = p -> next;
    q = q -> next;
  }
  
  if (q != NULL)
  {
    p -> next = q -> next;
    free(q);
  }
  
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
  Node * start = NULL;
  start = head;
  Node * copied = NULL;
  
  int * value;
  int * index;
  int length = 0;
  for (length = 0; start != NULL; length++)
    start = start -> next;
  
  value = malloc(sizeof(int) * length);
  index = malloc(sizeof(int) * length);
  int i = 0;
  
  while (start != NULL)
  {
    value[i] = start -> value;
    index[i] = start -> index;
    start = start -> next;
    i++;
  }
  
  copied = List_build(value, index, length);
  free(index);
  free(value);
  
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

Node * merge_insert(Node * head1_copy,int value, int index)
{
  if (head1_copy == NULL)
  {
    return List_create(value, index);
  }
  
  if ((head1_copy -> index) == index)
  {
    head1_copy -> value += value;
  }
  
  if ((head1_copy -> index) > index)
  {
    Node * p;
    p = List_create(value, index);
    p -> next = head1_copy;
  }
  
  head1_copy -> next = merge_insert(head1_copy -> next, value, index);
  
  return head1_copy;
}


Node * List_merge(Node * head1, Node * head2)
{
  Node * head1_copy = NULL;
  head1_copy = List_copy(head1);
  
  while(head2 != NULL)
  {
    head1_copy = merge_insert(head1_copy, head2 -> value, head2 -> index);
    head2 = head2 -> next;
  }
  
  while(head1_copy != NULL)
  {
    if ((head1_copy -> value) == 0)
    {
      head1_copy = List_delete(head1_copy, head1_copy -> index);
    }
  }
  
  return head1_copy;
}

#ifdef MYTEST
int main(int argc, char * * argv)
{
  {  
    int values[] = {1, 2, 3, 5, 6, 7};
    int index[] = {1, 2, 3, 5, 6, 7};
    Node *head = List_build(values,index,sizeof(values)/sizeof(int));
    printf("\n=====List======\n");
    List_print(stdout,head);
    printf("\n========Trying to insert in the begining========\n");
    printf("========You should see a 0: 1000========\n");
    head = List_insert_ascend(head,1000,0);
    List_print(stdout,head);
    printf("\n========Trying to insert in the middle========\n"); 
    printf("========You should see a 4: 4========\n");
    head = List_insert_ascend(head,4,4);
    List_print(stdout,head);
    printf("\n========Trying to insert in the end========\n");
    printf("========You should see a 9: 9========\n");
    head = List_insert_ascend(head,9,9);
    List_print(stdout,head);
    printf("\n========Trying to insert something that will make the value of index 3 0========\n");
    printf("========Index 3 should disappear ========\n");
    head = List_insert_ascend(head,0,3);
    List_print(stdout,head);
  }
  return 0;
}
#endif
