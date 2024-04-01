
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node
{
    int coeff;              // Coefficient of the polynomial term
    int degree;             // Degree of the polynomial term
    struct node *prev;      // Pointer to the previous node in the list
    struct node *next;      // Pointer to the next node in the list
};

// Function to print the polynomial list
void printList(struct node*, const char*);

// Function to append a new node to the polynomial list
void LIST_APPEND(struct node**, int, int);

// Function to create a new node with given coefficient and degree
struct node *createNode(int, int);

// Function to add two polynomials and return the resulting polynomial
struct node *addPolynomials(struct node*, struct node*);

int main(void)
{
    // Create the first polynomial list
    struct node *p_head1 = NULL;
    LIST_APPEND(&p_head1, 5, 3);
    LIST_APPEND(&p_head1, 4, 2);
    LIST_APPEND(&p_head1, 6, 1);
    
    // Print the first polynomial list
    printList(p_head1, "P1");

    // Create the second polynomial list
    struct node *p_head2 = NULL;
    LIST_APPEND(&p_head2, 6, 5);
    LIST_APPEND(&p_head2, 3, 2);
    LIST_APPEND(&p_head2, 4, 1);
    
    // Print the second polynomial list
    printList(p_head2, "P2");

    // Add the two polynomials and store the result in a new list
    struct node *p_head3 = addPolynomials(p_head1, p_head2);
    
    // Print the resulting polynomial list
    printList(p_head3, "P3");

    return 0;
}

// Function to print the polynomial list
void printList(struct node *L_head, const char* listName)
{
    if (L_head == NULL)
    {
        printf("%s is empty\n", listName);
    }
    else
    {
        printf("%s:\n", listName);
        struct node *tmpHead = L_head;

        while(tmpHead != NULL)
        {
            printf("%dx^%d ", tmpHead->coeff, tmpHead->degree);
            tmpHead = tmpHead->next;
            if (tmpHead != NULL)
            {
                printf("+ ");
            }
        }
        printf("\n");
    }

    return;
}

// Function to create a new node with given coefficient and degree
struct node *createNode(int coeff, int degree)
{
    struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
    newNode->coeff = coeff;
    newNode->degree = degree;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Function to append a new node to the polynomial list
void LIST_APPEND(struct node **L_head, int coeff, int degree)
{
    struct node *newNode = createNode(coeff, degree);

    if (*L_head == NULL)
    {
        *L_head = newNode;
        return;
    }

    struct node *lastNode = *L_head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->prev = lastNode;

    return;
}

// Function to add two polynomials and return the resulting polynomial
struct node *addPolynomials(struct node *p_head1, struct node *p_head2)
{
    struct node *p_head3 = NULL;
    struct node *p1 = p_head1;
    struct node *p2 = p_head2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->degree > p2->degree)
        {
            LIST_APPEND(&p_head3, p1->coeff, p1->degree);
            p1 = p1->next;
        }
        else if (p1->degree < p2->degree)
        {
            LIST_APPEND(&p_head3, p2->coeff, p2->degree);
            p2 = p2->next;
        }
        else
        {
            int sumCoeff = p1->coeff + p2->coeff;
            LIST_APPEND(&p_head3, sumCoeff, p1->degree);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        LIST_APPEND(&p_head3, p1->coeff, p1->degree);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        LIST_APPEND(&p_head3, p2->coeff, p2->degree);
        p2 = p2->next;
    }

    return p_head3;
}
