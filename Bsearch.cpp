#include<stdio.h>


int search(int value, int values[], int start, int end)
{
	int mid = (start + end)/2;
	if (start = end) {
		if(values[mid] =value) {
			printf("\n search(%d,%d)",&start,&end);
			printf("%d",values[mid]);
			return mid;
		}
		else return -1;
	}
	 
	if(value=values[mid]) {
		printf("\n search(%d,%d)",&start,&end);
		printf("%d",values[mid]);
		return mid;
	}
	else
	{ 
		if(value < values[mid]) {
		printf("\n search(%d,%d)",&start,&end);
		printf("%d",values[mid]);
		return search(value, values, mid-1, end);
		}
		else {
			printf("\n search(%d,%d)",&start,&end);
			printf("%d",values[mid]);
			return search(value, values, mid+1, end);
		}
	}
}
main() 
{
	int values[] = {1,2,4,6,8};
	int n;
	printf("Nhap so can tim="); scanf("%d",&n);
	search(n,values,1,5);
}

