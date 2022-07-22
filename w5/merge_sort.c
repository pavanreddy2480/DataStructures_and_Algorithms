#include <stdio.h>
#include <stdlib.h>

int n=0;

void merge(int *a, int beg, int mid, int end)  
{  
    int i=beg,j=mid+1,k,idx = beg;  

    int *temp=(int*)(malloc(n * sizeof(int)));  
    
    while(i<mid+1 && j<end+1)  
    {  
        if(a[i]<a[j])  
        {  
            temp[idx] = a[i];  
            i = i+1;  
        }  
        else   
        {  
            temp[idx] = a[j];  
            j = j+1;   
        }  
        idx++;  
    }  
    if(i>mid)  
    {  
        while(j<end+1)  
        {  
            temp[idx] = a[j];  
            idx++;  
            j++;  
        }  
    }  
    else   
    {  
        while(i<mid+1)  
        {  
            temp[idx] = a[i];  
            idx++;  
            i++;  
        }  
    }  
    for (i = beg; i < end+1; ++i) {
      
        a[i]=temp[i];  
      
    }
    free(temp);
}  

void merge_sort(int *ptr,int first,int last){
	
	if (first == last) {
		return;
	}
	else{
		int mid=(first+last)/2;
		merge_sort(ptr,first,mid);
		merge_sort(ptr,mid+1,last);
		merge(ptr,first,mid,last);

	}
}
int main(int argc, char *argv[])
{
	scanf("%d",&n);
	
	int *arr1=(int*)(malloc(n * sizeof(int)));
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr1[i]);
	}

	merge_sort(arr1 ,0, n-1);
	for (int i = 0; i < n; i++) {
		printf("%d\n",arr1[i]);
	}
	return 0;
}
