#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node_t;

node_t *createNode(int newValue);
void printList(node_t *head);
void insertAtBeginningOfList(node_t **head, int newValue);
void insertAtEndOfList(node_t **head, int newValue);
node_t *reverseList(node_t *head);
node_t *reverseListRecursive(node_t *head);

int main()
{
    node_t *head = createNode(3);
    insertAtBeginningOfList(&head, 2);
    insertAtBeginningOfList(&head, 1);
    insertAtEndOfList(&head, 4);
    insertAtEndOfList(&head, 5);

    node_t *reversedList = reverseList(head);

    printList(reversedList);

    node_t *reReversedList = reverseList(reversedList);

    printList(reReversedList);

    return 0;
}

node_t *createNode(int newValue)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->value = newValue;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginningOfList(node_t **head, int newValue)
{
    node_t *newNode = createNode(newValue);
    node_t *temp = *head;

    newNode->next = temp;
    *head = newNode;
}

void insertAtEndOfList(node_t **head, int newValue)
{
    node_t *newNode = createNode(newValue);
    node_t *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

node_t *reverseList(node_t *head)
{
    node_t *newList = NULL;
    node_t *current = head;

    while (current != NULL)
    {
        node_t *nextNode = current->next;

        current->next = newList;
        newList = current;

        current = nextNode;
    }

    return newList;
}

node_t *reverseListRecursive(node_t *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        return head;
    }

    node_t *restOfList = reverseListRecursive(head->next);

    head->next->next = head;
    head->next = NULL;

    return restOfList;
}

void printList(node_t *head)
{
    node_t *current = head;

    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
