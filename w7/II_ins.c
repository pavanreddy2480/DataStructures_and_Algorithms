#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* next;
};
typedef struct node* nodeptr;

void insertion_sort(nodeptr* curptr,nodeptr* head,int* n){
    nodeptr x,y,z;
    
    
    *curptr=*head;
    y=(*curptr)->next;

    int j=1,i=0;

    int b=0;
    z=*head;
    for (int j=1;j<*n;j++){
        b=0;
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
    }
}

int main(){
    int n;
    scanf("%d",&n);
    nodeptr head,curptr,lptr;
    lptr=(nodeptr)  (malloc(n*sizeof(struct node)));
    
    head=lptr;
    curptr=head;
    
    for (int i=0;i<n;i++){
        scanf("%d",&(curptr->num));
        if(i<n-1){
            curptr->next=curptr+1;
            curptr++;
        }
        else{
            curptr->next=NULL;
        }
    }

    insertion_sort(&curptr,&head,&n);

    for (int i=0;i<n;i++){
        printf("%d\n",curptr->num);
        curptr=curptr->next;
    }
}
