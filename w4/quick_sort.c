#include <stdio.h>
#include <stdlib.h>


int i=0,j=0;
int rank=0;
int n;

void swap(int *a, int *b)
{
   int t;

   t  = *b;
   *b = *a;
   *a = t;
}

void partition(int *ptr,int first, int last, int index){
	rank=0;
	for(i=first;i<last+1;i++){
		if (ptr[i]<ptr[index]) {
			rank=rank+1;
		}
	}
	rank = rank+first;
	
	swap(&ptr[rank],&ptr[index]);
	i=first;
	j=rank+1;
	while(i<rank){
	    
	    //elements with value less than A[k] appear only before all occurrences of A[k].
		while(i<rank && ptr[i]<ptr[rank]){
			i=i+1;
			
		}
		//elements with value greater than A[k] appear only after the first occurrence of A[k].
		while(j<last+1 && ptr[j]>=ptr[rank]){
			j=j+1;
			
		}
		if(i<rank){
		    swap(&ptr[i], &ptr[j]);
		}
	}	
}


void quick_sort(int *ptr,int first,int last){
	if (first==last) {
		return;
	}
	partition(ptr,first,last,first);
	if (rank>first) {
		quick_sort(ptr,first,rank-1);
	}
	if(rank<last) {
		quick_sort(ptr,rank+1,last);
	}
}
int main(int argc, char *argv[])
{
	int *arr;
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}
