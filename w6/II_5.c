#include <stdio.h>

struct node {
    int num;
    struct node* next;
};
typedef struct node* nodeptr;

int main(){
    nodeptr head,curptr;
    struct node n0,n1,n2,n3,n4,n5;
    head=&n0;
    curptr=&n0;
    
    (*curptr).next=&n1;
    curptr=(*curptr).next;
    
    (*curptr).next=&n2;
    curptr=(*curptr).next;
    
    (*curptr).next=&n3;
    curptr=(*curptr).next;
    
    (*curptr).next=&n4;
    n4.next=NULL;

    curptr=head;
    
    for (int i=0;i<5;i++){
        scanf("%d",&(*curptr).num);
        curptr=(*curptr).next;
    }
    
    curptr=head;
    for(int i=0;i<5;i++){
        printf("%d\n",(*curptr).num);
        curptr=(*curptr).next;
    }
    nodeptr x;
    int y=0;
    
    scanf("%d",&n5.num);
    curptr=head;
    
    for (int i=0;i<5;i++){
        if((*curptr).num>n5.num){
            if(curptr==head){
                head=&n5;
                n5.next=curptr;
                y=1;
                break;
            }
            else{
                n5.next=curptr;
                (*x).next=&n5;
                y=1;
            break;
            }
        }
        x=curptr;
        curptr=(*curptr).next;
    }
    if(y==0){
        n4.next=&n5;
        n5.next=NULL;
    }

    curptr=head;
    for(int i=0;i<6;i++){
        printf("%d\n",(*curptr).num);
        curptr=(*curptr).next;
    }
    return 0;
}

