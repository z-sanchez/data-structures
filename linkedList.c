#include <stdio.h>
#include <stdlib.h>

// construct node
// construct list
// prepend
// append
// traverse
// find
// delete head
// to array

struct Node
{
    char value;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
    struct Node *tail;
};

void append(char value, struct LinkedList *linkedList);
void insertAtBegin(char value, struct LinkedList *linkedList);

int main()
{

    struct LinkedList linkedList;
    struct Node *headNode = (struct Node *)malloc(sizeof(struct Node));

    headNode->next = NULL;
    headNode->value = NULL;

    linkedList.head = headNode;
    linkedList.tail = headNode;

    insertAtBegin('j', &linkedList);
    append('k', &linkedList);
    append('s', &linkedList);

    printf("HELLO TESTING.... %c | %c | %c \n", linkedList.head->value, linkedList.head->next->value, linkedList.head->next->next->value);

    return 0;
}

void insertAtBegin(char value, struct LinkedList *linkedList)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = linkedList->head->next;
    linkedList->head = newNode;
}

void append(char value, struct LinkedList *linkedList)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    struct Node *ptr = linkedList->head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    // linkedList->tail = ptr;
}