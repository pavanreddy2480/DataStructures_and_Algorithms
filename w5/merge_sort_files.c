#include <stdio.h>
#include <stdlib.h>

int n=2;
int p=0,q=0,i,j;
FILE *ptr1,*ptr2;

void merge(FILE *a, int beg, int mid, int end)  
{  
    int i=beg,j=mid+1,k,index = beg;  
	ptr2=fopen("input2.txt","r+");
    while(i<=mid && j<=end)  
    {  
        if(a[i]<a[j])  
        {  
            ptr2[index] = a[i];  
            i = i+1;  
        }  
        else   
        {  
            ptr2[index] = a[j];  
            j = j+1;   
        }  
        index++;  
    }  
    if(i>mid)  
    {  
        while(j<=end)  
        {  
            ptr2[index] = a[j]; 
            index++;  
            j++;  
        }  
    }  
    else   
    {  
        while(i<=mid)  
        {  
            ptr2[index] = a[i];  
            index++;  
            i++;  
        }  
    }  
    k = beg;  
    while(k<index)  
    {  
        a[k]=ptr2[k];  
        k++;  
    }  
}  

void merge_sort(FILE *ptr,int p1,int p2){
    while((p=getc(ptr)) != EOF){
        getw(ptr);				
        q++;
	}

    i=fseek(ptr, p/2, SEEK_SET);
    merge_sort(ptr,0,i);
    merge_sort(ptr,i,q);
    merge(ptr,0,i,q);

}
int main(int argc, char *argv[])
{
	ptr1=fopen("input1.txt","r+");
   fseek(ptr1, 0, SEEK_END);
   j=ftell(ptr1);
   fseek(ptr1, 0, SEEK_SET);
    merge_sort(ptr1, 0, j);
	return 0;
    fclose(ptr1);
    fclose(ptr2);
}
