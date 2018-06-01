#include <stdio.h>
#include <conio.h>

int main() {
	int maxSum=0;
	int a[]={-2,11,-4,13,-5,2};
	for (int i=0;i<6;i++) {
		for (int j=0;j<6;j++) {
			int sum=0;
			for (int k=i;k<j;k++) 
				sum += a[k];
			if (sum > maxSum)
				maxSum=sum;
		}
	}
	printf("Day so ban dau: ");
	for (int i=0;i<6;i++) printf("%3d",a[i]);
	printf("\nTrong luong lon nhat cua day= %d",maxSum);
	return 1;
}
