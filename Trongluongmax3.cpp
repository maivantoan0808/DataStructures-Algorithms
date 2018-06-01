#include <stdio.h>
#include <conio.h>



int main() {
	int MaxLeft(int *a, int i, int j) {
		int maxSum = -9999; 
		int sum = 0;
		for (int k=j; k>=i; k--) {
			sum = sum+a[k];
			if (sum > maxSum) 
				maxSum = sum;
		}	
		return maxSum;
	}

	int MaxRight(int *a, int i, int j) {
		int maxSum = -9999; 
		int sum = 0;
		for (int k=i; k<=j; k++){
			sum = sum+a[k];
			if (sum > maxSum) 
				maxSum = sum;
		}
		return maxSum;
	}
		
	int MaxSub(int *a, int i, int j) {
		if (i = j) return a[i];
		else { 
			int m = (i+j)/2;
			int wL = MaxSub(a, i, m);
			int wR = MaxSub(a, m+1, j);
			int wM = MaxLeft(a, i, m)+ MaxRight(a, m+1, j);
			return max(wL, wR, wM);
		}
	}
	
	int a[]={-2,11,-4,13,-5,2};
	printf("Day so ban dau: ");
	for (int i=0;i<6;i++) printf("%3d",a[i]);
	printf("\nTrong luong lon nhat cua day= %d",maxSum);
	return 1;
}		
