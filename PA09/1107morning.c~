typedef struct tnode
{
  struct tnode * left;
  struct tnode * right;
  int value; // store a letter if it is a leaf node
} TreeNode;

typedef struct snode
{
  TreeNode * data;
  struct snode * below;
} StackNode;

StackNode * Stack_create(TreeNode * tn)
{
  StackNode * st;
  st = malloc(sizeof(StackNode));
  st -> data = tn;
  st -> below = NULL;
  return st;
}

/* similar to List_insertFront */
StackNode * Stack_push(StackNode * st, TreeNode * tn)
{
  StackNode * newnode = Stack_create(tn);
  newnode -> below = st;
  return newnode;
}

TreeNode * TreeNode_create(int val)
{
  TreeNode * tn = malloc(sizeof(TreeNode));
  tn -> value = val;
  tn -> left = NULL;
  tn -> righ = NULL;
  return tn;
}



while (not the end of the tree)
  {
    read one letter; // command
    if the command is 1 
      {
	create a leaf node;
	push the node to a stack; // stack of tree nodes
      }
    if the command is 0 
      {
	pop the stack to get one node; // node A
	if the stack is empty 
	  {
	    the tree has been built, done;
	    A is the root of the tree
	  }
	else
	  {
	    pop the stack to get another node; // node B
	    create a node as the parent of the two nodes;
	    // node A and node B share the same parent
	    push the parent node to the stack
	  }
      }
  }
/* build the tree for 1a 1b 0 1c 1d 1$ 0 0 0 */


























/* write a conversion function */
int convert(int by, int loc)
{
  switch (loc)
    {
    case 1:
      return (by & 0x80);
      break;
    case 2:
      return (by & 0x40);
      break;
    case 3:
      return (by & 0x20);
      break;
      ...
    }
}

  read one byte from the file
  get the commnad bit => location keeps changing
  if the command bit is 1
    {
      read another 8 bits
      create a tree node 
      push the tree node
    }
  else // command is zero
    {
      
      
    }
  move the command location forward by one
  

