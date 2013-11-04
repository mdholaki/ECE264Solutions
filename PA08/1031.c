/*
 * tn is the root of the tree (change in recursive calls)
 * val is the value to be inserted
 * this function returns the root of the tree
 */
TreeNode * Tree_insert(TreeNode * tn, int val)
{
  if (tn == NULL) // nothing in the tree
    {
      return Tree_create(val); 
    }
  if ((tn -> value) == val) 
    {
      return tn; // do nothing
      /*
	common error 
	return NULL; // discard the node whose value is val
       */
    }
  if ((tn -> value) > val) // go to the left side
    {
      tn -> left = Tree_insert(tn -> left, val);
      return tn;
      /*
	compare with linked list
	fr -> next = List_insert(fr -> next, val);
       */
    }
  tn -> right = Tree_insert(tn -> right, val);
  return tn;
}

/*
 * return the node whose value is val
 * or NULL if this tree does not store vall
 */
TreeNode * Tree_search(TreeNode * tn, int val)
{
  if(tn==NULL)
    {
      return NULL; //or return tn b/c its null too 
    }
  if((tn->value) == val)
    {
      return tn;
    }
  if((tn->value) > val)
    {
      return Tree_search(tn->left, val);
    }
  return Tree_search(tn->right, val);
}

/*
 * delete every node in the tree
 */
void Tree_destroy(TreeNode * tn)
{
  if (tn == NULL)
    {
      return;
    }
  Tree_destroy(tn -> left);
  Tree_destroy(tn -> right);
  free (tn); // must be the last
}

/*
 * traversal: visit the nodes in the tree
 */
/*
 * 1. visit left side
 * 2. visit right side
 * 3. visit this node
 */
void Tree_print(TreeNode * tn)
{
  if (tn == NULL)
    {
      return;
    }
  printf("value = %d\n", tn -> value); // N 
  Tree_print(tn -> left);              // L
  Tree_print(tn -> right);             // R
}
/*
 * 3! = 3 x 2 x 1 = 6
 * NLR, NRL, LNR, LRN, RNL, RLN
 * by convention: L is before R
 * 3 ways:
 * NLR              LNR                LRN
 * pre-order        in-order           post-order
 * N is first       N is second        N is last
 */

/*
 * PA08 deadline is extended to November 5 Tuesday
 * there will be only 11 assignments
 * highest 5 assignments will get 5 points each
 * the other 6 get 4 points each
 * => 49 points (1 additional point)
 * PA 12 will be a bonus assignment with 4 points
 */

merge(tree1 and tree2)
{
  if (tree2 == NULL)
    {
      return;
    }
  
  merge tree2 -> left to tree1
  merge tree2 -> right to tree1
  insert tree2 to tree1
}
