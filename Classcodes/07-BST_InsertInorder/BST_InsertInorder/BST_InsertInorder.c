#include <stdio.h>
#include <stdlib.h>
 
struct node // Binary Search Tree Node
{
  int key; // key value. why is this not a pointer? because it is an integer. It can't be NULL. It will be a garbage value.

  struct node *parent; // parent node. why is it a pointer? because it can be NULL. If it is not a pointer, then it will be a struct node type object. In that case, it can't be NULL. It will be a garbage value.
  //*pointer to the parent of the key 
  struct node *left; // left child
  struct node *right; // right child
};

struct node *T_root = NULL; // Empty tree 
//* T_root is a pointer to the root node of the tree. Initially, it is NULL. it is struct node type pointer.
struct node* createNode(int); // Create a new node with the given key value. It returns the pointer to the new node.
// struct node* is the return type. createNode is the function name. int is the parameter type.
// createNode is a function that takes an integer as input and returns a pointer to a struct node type object.

void BST_Insert(int); // Insert a key into the BST
void BST_InorderWalk(struct node*); // Inorder walk of the BST


//--------------------------------------------------------------------------
struct node* createNode(int key)
{
  struct node *newNode = (struct node*) malloc(1 * sizeof(struct node));

  newNode->key = key;

  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void BST_Insert(int key)
{

  struct node *zNode = createNode(key);

  struct node *xNode = T_root; // current node to compare with zNode
  struct node *yNode = NULL; // parent node to which zNode will be attached.

  while(xNode != NULL)
    {
      yNode = xNode;

      if(zNode->key < xNode->key)
        {
          xNode = xNode->left;
        }
      else
        {
          xNode = xNode->right;
        }
    }

  zNode->parent = yNode;

  if(yNode == NULL)
    {
      T_root = zNode;
    }
  else if(zNode->key < yNode->key)
    {
      yNode->left = zNode;
    }
  else
    {
      yNode->right = zNode;
    }
}


void BST_InorderWalk(struct node *xNode)
{

  if(xNode == NULL)
    return;

  BST_InorderWalk(xNode->left);
  printf("%d ", xNode->key);
  BST_InorderWalk(xNode->right);
  
}

//--------------------------------------------------------------------------
int main(void)
{
  BST_Insert(31);
  BST_Insert(31);
  BST_Insert(52);
  BST_Insert(11);
  BST_Insert(76);

  BST_InorderWalk(T_root);
  printf("\n");
  
  return 0;
}

