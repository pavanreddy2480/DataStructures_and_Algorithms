//No.Of comparisons of this program is quadratic w.r.t  'n' .
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int freq=0,curr_num=0;
	int MAX_FREQ=0,MAX_NUM=0;
	int i,j,n;
	int *arr_num,*arr_freq;
	
	scanf("%d",&n);
	
	arr_num=(int*)malloc(n*sizeof(int));
	arr_freq=(int*)malloc(n*sizeof(int));
	
	//figuring out freequeues of numbers.
	for (i=0;i<n;i++)
		scanf("%d",&arr_num[i]);
		printf("\n");
	
	for (i=0;i<n;i++){
		curr_num=arr_num[i];
		freq=0;
		for (j = 0; j < n; j++){ 
			if (curr_num==arr_num[j]) {
				freq=freq+1;	
			}
		}
		arr_freq[i]=freq;
	}
	
	//Number with max frequency.
	for (i = 0; i < n; i++) 
		if (arr_freq[i]>MAX_FREQ){
			MAX_FREQ=arr_freq[i];
			MAX_NUM=arr_num[i];
		}	
	if (MAX_FREQ>n/2){
		printf("%d",MAX_NUM);
	}	
	else 
		printf("No Majority");

	return 0;
}
