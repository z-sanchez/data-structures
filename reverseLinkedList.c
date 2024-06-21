// create node
// print list
// add to beginning
// add to end
// reverse list
// reverse recursivley

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node *next;
    int value;
} node_t;

node_t *createNode(int newValue);
void printList(node_t *head);
void addToBeginning(node_t **head, int newValue);
void addToEnd(node_t **head, int newValue);
node_t *reverseList(node_t *head);
node_t *reverseListRecursive(node_t *head);

int main()
{

    node_t *head = createNode(3);

    addToBeginning(&head, 2);
    addToBeginning(&head, 1);

    addToEnd(&head, 4);
    addToEnd(&head, 5);

    printList(head);

    node_t *reversedList = reverseList(head);

    printList(reversedList);

    node_t *reReversedList = reverseList(reversedList);

    printList(reReversedList);

    return 0;
}

node_t *createNode(int newValue)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->next = NULL;
    newNode->value = newValue;

    return newNode;
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

void addToBeginning(node_t **head, int newValue)
{
    node_t *newNode = createNode(newValue);
    newNode->next = *head;
    *head = newNode;
}

void addToEnd(node_t **head, int newValue)
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