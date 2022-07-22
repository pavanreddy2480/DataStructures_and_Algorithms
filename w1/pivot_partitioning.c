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

void pivot_partitioning(int *ptr,int index){
	for(i=0;i<n;i++){
		if (ptr[i]<ptr[index]) {
			rank=rank+1;
		}
	}
	
	swap(&ptr[rank],&ptr[index]);
	i=0;
	j=rank+1;
	while(1){
		while(i<rank && ptr[i]<ptr[rank]){
			i=i+1;
			break;
		}
		while(j<n && ptr[j]>=ptr[rank]){
			j=j+1;
			break;
		}
		swap(&ptr[i], &ptr[j]);
		if (i==rank-1) {
			break;
		}
	}	
}



int main(int argc, char *argv[])
{
	int a,b;	
	int *arr,index;
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&index);
	pivot_partitioning(arr, index);
	for (i = 0; i < n; ++i) {
		printf("%d\n",arr[i]);
	}
	return 0;
}
