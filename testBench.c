#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char value[100];
    struct node *next;
} node_t;

void printList(node_t *head);
node_t *createNode(char *newValue);
void addToBeginning(node_t **head, char *newValue);
void addToEnd(node_t **head, char *newValue);
void reverseList(node_t **head);
node_t *reverseListRecursive(node_t *head);
node_t *deleteMiddleNode(node_t *head);
node_t *deleteMiddleAlt(node_t *head);

int main()
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    strcpy(head->value, "Ziek");

    addToBeginning(&head, (char *)"Mimi");
    addToEnd(&head, (char *)"Bella");
    addToEnd(&head, (char *)"Bob");
    addToEnd(&head, (char *)"Bob2");
    addToEnd(&head, (char *)"Bob3");
    addToEnd(&head, (char *)"Bob4");
    addToEnd(&head, (char *)"Bob5");
    addToEnd(&head, (char *)"Bob6");
    addToEnd(&head, (char *)"Bob7");
    addToEnd(&head, (char *)"Bob8");

    printList(head);

    // reverseList(&head);

    // printList(head);

    // node_t *newList = reverseListRecursive(head);

    // printList(newList);
    printf("DELETING \n");

    deleteMiddleAlt(head);

    printList(head);

    return 0;
}

void printList(node_t *head)
{
    node_t *current = head;

    while (current != NULL)
    {
        printf("%s\n", current->value);
        current = current->next;
    }
}

node_t *createNode(char *newValue)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    strcpy(newNode->value, newValue);

    return newNode;
}

void addToBeginning(node_t **head, char *newValue)
{
    node_t *newNode = createNode(newValue);
    newNode->next = *head;
    *head = newNode;
}

void addToEnd(node_t **head, char *newValue)
{
    node_t *newNode = createNode(newValue);
    node_t *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

void reverseList(node_t **head)
{
    node_t *current = *head;
    node_t *newList = NULL;

    while (current != NULL)
    {
        node_t *nextNode = current->next;

        current->next = newList;

        newList = current;

        current = nextNode;
    }

    *head = newList;
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

node_t *deleteMiddleNode(node_t *head)
{
    int counter = 0;
    node_t *current = head;

    while (current != NULL)
    {
        current = current->next;
        ++counter;
    }

    int deleteIndex = counter / 2;

    current = head;

    for (int i = 0; i < counter; i++)
    {
        if (i == deleteIndex - 1)
        {
            current->next = current->next->next;
            break;
        }
        current = current->next;
    }

    return head;
}

// tortoise and hare algorithm
node_t *deleteMiddleAlt(node_t *head)
{
    if (!head->next)
        return NULL;

    node_t *fast = head->next;
    node_t *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        if (!fast)
            break;
        slow = slow->next;
    }
    node_t *q = slow->next;
    slow->next = slow->next->next;
    free(q);
    return head;
}