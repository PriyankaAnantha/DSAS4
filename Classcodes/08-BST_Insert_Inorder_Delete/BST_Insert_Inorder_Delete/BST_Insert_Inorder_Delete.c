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

struct node* createNode(int);

void BST_Insert(int);
void BST_InorderWalk(struct node*);


struct node* BST_Minimum(struct node*);
struct node* BST_Maximum(struct node*);
struct node* BST_TreeSearch(struct node*, int);

void BST_Transplant(struct node*, struct node*);
void BST_Delete(struct node*);


//****************************************************************************
struct node* BST_Minimum(struct node *xNode)
{
  while(xNode->left != NULL)
    xNode = xNode->left;

  return xNode;
}

struct node* BST_Maximum(struct node *xNode)
{
  while(xNode->right != NULL)
    xNode = xNode->right;

  return xNode;
}


struct node* BST_TreeSearch(struct node *xNode, int key)
{
  
  while(xNode != NULL && key != xNode->key)
    {
      if(key < xNode->key)
        xNode = xNode->left;
      else
        xNode = xNode->right;
    }

  return xNode;
  
}

void BST_Transplant(struct node *u, struct node *v)
{
  if(u->parent == NULL)
    T_root = v;
  if(u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;

  if(v != NULL)
    v->parent = u->parent;

  return;
}

void BST_Delete(struct node *zNode)
{
  if(zNode->left == NULL)
    BST_Transplant(zNode, zNode->right);
  else if(zNode->right == NULL)
    BST_Transplant(zNode, zNode->left);
  else
    {
      struct node *yNode = BST_Minimum(zNode->right);

      if(yNode != zNode->right)
        {
          BST_Transplant(yNode, yNode->right);
          yNode->right = zNode->right;
          yNode->right->parent = yNode;
        }
      BST_Transplant(zNode, yNode);
      yNode->left = zNode->left;
      yNode->left->parent = yNode;
      
    }

  free(zNode);
  
}
//****************************************************************************



int main(void)
{
  BST_Insert(31);
  BST_Insert(26);
  BST_Insert(52);
  BST_Insert(11);
  BST_Insert(76);

  BST_InorderWalk(T_root);
  printf("\n");

  struct node *xNode = BST_Minimum(T_root);

  if(xNode != NULL)
    printf("Minimum: %d\n", xNode->key);
  else
    printf("Tree is Empty");


  xNode = BST_Maximum(T_root);

  if(xNode != NULL)
    printf("Maximum: %d\n", xNode->key);
  else
    printf("Tree is Empty");

  int xVal = 0;
  printf("Enter a value to search:");
  scanf("%d", &xVal);

  xNode = BST_TreeSearch(T_root, xVal);

  if(xNode != NULL)
    {
      printf("%d is found in node %p\n", xVal, xNode);
    }
  else
    printf("%d not found in the tree\n", xVal);

  printf("Enter the value to delete:");
  scanf("%d", &xVal);

  struct node *zNode = BST_TreeSearch(T_root, xVal);
    
  BST_Delete(zNode);

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


