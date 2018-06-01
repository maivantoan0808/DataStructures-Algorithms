#include<stdio.h>
#include<conio.h>
#include<math.h>
int UCLN(int a,int b);
main() {
    int a,b;
    printf("nhap vao 2 so a va b:\n");
    scanf("%d%d",&a,&b);
    printf("BCNN cua %d va %d la:%d",a,b,(a*b)/UCLN(a,b));
    getch();
 
}

int UCLN(int a,int b) {
    a=abs(a);b=abs(b);
    if(b==0)
        return a;
    else
        return UCLN(b,a%b);
}
