#include <stdio.h>

int f4(int n) {
	if (n>1) 
		return 1+2*f4(n-1);
	return 0;
}

main() {
	int n;
	while(1) {
		printf("\nNhap n= "); scanf("%d",&n);
		f4(n);
		printf("\nGia tri cua ham de quy la: %d",f4(n));
	}
}
