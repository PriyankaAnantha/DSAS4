/* Doubly Linked List */
#include <stdio.h>
#include <stdlib.h>

// P1: 5x^3 + 4x^2 + 6x^1
// P2: 6x^5 + 3x^2 + 4x^1
// Result of addition, P3: 6x^5 + 5x^3 + 7x^2 + 10x^1

/* Global Variable Declarations */
struct node
{
  int coeff;
  int degree;
  struct node *prev;
  struct node *next;
};

//struct node *L_head = NULL; // Empty List

/* List operations */

void printList(struct node*);
void LIST_APPEND(struct node**, int, int);      // Inserting a new last element.
struct node *createNode(int, int);  // Creates a new node and initialize the key.

int main(void)
{
  struct node *p_head1 = NULL;
  LIST_APPEND(&p_head1, 5, 3);
  LIST_APPEND(&p_head1, 4, 2);
  LIST_APPEND(&p_head1, 6, 1);
  
  printList(p_head1);

  struct node *p_head2 = NULL;
  LIST_APPEND(&p_head2, 6, 5);
  LIST_APPEND(&p_head2, 3, 2);
  LIST_APPEND(&p_head2, 4, 1);
  
  printList(p_head2);

  return 0;
}

void printList(struct node *L_head)
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

    while(tmpHead != NULL)
    {
      printf("%dx^%d ", tmpHead->coeff, tmpHead->degree);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }

  return;
}

struct node *createNode(int coeff, int degree)
{
  /* malloc the new node and typecast the address to struct node ptr. */
  /* Set the key with x, prev and next to NULL */

  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->coeff = coeff;
  newNode->degree = degree;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}


void LIST_APPEND(struct node **L_head, int coeff, int degree)
{
  /* Navigate to the last node and update its next pointer to link the new node. */
  /* If the list was empty, then head will point to the new node. */

  struct node *newNode = createNode(coeff, degree);

  if (*L_head == NULL)
  {
    *L_head = newNode;
    return;
  }

  /* To navigate to the last node of current list */
  struct node *lastNode = *L_head;
  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
  }

  /* Next pointer of lastNode should point to the new node. */
  /* Previous pointer of the new node should point to lastNode */

  lastNode->next = newNode;
  newNode->prev = lastNode;

  return;
}

