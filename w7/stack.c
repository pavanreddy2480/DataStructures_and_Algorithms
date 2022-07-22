#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr ptr;
nodeptr curptr, head = NULL;

void push(nodeptr *head)
{
    ptr = (nodeptr)(malloc(sizeof(struct node)));
    if (ptr != NULL)
    {
        scanf("%d", &(ptr->num));
        ptr->next = NULL;
        if (*head != NULL)
        {
            ptr->next = *head;
            *head = ptr;
        }
        if (*head == NULL)
        {
            *head = ptr;
        }
    }
    else
    {
        printf("Push Failure\n");
    }
}
void pop(nodeptr *head)
{
    if (*head != NULL)
    {
        nodeptr temp;
        temp = *head;
        *head = (*head)->next;
        printf("%d\n", temp->num);
        free(temp);
    }
    else
    {
        printf("Pop Failure\n");
    }
}
void top(nodeptr *head)
{
    printf("%d\n", (*head)->num);
}
void print(nodeptr *head)
{
    nodeptr temp;
    temp = *head;
    if (*head != NULL)
    {
        while (temp != NULL)
        {
            printf("%d\n", (temp)->num);
            temp = (temp)->next;
        };
    }
    else
    {
        printf("Empty List\n");
    }
}
int main()
{
    int a, b;

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
            push(&head);
        }
        else if (a == 2)
        {
            pop(&head);
        }
        else if (a == 3)
        {
            top(&head);
        }
        else if (a == 4)
        {
            print(&head);
        }
        else if (a == 5)
        {
            break;
        }
    }
}