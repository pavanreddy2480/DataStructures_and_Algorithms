//program to read an array A of n integers and partition the array with respect to a pivot at index k.
#include <stdio.h>
#include <stdlib.h>

int i=0,j=0;
int n;

void swap(int *a, int *b)
{
   int temp;

   temp = *b;
   *b = *a;
   *a = temp;
}

void pivot_partitioning(int *ptr,int index){
	
	
    int rank=0;
	
	for(i=0;i<n;i++){
		if (ptr[i]<ptr[index]) {
			rank=rank+1;
		}
	}
	
	swap(&ptr[rank],&ptr[index]);
	
	i=0;
	j=rank+1;
	
	while(i<rank){
	    
	    //elements with value less than A[k] appear only before all occurrences of A[k].
		while(i<rank && ptr[i]<ptr[rank]){
			i=i+1;
			
		}
		//elements with value greater than A[k] appear only after the first occurrence of A[k].
		while(j<n && ptr[j]>=ptr[rank]){
			j=j+1;
			
		}
		if(i<rank){
		    swap(&ptr[i], &ptr[j]);
		}
	}	
}



int main(int argc, char *argv[])
{
		
	int *arr,index;
	
	scanf("%d",&n);
	
	arr=(int*)malloc(n*sizeof(int));//creating arr using malloc func.
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	scanf("%d",&index);
	
	pivot_partitioning(arr, index);
	
	for (i = 0; i < n; ++i) {
		printf("%d\n",arr[i]);
	}
	return 0;
}

