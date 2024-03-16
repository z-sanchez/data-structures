#include <stdio.h>
#include <stdlib.h>

// create node
// create list
// prepend
// append (without tail)
// append (with tail)
// display list
// to array
// free list
// find
// delete head
// delete tail

typedef struct node
{
    char value;
    struct node *next;
} node_t;

typedef struct LinkedList
{
    node_t *head;
    node_t *tail;
} linkedList_t;

node_t *createNode(char value);
linkedList_t *initializeList();
void prepend(char value, linkedList_t *linkedList);
void printList(linkedList_t *linkedList_t);

int main()
{
    linkedList_t *list = initializeList();

    prepend('K', list);
    prepend('E', list);
    prepend('I', list);
    prepend('Z', list);

    printList(list);

    return 0;
}

node_t *createNode(char value)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    if (newNode == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY WHEN CREATING NEW NODE");
        exit(1);
    }

    newNode->next = NULL;
    newNode->value = value;

    return newNode;
}

linkedList_t *initializeList()
{
    linkedList_t *linkedList = (linkedList_t *)malloc(sizeof(linkedList_t));

    if (linkedList == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY WHEN CREATING NEW LIST");
        exit(1);
    }

    node_t *head = createNode(NULL);

    linkedList->head = head;
    linkedList->tail = head;

    return linkedList;
}

void prepend(char value, linkedList_t *linkedList)
{
    if (linkedList->head->value == NULL)
    {
        linkedList->head->value = value;
        return;
    }

    node_t *newNode = createNode(value);
    newNode->next = linkedList->head;
    linkedList->head = newNode;
}

void printList(linkedList_t *linkedList_t)
{
    node_t *current = linkedList_t->head;

    while (current != NULL)
    {
        printf("%c ", current->value);
        current = current->next;
    }

    printf("\n");
}