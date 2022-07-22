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
nodeptr root = NULL, curptr = NULL, temp = NULL, temp2 = NULL;
int a, b;
int m, n;

void insert(nodeptr *root, int *m)
{
    temp = (struct node *)(malloc(sizeof(struct node)));
    if (temp == NULL)
    {
        printf("Error\n");
        return;
    }
    else
    {
        temp->key = *m;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = NULL;

        if (*root == NULL)
        {
            *root = temp;
        }
        else
        {
            if ((*root)->key > *m)
            {
                if ((*root)->left == NULL)
                {
                    (*root)->left = temp;
                    temp->parent = *root;
                }
                else
                {
                    insert(&((*root)->left), &(*m));
                }
            }
            else if ((*root)->key <= *m)
            {
                if ((*root)->right == NULL)
                {
                    (*root)->right = temp;
                    temp->parent = *root;
                }
                else
                {
                    insert(&((*root)->right), &(*m));
                }
            }
        }
    }
}
void search(nodeptr *root, int *m)
{
    b = 0;
    temp2 = NULL;
    curptr == NULL;
    if ((*root)->key == *m)
    {
        b = 1;
        curptr = *root;
    }
    else
    {
        temp2 = *root;
        if ((*root)->key > *m)
        {
            if ((*root)->left == NULL)
            {
                //printf("Not Found\n");
                b = -1;
            }
            else
            {
                search(&((*root)->left), &(*m));
            }
        }
        else if ((*root)->key < *m)
        {
            if ((*root)->right == NULL)
            {
                //printf("Not Found\n");
                b = -1;
            }
            else
            {
                search(&((*root)->right), &(*m));
            }
        }
    }
}
void inorder(nodeptr root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\n", root->key);
    inorder(root->right);
}
void preorder(nodeptr root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\n", root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(nodeptr root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->key);
}
void findsuc(nodeptr root, int m)
{
    curptr = NULL;
    search(&root, &m);
    if (curptr == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    //curptr = curptr->right;
    if (curptr->right == NULL)
    {
        if (curptr->parent == NULL)
        {
            printf("No successor\n");
            return;
        }

        else if (curptr->parent->key > m)
        {
            curptr = curptr->parent;
            while (curptr->parent != NULL)
            {
                if (curptr->parent->key > curptr->key)
                {
                    break;
                }
                curptr = curptr->parent;
            }
            printf("%d\n", curptr->key);
            return;
        }
        else
        {
            printf("No successor\n");
            return;
        }
    }

    curptr = curptr->right;
    while (curptr->left != NULL)
    {
        curptr = curptr->left;
    }
    printf("%d\n", curptr->key);
    return;
}
void findpre(nodeptr root, int m)
{
    curptr = NULL;
    search(&root, &m);
    if (curptr == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if (curptr->left == NULL)
    {
        if (curptr->parent == NULL)
        {
            printf("No predecessor\n");
            return;
        }

        else if (curptr->parent->key < m)
        {
            curptr = curptr->parent;
            while (curptr->parent != NULL)
            {
                if (curptr->parent->key < curptr->key)
                {
                    break;
                }
                curptr = curptr->parent;
            }
            printf("%d\n", curptr->key);
            return;
        }
        else
        {
            printf("No predecessor\n");
            return;
        }
    }

     curptr = curptr->left;
    while (curptr->right != NULL)
    {
        curptr = curptr->right;
    }
    printf("%d\n", curptr->key);
}

int main()
{

    while (1)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &m);
            insert(&root, &m);
        }
        else if (a == 2)
        {
            scanf("%d", &m);
            search(&root, &m);
            if (b == 1)
            {
                printf("Found\n");
            }
            else if (b == -1)
            {
                printf("Not Found\n");
            }
        }
        else if (a == 3)
        {
            inorder(root);
        }
        else if (a == 4)
        {
            preorder(root);
        }
        else if (a == 5)
        {
            postorder(root);
        }
        else if (a == 6)
        {
            scanf("%d", &m);
            findpre(root, m);
        }
        else if (a == 7)
        {
            scanf("%d", &m);
            findsuc(root, m);
        }
        else if (a == 8)
        {
            break;
        }
    }
}