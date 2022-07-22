//To create an adjacency list.
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
struct node *arr[100]; //array of  linked lists.

void push(nodeptr *head, int *p, int *q) //push function.
{
    ptr = NULL;
    ptr = (nodeptr)(malloc(sizeof(struct node)));
    if (ptr != NULL)
    {
        ptr->num = *p;
        ptr->next = NULL;
        if (*head != NULL)
        {
            while ((*head)->next != NULL) //to move the head to the end.
            {
                *head = (*head)->next;
            }
            (*head)->next = ptr;
            *head = ptr;
        }
        if (*head == NULL)
        {
            *head = ptr;
            arr[*q] = *head;
        }
    }
    else
    {
        printf("Push Failure\n");
    }
}

void print(nodeptr *head) //print function.
{
    nodeptr temp;
    temp = *head;
    if (*head != NULL)
    {
        while (temp->next != NULL)
        {
            printf("%d ", (temp)->num);
            temp = (temp)->next;
        };
        printf("%d ", (temp)->num);
    }
    else
    {
        printf("Nil");
    }
}

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int m, n;
    int x, y;
    scanf("%d", &m);
    scanf("%d", &n);

    for (int i = 0; i < m; i++)
    {
        arr[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);

        int k;
        head = arr[x];
        push(&head, &y, &x);

        head = arr[y];
        push(&head, &x, &y);
    }
    for (int k = 0; k < m; k++)
    {
        print(&arr[k]);
        printf("\n");
    }
}