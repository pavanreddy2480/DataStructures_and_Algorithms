#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr ptr;
nodeptr tail = NULL, head = NULL;

void enqueue(nodeptr *head, nodeptr *tail)
{
    ptr = (nodeptr)(malloc(sizeof(struct node)));
    if (ptr == NULL)
    {
        printf("Enqueue Failure\n");
    }
    else
    {
        scanf("%d", &ptr->num);
        ptr->next = NULL;
        if (*head == NULL)
        {
            *head = ptr;
            *tail = ptr;
        }
        else
        {
            (*head)->next = ptr;
            *head = ptr;
        }
    }
}

void dequeue(nodeptr *head, nodeptr *tail)
{
    if (*head != NULL)
    {
        nodeptr temp;
        if (*head == *tail)
        {
            temp = *head;
            *head = NULL;
            *tail = NULL;
            printf("%d\n", temp->num);
            free(temp);
        }
        else
        {
            temp = *tail;
            *tail = (*tail)->next;
            printf("%d\n", temp->num);
            free(temp);
        }
    }
    else
    {
        printf("Dequeue Failure\n");
    }
}
void peek(nodeptr *head, nodeptr *tail)
{
    if (*head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        printf("%d\n", (*tail)->num);
    }
}
void display(nodeptr *head, nodeptr *tail)
{
    nodeptr temp;
    temp = *tail;
    if (*head != NULL)
    {
        while (temp != NULL)
        {
            printf("%d\n", temp->num);
            temp = temp->next;
        }
    }
    else
    {
        printf("Empty List\n");
    }
}

int main()
{
    int a;
    while (1)
    {
        scanf("%d", &a);
        if (a == 0)
        {
            if (head == NULL)
            {
                printf("Empty\n");
            }
            else
            {
                printf("Non Empty\n");
            }
        }
        else if (a == 1)
        {
            enqueue(&head, &tail);
        }
        else if (a == 2)
        {
            dequeue(&head, &tail);
        }
        else if (a == 3)
        {
            peek(&head, &tail);
        }
        else if (a == 4)
        {
            display(&head, &tail);
        }
        else if (a == 5)
        {
            break;
        }
    }
}