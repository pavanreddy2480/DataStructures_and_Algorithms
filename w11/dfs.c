// This program performs dfs on the adj_list.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node // creates the node for linked list.
{
    //    struct node *prv;
    int num;
    struct node *next;
};

typedef struct node *nodeptr;
nodeptr ptr;
nodeptr curptr, head = NULL;
int clock = 0;
int entry[100];
int visited[100];
int Exit[100];
struct node *arr[100];

void push(nodeptr *head, int *p, int *q) // push function.
{
    ptr = NULL;
    ptr = (nodeptr)(malloc(sizeof(struct node)));
    if (ptr != NULL)
    {
        ptr->num = *p;
        ptr->next = NULL;
        if (*head != NULL)
        {
            while ((*head)->next != NULL) // to move the head to the end.
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

void print(nodeptr *head) // print function.
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

void dfs(nodeptr arr[], int m) // runs dfs.
{
    nodeptr head;
    visited[m] = 1; // visiting the node.
    head = arr[m];
    entry[m] = clock; // entering the clock.
    clock++;
    while (head != NULL)
    {
        if (visited[head->num] == 0) // it not visited.
        {
            visited[head->num] = 1;
            dfs(arr, head->num);
        }
        head = head->next;
    }
    Exit[m] = clock;
    clock++;
}
void depthfirstsearch(nodeptr arr[], int n) // to make sure that we have visited all the connected components.
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(arr, i);
        }
    }
}

int main()
{
    int m, n, p;
    int x, y;
    scanf("%d", &m);
    scanf("%d", &n);

    memset(visited, 0, m * sizeof(visited[0])); // setting all the values in the array to '0'.

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
        push(&head, &x, &y); // until now the adj_list is created.
    }
    scanf("%d", &p);
    dfs(arr, p);
    depthfirstsearch(arr, m);

    for (int i = 0; i < m; i++)
    {
        printf("%d %d\n", entry[i], Exit[i]);
    }
}
