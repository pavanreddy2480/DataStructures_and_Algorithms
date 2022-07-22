#include <stdio.h>
#include <stdlib.h>

int n;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection(int *ptr){
	int i, j, max_index;
 
    for (i = n-1; i > -1; i--)
    {
        max_index = i;
        for (j = i; j > -1; j--)
          if (ptr[j] > ptr[max_index])
            max_index = j;
 
        swap(&ptr[max_index], &ptr[i]);

    }
}
int main()
{
	int *arr;

	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for (int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
    selection(arr);
    for (int i = 0; i < n; i++) {
        printf("%d\n",arr[i]);
    }
	return 0;
}
