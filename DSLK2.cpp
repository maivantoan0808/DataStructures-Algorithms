#include <stdio.h>
#include <iostream>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *pNext; 
};
typedef struct Node NODE;

struct List{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

void Init(LIST &l) {
	l.pHead= l.pTail = NULL;
}

NODE* TaoNode(int x) {
	NODE *p= new NODE;
	
	if (p == NULL) return NULL;
	p->data= x;
	p->pNext= NULL;
}

void addHead(LIST &l, NODE *p) {
	if (l.pHead== NULL) {
		l.pHead= l.pTail = p;
	}
	else {
		p-> pNext= l.pHead;
		l.pHead= p;
	}
}

void addTail(LIST &l, NODE *p) {
	if (l.pHead== NULL) {
		l.pHead= l.pTail = p;
	}
	else {
		l.pTail-> pNext= p;
		l.pTail= p;
	}
}

void Input(LIST &l) {
	int n;
	printf("Ban muon bao nhieu Node: "); scanf("%d",&n);
	Init(l);
	for(int i=1; i<=n; i++) {
		int x;
		printf("Nhap vao Node thu %d: ",i); scanf("%d",&x);
		
		NODE *p=TaoNode(x);
		addTail(l,p);
		//addHead(l,p);
	}
}

void Output(LIST l) {
	for(NODE *p= l.pHead; p!=NULL; p= p->pNext) {
		printf("%4d", p->data);
	}
}

int main() {
	LIST l;
	Input(l);
	Output(l);
	return 0;
}
