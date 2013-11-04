typedef struct lnode
{
  struct lnode * next; // only one pointer
  int data; 
} ListNode; // linked list

typedef struct tnode
{
  struct tnode * left;  // two pointers
  struct tnode * right; // second pointer
  int data; 
} TreeNode; // binary tree

TreeNode * Tree_construct(int v)
{
  TreeNode * tn;
  tn = malloc(sizeof(TreeNode));
  tn -> left = NULL;  // similar to -> next = NULL
  tn -> right = NULL; 
  tn -> data = v;
  return tn;
}

TreeNode * Tree_search(TreeNode * tn, int val)
/*
 * return a pointer to the node whose data is val
 * return NULL if no such node can be found
 */
{
  if (tn == NULL)
    {
      return NULL; // cannot find
    }
  if ((tn -> data) == val)
    {
      return tn; // found it
    }
  if ((tn -> data) > val)
    {
      return Tree_search(tn -> left, val); 
      // go to the left side
    }
  return Tree_search(tn -> right, val); 
  // go to the right side
}

TreeNode * Tree_insert(TreeNode * tn, int val)
{
  if (tn == NULL)
    {
      return Tree_constrct(val);
    }
  if ((tn -> data) == val)
    {
      return tn; // if the data is already in the tree
    }
  if ((tn -> data) > val)
    {
      // val will be inserted to the left side
      tn -> left = Tree_insert(tn -> left, val);
      return tn;

      // compare this with linked list
      /*
      fr -> neft = List_insert(fr -> next, val);
      return fr;
      */
    }
  // val will be inserted to the right side
  tn -> right = Tree_insert(tn -> right, val);
  return tn;

}
