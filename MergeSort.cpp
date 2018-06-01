#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>

/*void docfile(int A[], int &n)
{
	FILE *f;
	f=fopen("Mangtest.txt","r");
	fscanf(f,"%d",&n);    
	for(int i=0;i<n;i++)
	fscanf(f,"%d",&A[i]);
	fclose(f);   
}*/

//Tang dan
void Merge(int A[],int first, int mid, int last) {
	int i1=first, i2=mid;
	int j1=mid+1, j2=last;
	int k=i1, tA[100000];
	for(;(i1<=i2) && (j1<=j2);) {
		if(A[i1] < A[j1]) {
			tA[k]=A[i1];
			i1++;
		}
		else {
			tA[k]=A[j1];
			j1++;
		}
		k++;
	}
	
	for(;i1 <= i2;) {
		tA[k]=A[i1];
		i1++;
		k++;
	}
	
	for(;j1 <= j2;) {
		tA[k]=A[j1];
		j1++;
		k++;
	}
	
	for(int i=first;i<=last;i++) {
		A[i]=tA[i];
	}
	return;
}

/* Giam dan
void Merge(int A[],int first, int mid, int last) {
	int i1=first, i2=mid;
	int j1=mid+1, j2=last;
	int k=i1, tA[100000];
	for(;(i1<=i2) && (j1<=j2);) {
		if(A[i1] > A[j1]) {
			tA[k]=A[i1];
			i1++;
		}
		else {
			tA[k]=A[j1];
			j1++;
		}
		k++;
	}
	
	for(;i1 <= i2;) {
		tA[k]=A[i1];
		i1++;
		k++;
	}
	
	for(;j1 <= j2;) {
		tA[k]=A[j1];
		j1++;
		k++;
	}
	
	for(int i=first;i<=last;i++) {
		A[i]=tA[i];
	}
	return;
}
*/

void Merge_Sort(int A[],int first, int last) {
	int mid;
	if(first < last) {
		mid=(first+last)/2;
		Merge_Sort(A, first, mid);
		Merge_Sort(A, mid+1, last);
		Merge(A, first, mid, last);
	}
	return;
}
int main() {    
	int A[300000];
    int i,n;  
	printf("---------MERGE SORT VERSION-------"); 
	while(1) {
		printf("\n Nhap n:");
		scanf("%d",&n);
		for (i=0;i<n;i++)
			A[i]=rand()%999;   
		printf("\n Day so ban dau la:\n");
		for(i=0;i<n;i++)
		printf("%5d",A[i]);	       
		printf("\n\n Ket qua sau khi sap xep tang dan la:\n");
		clock_t start=clock();
		Merge_Sort(A,0,n-1);
		clock_t finish=clock();
		double d= (double)(finish-start)/ CLOCKS_PER_SEC;
		for(i=0;i<n;i++)
		printf("%5d",A[i]);
		printf("\n\n Thoi gian thuc hien thuat toan sap xep tron la:%.5f ", d);
	}
}	

