#include <stdio.h>

void towerOH(int n,int initial,int final,int middle){
	if(n<1)
		return;
	if (n==1) {
		printf("Move Disk 1 from Pole %d to Pole %d\n",initial,final);
	}
	else{
		towerOH(n-1,initial,middle,final);
		printf("Move Disk %d from Pole %d to Pole %d\n",n,initial,final);
		towerOH(n-1, middle, final, initial);
	}
}

int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	towerOH(n,0,2,1);
	return 0;
}
