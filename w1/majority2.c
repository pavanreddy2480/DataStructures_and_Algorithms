//No.Of comparisons of this program is linear w.r.t  'n' .
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int freq=0,curr_candidate=0;
	int i,n,*ptr;
	scanf("%d",&n);
	
	ptr=(int*)malloc(n*sizeof(int));
	
	//this will assign majority num to curr_candidate.		
	for (i=0;i<n;i++)
		scanf("%d",&ptr[i]);
		printf("\n");
		i=i+1;
	
	for (i=0;i<n;i++)
		if (freq==0){
			curr_candidate=ptr[i];
			freq=1;
		}
		else if (curr_candidate==ptr[i]){
			freq=freq+1;
		}
		else
			freq=freq-1;
	
	freq=0;
	
	//checking weather there is a majority number or not.	
	for (i=0;i<n;i++)
		if (curr_candidate==ptr[i]){
			freq=freq+1;
		}
	if(freq>(n/2)){
		printf("%d",curr_candidate);
	}
	else
		printf("No Majority");
	
	return 0;
}
