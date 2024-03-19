#include <stdio.h>
#include <stdlib.h>

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
void appendWithoutTail(char value, linkedList_t *linkedList);
void appendWithTail(char value, linkedList_t *linkedList);
void freeList(linkedList_t *linkedList);
void deleteHead(linkedList_t *linkedList);
void deleteTail(linkedList_t *linkedList);
node_t *findNodeByIndex(linkedList_t *linkedList, int index);
void deleteNodeByIndex(linkedList_t *linkedList, int index);

int main()
{
    linkedList_t *list = initializeList();

    prepend('Z', list);
    prepend('I', list);
    appendWithoutTail('S', list);

    // not working when index is out of range
    deleteNodeByIndex(list, 3);
    printf("HEAD: %c |   TAIL:  %c \n", list->head->value, list->tail->value);

    printList(list);

    freeList(list);
    free(list);

    return 0;
}

/*
 * Allocate Memory For New Node
 * Check if Memory failed
 * Set Next
 * Set Value
 * Return Node
 */
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

/*
 * Allocate Memory For New List
 * Check if Memory failed
 * Create Node
 * Set Head to Node
 * Set Tail to Node
 * Return List
 */
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

/*
 * Check if head empty, if empty set head value, return
 * If head not empty:
 * Create Node
 * Set Next to be Head
 * Set Head to be Current Node
 * Return
 */
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

/*
 * Create current pointer
 * Check if the Node is empty
 * If not, print value, set current pointer to next
 */
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

/*
 * Check if head is empty
 * If empty, set head value, return
 * Create new node
 * If not empty, traverse list until you find a node with null next
 * Set next to new node
 * Set tail to new node
 */
void appendWithoutTail(char value, linkedList_t *linkedList)
{

    if (linkedList->head->value == NULL)
    {
        linkedList->head->value = value;
        return;
    }

    node_t *currentPtr = linkedList->head;
    node_t *newNode = createNode(value);

    while (currentPtr->next != NULL)
    {
        currentPtr = currentPtr->next;
    }

    currentPtr->next = newNode;
    linkedList->tail = newNode;
}

/*
 * Check head equals tail, if so they are the same so just set a value on head
 * If not
 * Create new node
 * Set tail's next to new node
 * Set tail to new node
 */
void appendWithTail(char value, linkedList_t *linkedList)
{
    if (linkedList->head == linkedList->tail)
    {
        linkedList->head->value = value;
        return;
    }

    node_t *newNode = createNode(value);

    linkedList->tail->next = newNode;
    linkedList->tail = newNode;
}

/*
 * Declare temp node
 * While head is not null
 * Set temp node to head
 * Set list's new head to head's next node
 * Free temp node which has the old head stored
 */
void freeList(linkedList_t *linkedList)
{
    node_t *temp;

    while (linkedList->head != NULL)
    {
        temp = linkedList->head;
        linkedList->head = linkedList->head->next;
        free(temp);
    }
}

/*
 * If head and tail are the same, set both to NULL, return
 * Create temp node
 * Set temp node to head
 * Set head to temp's next node
 * Free temp
 */
void deleteHead(linkedList_t *linkedList)
{
    if (linkedList->head == linkedList->tail)
    {
        linkedList->head = NULL;
        linkedList->tail = NULL;
        return;
    }

    node_t *temp;

    temp = linkedList->head;
    linkedList->head = temp->next;
    free(temp);
}

/*
 * If head and tail are the same, set both to NULL, return
 * Create pointer node
 * While pointer node's next does not equal tail
 * Set current node to next
 * Then set current node's next to NULL
 * Set tail to current node
 */
void deleteTail(linkedList_t *linkedList)
{

    if (linkedList->head == linkedList->tail)
    {
        linkedList->head = NULL;
        linkedList->tail = NULL;
        return;
    }

    node_t *currentPtr = linkedList->head;

    while (currentPtr->next != linkedList->tail)
    {
        currentPtr = currentPtr->next;
    }

    currentPtr->next = NULL;
    linkedList->tail = currentPtr;
}

/*
 * Create pointer node and set it to list's head
 * Set Iteration to zero
 * While iteration does not equal index
 * Set current node to next
 * Check if its null, if so, return null
 * Increment iteration by one
 * Return node once found
 */
node_t *findNodeByIndex(linkedList_t *linkedList, int index)
{
    node_t *currentNode = linkedList->head;
    int iteration = 0;

    while (iteration != index)
    {
        currentNode = currentNode->next;
        if (currentNode == NULL)
        {
            return NULL;
        }
        ++iteration;
    }

    return currentNode;
}

/*
 * Create pointer node and set it to list's head
 * Set Iteration to zero
 * While iteration does not equal index
 * Set current node to next
 * Check if its null, if so, return null
 * Increment iteration by one
 * Return node once found
 */
void deleteNodeByIndex(linkedList_t *linkedList, int index)
{
    node_t *currentNode = linkedList->head;
    node_t *temp;
    int iteration = 0;

    if (index == 0)
    {
        deleteHead(linkedList);
        return;
    }

    while (iteration != index - 1)
    {
        if (currentNode->next == NULL)
        {
            return;
        }
        currentNode = currentNode->next;
        ++iteration;
    }

    if (currentNode->next == linkedList->tail)
    {
        deleteTail(linkedList);
    }
    else
    {
        temp = currentNode->next;

        currentNode->next = currentNode->next->next;

        free(temp);
    }
}