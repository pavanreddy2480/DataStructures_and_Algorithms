#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *ptr;
	ptr=fopen("a1.txt", "w");

	for (int a=0;a<5000;a++){
		fprintf(ptr, "%d ",rand()%1000);
	}
	fclose(ptr);
	return 0;
}
