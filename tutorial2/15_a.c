#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};
int p, q;
typedef struct node *nodeptr;
nodeptr ptr;
nodeptr head = NULL;

void push(nodeptr *head, int *a)
{
    ptr = (nodeptr)(malloc(sizeof(struct node)));
    if (ptr != NULL)
    {
        ptr->num = *a;
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
int pop(nodeptr *head, int *a)
{
    if (*head != NULL)
    {
        nodeptr temp;
        temp = *head;
        *a = temp->num;
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
int main()
{
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        push(&head, &a);
    }
    pop(&head, &p);
    pop(&head, &q);
    push(&head, &p);
    push(&head, &q);
    nodeptr temp;
    temp = head;
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}