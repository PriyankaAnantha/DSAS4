/* Singly Linked List */
#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */
struct node
{
  int key;
  struct node *next;
};

struct node *L_head = NULL; // Empty List

/* List operations */

void printList();
void LIST_PREPEND(int);     // Inserting a new first element.
void LIST_APPEND(int);      // Inserting a new last element.
void LIST_INSERT(int, int); // inserts x next to y.
void LIST_DELETE(int);      // Find the node containing value and remove the node.

struct node *LIST_SEARCH(int); //  Find the node containing the data.
struct node *createNode(int);  // Creates a new node and initialize the key.

int main(void)
{
  char option = '\0';

  printf("------------------------\n");
  printf("---Singly Linked List---\n");
  printf("Show: S\n");
  printf("LIST-PREPEND: 1\n");
  printf("LIST-APPEND: 2\n");
  printf("LIST-INSERT: 3\n");
  printf("LIST-DELETE: 4\n");
  printf("EXIT: E\n");
  printf("------------------------\n");

  while (1)
  {

    printf("Enter your option: ");
    scanf(" %c", &option);

    switch (option)
    {
    case 'S':
      printf("Displaying the list\n\n");
      printList();

      break;

    case '1':
      printf("Enter the element to prepend the list: ");
      int x = 0;
      scanf("%d", &x);
      LIST_PREPEND(x);

      break;

    case '2':
      printf("Enter the element to append the list: ");
      x = 0;
      scanf("%d", &x);
      LIST_APPEND(x);

      break;

    case '3':
      printf("Enter the value after:");
      int y = 0;
      scanf("%d", &y);

      x = 0;
      printf("Enter the new value to insert: ");
      scanf("%d", &x);

      LIST_INSERT(x, y); // insert x next to y

      break;

    case '4':
      printf("Enter the value to delete:");
      y = 0;
      scanf("%d", &y);

      LIST_DELETE(y); // Find the node containing y and delete it.

      break;

    case 'E':
      printf("Exit\n\n");
      exit(0);

    default:
      printf("Enter correct option\n\n");
    }
  }

  return 0;
}

void printList()
{
  /* Check whether the list is empty or not. */
  /* If not empty, create a temporary pointer which starts
     from head and navigates until there is no next node. */
  /* The terminating condition is until this temp pointer is NULL. */
  /* Update the temp pointer with the next pointer of current node. */

  if (L_head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    printf("List elements:\n");
    struct node *tmpHead = L_head;

    while (tmpHead != NULL)
    {
      printf("[%p] ==> %d --> %p\n",
             tmpHead, tmpHead->key, tmpHead->next);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }

  return;
}

struct node *createNode(int x)
{
  /* malloc the new node and typecast the address to struct node ptr. */
  /* Set the key with x and next to NULL */

  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->key = x;
  newNode->next = NULL;

  return newNode;
}

void LIST_PREPEND(int x)
{

  /* Create a new node with the key initialized using the value in x. */
  /* Since  this node is always going to be the first node, the next pointer is NULL. */

  struct node *newNode = createNode(x);

  newNode->next = L_head; // Whatever head was pointing to.

  /* Head should now point to the new node. */
  L_head = newNode; // Now head should point to the new node.

  printf("First element: %d\n", L_head->key);
}

void LIST_APPEND(int x)
{
  /* Navigate to the last node and update its next pointer to link the new node. */
  /* If the list was empty, then head will point to the new node. */

  struct node *newNode = createNode(x);

  if (L_head == NULL)
  {
    L_head = newNode;
    return;
  }

  /* To navigate to the last node of current list */
  struct node *lastNode = L_head;
  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
  }

  /* Next pointer of lastNode should point to the new node. */

  lastNode->next = newNode;

  return;
}

void LIST_INSERT(int x, int y)
{

  /* Find the node which contains y. */
  /* Create a new node which stores x and then place is next to the node containing y */
  struct node *yNode = LIST_SEARCH(y);

  /* If values doen't exist, then print message and return */
  if (yNode == NULL)
  {
    printf("The value %d do not exist in list\n", y);
    return;
  }
  printf("%p ==> %d\n", yNode, yNode->key);

  struct node *newNode = createNode(x);

  /* Update next pointer of new node. */
  newNode->next = yNode->next;

  yNode->next = newNode;

  return;
}

struct node *LIST_SEARCH(int y)
{
  /* Check whether the list is empy */
  struct node *yNode = L_head;

  if (L_head == NULL)
  {
    printf("Empty list\n");
    return NULL;
  }
  else
  {
    while (yNode != NULL && yNode->key != y)
    {
      printf("%p --> %d\n", yNode, yNode->key);
      yNode = yNode->next;
    }

    return yNode;
  }
}

void LIST_DELETE(int y)
{
  /* Find the node containing y */

  struct node *yNode = LIST_SEARCH(y);

  if (yNode == NULL)
  {
    printf("The value %d do not exist\n", y);
    return;
  }

  /* If it is not the first node */
  if (yNode != L_head)
  {
    struct node *prevNode = L_head;
    while (prevNode->next != yNode)
    {
      prevNode = prevNode->next;
    }
    prevNode->next = yNode->next;
  }
  else
  {
    L_head = yNode->next;
  }

  free(yNode);

  return;
}
