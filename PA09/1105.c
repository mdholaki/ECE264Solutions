int isLeaf(TreeNode * tn)
{
  if (tn == NULL) { return 1; }
  if ((tn -> left) == NULL)
    {
      if ((tn -> right) == NULL)
	{
	  return 1;
	}
    }
  return 0;
}

while (not the end of the file)
  {
    read one bit; // data
    if the bit is 0 => go left;
    if the bit is 1 => go right;
    if this node is a leaf node 
      {
	print the value;
	return to the root;
      }
  }














while (tree not done yet)
  {
    read one command; // command can be 0 or 1
    if (command is 1)
      {
	read a letter;
	create a leaf node storing the letter;
	push this node to the stack // not callstack
      }
    else // command is 0
      {
	/*
	create a non-leaf node as the parent
	  of the *latest* two nodes
	*/
	// create a stack
        pop a node from the stack; // node A
	if the stack is empty => tree is done;
	else
	  {
	    pop another node from the stack; // node B
	    create a non-leaf node as the parent
	      of the *latest* two nodes // A and B
	    push the new node to the stack
	  }
      }
  }











typedef struct snode
{
  struct snode * next;
  TreeNode * tn;
} StackNode;

StackNode * Stack_push(StackNode * st, TreeNode * t)
{
  StackNode * stnew = malloc(sizeof(StackNode));
  stnew -> tn = t;
  stnew -> next = st;
  return stnew;
}
