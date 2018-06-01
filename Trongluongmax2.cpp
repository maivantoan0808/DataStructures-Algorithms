#include <stdio.h>
#include <conio.h>

int main() {
	int a[]={-2,11,-4,13,-5,2};
	int maxSum=a[0];
	for (int i=0; i<6; i++) {
		int sum = 0;
		for (int j=i; j<6; j++) {
			sum += a[j];
			if (sum > maxSum) 
				maxSum = sum;
		}
	}
	printf("Day so ban dau: ");
	for (int i=0;i<6;i++) printf("%3d",a[i]);
	printf("\nTrong luong lon nhat cua day= %d",maxSum);
	return 1;
}
