//#include <stdio.h>
//#include <string.h>
//
//int i=0;
//char s[500],s1[50][50],*p;
//void Xau() {
//	p=strtok(s," ");
//	while(p!='\0') {
//		strcpy(s1[i],p);
//		p=strtok(NULL," ");
//		i++;
//	}
//	printf("\nXau dao: ");
//	while (i>=0) {
//		printf(" %s",s1[i]);
//		i--;
//	}
//}
//int main() {
//	printf("\nNhap xau: ");
//	gets(s);
//	Xau(); 
//	return 0;
//}

#include <stdio.h>
#include <string.h>
#include <conio.h>
void daonguoc(char x[]) {	
	int k=strlen(x);
	for(int i=k;i>=0;i--)
		printf("%c",x[i]);
}

int main () {	
	char x[20];
	printf("nhap vao chuoi ky tu  ");
	gets(x);
	daonguoc(x);
	return 0;
}
