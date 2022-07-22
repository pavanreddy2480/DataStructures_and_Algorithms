//program to read a sorted array of n integers and implement binary search algorithm recursively.
#include <stdio.h>
#include <stdlib.h>


int depth=0;

//declaring the recrussive func.
int binary_search(int *ptr,int left,int right,int num){
	
	depth=depth+1;
	
	int mid;
	if (left==right) {
		if (ptr[left]==num) {
			return left;
		}
		else 
			return -1;
	}
	else {
		mid=(left+right)/2;

		if (num==ptr[mid]) {
			return mid;
		}
		
		else if((num<ptr[mid])&&(left<mid))
			return (binary_search(ptr,left,mid-1,num));
		
		else if((num>ptr[mid])&&(mid<right))
			return (binary_search(ptr,mid+1,right,num));
		
		else 
			return -1;
		}
	}


int main()
{
	int n,i,index,num;
	int *arr;
	
	scanf("%d",&n);
	
	arr=(int*)(malloc(n*sizeof(int)));//creating arr using malloc func.
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	scanf("%d",&num);
	
	index=binary_search(arr,0,n-1,num);
	
	printf("%d\n",depth);
	printf("%d\n",index);
	return 0;
}

