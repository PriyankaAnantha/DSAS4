#include <stdio.h>
#include <stdlib.h>

struct node
{
  int key;

  struct node *parent;
  struct node *left;
  struct node *right;
};

struct node *T_root = NULL; // Empty tree

void BST_Insert(int);
void BST_InorderWalk(struct node*);

struct node* createNode(int);

int main(void)
{
  BST_Insert(31);
  BST_Insert(26);
  BST_Insert(52);
  BST_Insert(11);
  BST_Insert(76);

  BST_InorderWalk(T_root);
  printf("\n");
  
  return 0;
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

struct node* createNode(int key)
{
  struct node *newNode = (struct node*) malloc(1 * sizeof(struct node));

  newNode->key = key;

  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void BST_InorderWalk(struct node *xNode)
{

  if(xNode == NULL)
    return;

  BST_InorderWalk(xNode->left);
  printf("%d ", xNode->key);
  BST_InorderWalk(xNode->right);
  
}
