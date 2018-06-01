#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
void Swap(int &a, int &b) {
	int tmp=a;
	a=b;
	b=tmp;
}

//tang dan
void Selection_Sort(int A[], int n) {
	int i,j,min,temp;
	for (i=0; i<n-1; i++) {
		min=i;
		for (j=i+1; j<n; j++) {
			if (A[j] < A[min])
				min=j;
		}
		Swap(A[i],A[min]);
	}
}

//giam dan
//void Selection_Sort(int A[], int n) {
//	int i,j,min,temp;
//	for (i=0; i<n-1; i++) {
//		min=i;
//		for (j=i+1; j<n; j++) {
//			if (A[j] > A[min])
//				min=j;
//		}
//		Swap(A[i],A[min]);
//	}
//}

int main() {    
	int A[100000];
    int i,n;  
	printf("---------INSERTION SORT VERSION-------");
	while(1) {     
    	printf("\n Nhap n:");
    	scanf("%d",&n);
    	for(int i=0;i<n;i++)
			A[i]=rand()&999; 	
		printf("\n Day so ban dau la:\n");
		for(int i=0;i<n;i++)
		printf("%5d",A[i]);	       
		printf("\n\n Ket qua sau khi sap xep la:\n");
		clock_t start=clock();
		Selection_Sort(A,n);
		clock_t finish=clock();
		double d= (double)(finish-start)/ CLOCKS_PER_SEC;
		for(int i=0;i<n;i++)
		printf("%5d",A[i]);
		printf("\n\n Thoi gian thuc hien thuat toan sap xep chen la:%.5f ", d);
	}
}	

