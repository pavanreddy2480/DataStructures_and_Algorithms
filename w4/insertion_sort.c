#include <stdio.h>
#include <stdlib.h>



int n;
void insertion(int *ptr,int i){
	int temp;
	temp=ptr[i];
	i--;
	while(i>-1 && ptr[i]>temp){
		ptr[i+1]=ptr[i];
		i--;
	}
	ptr[i+1]=temp;
}
void insertion_sort(int *ptr,int n){
	if (n==1) {
		return;
	}
	else{
		insertion_sort(ptr,n-1);
		insertion(ptr,n-1);
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
	insertion_sort(arr,n);
	for(int i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}
