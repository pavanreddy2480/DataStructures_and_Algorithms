//Creates an expression tree.
#include <stdio.h>
#include <stdlib.h>

struct node //Node for the binary search tree.
{
    char key;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct stack //Node for the stack.
{
    struct node *adds;
    struct stack *next;
};

typedef struct node *nodeptr;
struct stack *head = NULL; // temp3 = NULL;
nodeptr root = NULL, curptr = NULL, temp = NULL, temp1 = NULL, temp2 = NULL;

void push(nodeptr *nodeadds, struct stack **head) //pushes the given element into the stack.
{
    struct stack *ptr;
    ptr = (struct stack *)(malloc(sizeof(struct stack)));
    if (ptr != NULL)
    {
        ptr->adds = *nodeadds;
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

nodeptr pop(struct stack **head) //pops out the element from the stack.
{
    if (*head != NULL)
    {
        struct stack *temp;
        nodeptr temp1;
        temp = *head;
        *head = (*head)->next;
        temp1 = temp->adds;
        //printf("%d\n", temp->adds);
        free(temp);
        return temp1;
    }
    else
    {
        printf("Pop Failure\n");
    }
}

nodeptr create(char m) //creeates a node for bst.
{
    nodeptr temp;
    temp = (struct node *)(malloc(sizeof(struct node)));
    if (temp == NULL)
    {
        printf("Error\n");
        return NULL;
    }
    else
    {
        temp->key = m;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = NULL;
        return temp;
    }
}

nodeptr merge(nodeptr *ptr1, nodeptr *ptr2, nodeptr *ptr3, nodeptr *root) //merges three nodes and makes the 2nd input as root.
{
    (*ptr2)->left = *ptr1;
    (*ptr1)->parent = *ptr2;
    (*ptr2)->right = *ptr3;
    (*ptr3)->parent = *ptr2;
    *root = *ptr2;
    return *ptr2;
}

void inorder(nodeptr root) //InOrder traversal of the tree
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
        printf("(");
    inorder(root->left);
    printf("%c", root->key);
    inorder(root->right);
    if (root->right != NULL)
        printf(")");
}
void preorder(nodeptr root) //PreOrder traversal of the tree.
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->key);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    char string[100];
    scanf("%s", string);
    int i = 0;
    while (string[i] != '\0')
    {
        char ch = string[i];
        if (ch >= 'a' && ch <= 'z')
        {
            nodeptr temp;
            temp = create(ch);
            push(&temp, &head); //pushing into the stack.
        }
        else
        {
            nodeptr temp1, temp2, new, mer;
            temp1 = pop(&head);
            temp2 = pop(&head);
            new = create(ch);
            mer = merge(&temp2, &new, &temp1, &root);
            push(&mer, &head);
        }
        i++;
    } //finally the expression tree is crated.
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
}