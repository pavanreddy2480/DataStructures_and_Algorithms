#include <stdio.h>

struct node {
    int num;
    struct node* next;
};
typedef struct node* nodeptr;

void link(nodeptr* x,struct node* y){
        
    (*x)->next=&(*y);
    *x=(*x)->next;
    
}

void insertion_sort(nodeptr* curptr,nodeptr* head,int* n){
    nodeptr x,y,z;
    
    
    *curptr=*head;
    y=(*curptr)->next;

    int j=1,i=0;

    z=*head;
        for (int j=1;j<*n;j++){
        int b=0;
        for(int i=0;i<j;i++){
            if((*curptr)->num>(*y).num){
                if(*curptr==*head){
                    z->next=y->next;
                    *head=y;
                    y->next=*curptr;
                    y=z->next;
                    b=1;
                    break;
                }
                else {
                    z->next=y->next;
                    y->next=*curptr;
                    x->next=y;
                    y=z->next;
                    b=1;
                break;
                }
            }
            x=*curptr;
            *curptr=(*curptr)->next;
        }
    if(b==0){

        z=y;
        y=y->next;
        }
    *curptr=*head;
    for(int k=0;k<j+1;k++){
        printf("%d\n",(*curptr)->num);
        *curptr=(*curptr)->next;
    }
    *curptr=*head;

    }
}

int main(){
    nodeptr head,curptr;
    struct node n0,n1,n2,n3,n4;
    head=&n0;
    curptr=&n0;
    link(&curptr,&n1);
    link(&curptr,&n2);
    link(&curptr,&n3);
    link(&curptr,&n4);
    curptr->next=NULL;

    curptr=head;
    
    for (int i=0;i<5;i++){
        scanf("%d",&(*curptr).num);
        curptr=(*curptr).next;
    }
    
    curptr=head;
    int n=5;
    printf("%d\n",curptr->num);

    insertion_sort(&curptr,&head,&n);

    
    curptr=head;
    for(int i=0;i<5;i++){
        printf("%d\n",(*curptr).num);
        curptr=(*curptr).next;
    }
    return 0;
}
