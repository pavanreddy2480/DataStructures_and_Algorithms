//This program helps us to create Binary Search Tree and perform some operations on it.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
};

typedef struct node *nodeptr;
nodeptr root = NULL, temp = NULL;

int a;
int m;

void insert(nodeptr *root, int m) //Insert Functiion.
{
    temp = (struct node *)(malloc(sizeof(struct node)));
    if (temp == NULL)
    {
        printf("Error\n");
        return;
    }
    else
    {
        temp->key = m;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = NULL;

        if (*root == NULL)
        {
            *root = temp;
        }
        else
        {
            if ((*root)->key > m)
            {
                if ((*root)->left == NULL)
                {
                    (*root)->left = temp;
                    temp->parent = *root;
                }
                else
                {
                    insert(&((*root)->left), (m));
                }
            }
            else if ((*root)->key <= m)
            {
                if ((*root)->right == NULL)
                {
                    (*root)->right = temp;
                    temp->parent = *root;
                }
                else
                {
                    insert(&((*root)->right), (m));
                }
            }
        }
    }
}

nodeptr search(nodeptr *root, int m) //search Function.
{
    if (*root == NULL)
    {
        return NULL;
    }
    if ((*root)->key == m)
    {
        return *root;
    }

    if ((*root)->key > m)
    {
        search(&(*root)->left, m);
    }
    else
    {
        search(&(*root)->right, m);
    }
}

void inorder(nodeptr *root) //In Order.
{
    if (*root == NULL)
    {
        return;
    }
    inorder(&(*root)->left);
    printf("%d\n", (*root)->key); //root is at the middle.
    inorder(&(*root)->right);
}

void preorder(nodeptr *root) // Pre-Order
{
    if (*root == NULL)
    {
        return;
    }
    printf("%d\n", (*root)->key); //root is at the start.
    preorder(&(*root)->left);
    preorder(&(*root)->right);
}

void postorder(nodeptr *root) //Post Order
{
    if (*root == NULL)
    {
        return;
    }
    postorder(&(*root)->left);
    postorder(&(*root)->right);
    printf("%d\n", (*root)->key); //root is at the end.
}

nodeptr findsuc(nodeptr *root, int m) //to find successor.
{
    nodeptr curptr;
    curptr = NULL;
    curptr = search(&(*root), m);

    if (curptr == NULL)
    {
        printf("Invalid Input\n");
        return NULL;
    }
    if (curptr->right == NULL)
    {
        if (curptr->parent == NULL)
        {
            printf("No successor\n");
            return NULL;
        }

        else if (curptr->parent->key > m)
        {
            curptr = curptr->parent;
            if (curptr->key < curptr->parent->key)
            {
                return curptr;
            }
            while (curptr->parent != NULL)
            {
                if (curptr->parent->key < m)
                {
                    break;
                }
                curptr = curptr->parent;
            }
            return curptr;
        }

        else
        {
            printf("No successor\n");
            return NULL;
        }
    }

    curptr = curptr->right;
    while (curptr->left != NULL)
    {
        curptr = curptr->left;
    }
    return curptr;
}

nodeptr findpre(nodeptr *root, int m) //to  find predecessor.
{
    nodeptr curptr;
    curptr = NULL;
    curptr = search(&(*root), m);

    if (curptr == NULL)
    {
        printf("Invalid Input\n");
        return NULL;
    }
    if (curptr->left == NULL)
    {
        if (curptr->parent == NULL)
        {
            printf("No predecessor\n");
            return NULL;
        }

        else if (curptr->parent->key < m)
        {
            curptr = curptr->parent;
            if (curptr->key > curptr->parent->key)
            {
                return curptr;
            }
            while (curptr->parent != NULL)
            {
                if (curptr->parent->key > m)
                {
                    break;
                }
                curptr = curptr->parent;
            }
            return curptr;
        }

        else
        {
            printf("No predecessor\n");
            return NULL;
        }
    }

    curptr = curptr->left;
    while (curptr->right != NULL)
    {
        curptr = curptr->right;
    }
    return curptr;
}

void check(int n)
{
    if (n == 2)
    {
        nodeptr p = search(&root, m);
        if (p != NULL)
        {
            printf("Found\n");
        }
        else if (p == NULL)
        {
            printf("Not Found\n");
        }
    }
    else if (n == 6)
    {
        nodeptr p;
        p = findpre(&root, m);
        if (p != NULL)
        {
            printf("%d\n", p->key);
        }
    }
    else if (n == 7)
    {
        nodeptr p;
        p = findsuc(&root, m);
        if (p != NULL)
            printf("%d\n", p->key);
    }
}

int main()
{

    while (1)
    {
        scanf("%d", &a);

        if (a == 1)
        {
            scanf("%d", &m);
            insert(&root, m);
        }
        else if (a == 2)
        {
            scanf("%d", &m);
            check(2);
        }
        else if (a == 3)
        {
            inorder(&root);
        }
        else if (a == 4)
        {
            preorder(&root);
        }
        else if (a == 5)
        {
            postorder(&root);
        }
        else if (a == 6)
        {
            scanf("%d", &m);
            check(6);
        }
        else if (a == 7)
        {
            scanf("%d", &m);
            check(7);
        }
        else if (a == 8)
        {
            break;
        }
    }
}