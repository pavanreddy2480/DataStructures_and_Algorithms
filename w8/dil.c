#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int num;
    struct node *next;
};

typedef struct node *nodeptr;
nodeptr ptr, head = NULL, tail = NULL;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        ptr = (nodeptr)(malloc(sizeof(struct node)));
        if (ptr == NULL)
        {
            printf("Failure In Alloting Memory\n");
        }
        else
        {
            scanf("%d", &(ptr->num));
            ptr->prev = NULL;
            ptr->next = NULL;
            if (head == NULL)
            {
                head = ptr;
                tail = ptr;
            }
            else
            {
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
            }
        }
    }

    nodeptr temp1, temp2;
    temp1 = head;
    temp2 = tail;

    while (tail != NULL)
    {
        printf("%d\n", tail->num);
        tail = tail->prev;
    }

    while (head != NULL)
    {
        printf("%d\n", head->num);
        head = head->next;
    }

    head = temp2;
    tail = temp1;

    head = head->prev;
    head->next = NULL;
    tail = tail->next;
    tail->prev = NULL;

    free(temp1);
    free(temp2);

    while (head != NULL)
    {
        printf("%d\n", head->num);
        head = head->prev;
    }
    while (tail != NULL)
    {
        printf("%d\n", tail->num);
        tail = tail->next;
    }
}