#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
//Khai báo
struct Node{
	int heso;
	int somu;
	struct Node *pNext;
};
typedef struct Node NODE;

struct List{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

//Khoi tao
void Init(LIST &l) {
	l.pHead=l.pTail=NULL;
}

NODE* TaoNode (int x, int y) {
	NODE *p = new NODE;
	
	if (p == NULL) return NULL;
	p -> heso = x;
	p -> somu = y;
	p -> pNext = NULL;
}

void addTail (LIST &l, NODE *p) {
	if (l.pHead == NULL) 
		l.pHead = l.pTail = p;
	else { 
		l.pTail -> pNext = p;
		l.pTail = p; 
	}
}

void Input(LIST &l) {
	int n;
	printf("\nNhap vao bac cua da thuc: "); scanf("%d",&n);
	Init(l);
	for( int i=n ; i>=0; i--) {
		int k;
		printf("\nNhap vao he so cua x^ %d: ",i); scanf("%d",&k);
		
		NODE *p=TaoNode(k,i);
		addTail(l,p);
		//addHead(l,p);
	}
}

void GiaiPhong(LIST &l) {
	NODE *p;
	while (l.pHead != NULL) {
		p = l.pHead;
		l.pHead = l.pHead -> pNext;
		delete p;
	}
}

void Sum(LIST &l, LIST l1, LIST l2) {
	Node *p = new Node, *q = new Node;
	if(l1.pHead -> somu > l2.pHead -> somu ) {
		l = l1;
		p = l2.pHead;
	}
	else {
		l = l2;
		p = l.pHead;
	}
	
	q= l.pHead;
	while( q->somu > p->somu ) 
		q = q->pNext; // tim dc q sao cho q->sm == p->sm
	while( q != NULL ) {
		q->heso += p->heso;
		p = p->pNext; 
		q = q->pNext;
	}
}

void Mult(LIST &l, LIST l1, LIST l2) {
	
}

void Output(LIST l) {
	for (NODE *p = l.pHead; p!= NULL; p = p->pNext){
		if( p!= l.pTail ) {
			if( p -> heso ) cout<< p->heso <<"x^"<< p->somu;
			if( p -> heso){
				if(p -> heso > 0 ) cout<<" + ";
				else cout<<" ";
			}
		}
		if( p->somu==0 ) cout<< p->heso;
	}
}

int main() {
	LIST l,l1,l2;
	Init(l); Init(l1); Init(l2);
	printf("\nNhap da thuc P(x) "); Input(l1);
	printf("\nNhap da thuc Q(x) "); Input(l2);
	printf("\nDa thuc P(x)= "); Output(l1);
	printf("\nDa thuc Q(x)= "); Output(l2);
	Sum(l,l1,l2);
	printf("\nDa thuc R(x)= P(x) + Q(x) = "); Output(l);
	GiaiPhong(l);
	return 0;
}
