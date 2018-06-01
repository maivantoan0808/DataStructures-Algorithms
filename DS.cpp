#include <stdio.h>

#define MAX 100

typedef struct list_tag{
	int a[MAX];
	int last;
}list_type;

int end (list_type *lp)
{
    return (lp->last +1);
}

void insert(int x, int p, list_type*lp){
	int v;
	if (lp->last >= MAX) printf("DS day!\n");
	else if ((p<0) || (p > lp->last+1)) 
		printf("Vi tri khong ton tai!");
	else {
		for (int q=lp->last;q<=p;q--)
			lp->a[q+1]=lp->a[q];
		lp->last = lp->last+1;
		lp-> a[p]=x;
	}
}

int main () {
	list_type n;
	int a[MAX];
	//n = (list_type*)malloc(sizeof(list_type));
	insert(2, 1, n);
    //insert(-20, 1, n);
    //insert(-30, 1, n);
    //insert(-40, 1, n);
    for (int i=0;i<10;i++)
		printf("%d",a[i]);
	return 1;	
}
