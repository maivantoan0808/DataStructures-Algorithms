#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
//Khai báo
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

//Khoi tao
void Init(LIST &l) {
	l.pHead=l.pTail=NULL;
}

NODE* TaoNode (int x) {
	NODE *p = new NODE;
	
	if (p == NULL) return NULL;
	p -> data = x;
	p -> pNext = NULL;
}
//Them Node
void addHead (LIST &l, NODE *p) { 
	if (l.pHead == NULL) 
		l.pHead = l.pTail = p;
	else {
		p ->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTail (LIST &l, NODE *p) {
	if (l.pHead == NULL) 
		l.pHead = l.pTail = p;
	else { 
		l.pTail -> pNext = p;
		l.pTail = p; 
	}
}

//them 1 Node p vao sau Node q
void addNode(LIST &l, NODE *p, NODE *q) {
	for (NODE *k = l.pHead; k != NULL; k = k-> pNext ) {
		if (k-> data == q->data) {
			NODE *g = k-> pNext;
			k-> pNext = p;
			p->pNext = g;
			return;
		}
	}
}

//Nhap DL vào danh sách
void Input(LIST &l) {
	int n;
	printf("\nBan muon nhap bao nhieu Node: "); scanf("%d",&n);
	Init(l);
	for( int i=0 ; i<n; i++) {
		int x;
		printf("\nNhap vao du lieu: "); scanf("%d",&x);
		
		NODE *p=TaoNode(x);
		addTail(l,p);
		//addHead(l,p);
	}
}

//Xoa 1 Node
void DeleteHead(LIST &l) {
	NODE *p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;	
}

void DeleteTail(LIST &l) {
	NODE *p;
	for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
		if (k == l.pTail) {
			l.pTail = p;
			l.pTail->pNext = NULL;
			delete k;
			return;
		}
		p=k;
	}
}
//xoa Node g sau Node q
void DeleteNode(LIST &l, NODE *q) {
	NODE *g;
	for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data == q->data) {
			g = k->pNext;
			k->pNext = g->pNext;
			delete g;
			return;
		}
	}
}

void deleteRandomNode(LIST &l, int random) {
	if (l.pHead->data == random) {
		DeleteHead(l);
		return;
	}
	if (l.pTail->data == random) {
		DeleteTail(l);
		return;
	}
	NODE *q;
	for (NODE *g=l.pHead; g != NULL; g=g->pNext) {
		if (g->data == random) {
			DeleteNode(l,q);
			return;
		}
		q = g;
	}
}

int Search(LIST &l, int data) {
	for (NODE *k=l.pHead; k != NULL; k=k->pNext) {
		if (k->data == data) 
			return 1;
	}
	return 0;
}
/* Dem so chan, so le
void Kiemtra(LIST &l) {
	int count1=0; int count2=0;
	for (NODE *p = l.pHead; p!= NULL; p = p->pNext) {
		if (p->data %2 ==0 ) count1++;
		else count2++;
	}
	printf("\nSo so chan la: %d",count1);
	printf("\nSo so le la: %d\n",count2);
}*/

void GiaiPhong(LIST &l) {
	NODE *p;
	while (l.pHead != NULL) {
		p = l.pHead;
		l.pHead = l.pHead -> pNext;
		delete p;
	}
}

void Output(LIST l) {
	for (NODE *p = l.pHead; p!= NULL; p = p->pNext) {
		printf("%4d", p->data);
	}
}
/* Ham tra lai dau ra la so chan
void Output(LIST l) {
	for (NODE *p = l.pHead; p!= NULL; p = p->pNext) {
		if(p->data % 2 == 0)
		printf("%4d", p->data);
	}
}
*/
int main() {
	LIST l;
	Input(l);
//	Kiemtra(l);
	Output(l);
//	int p,q;
//	printf("\n Nhap Node q: "); scanf("%d",&q);
//	NODE *Q = TaoNode(q);
//	printf("\n Nhap Node p can them: "); scanf("%d",&p);
//	NODE *P = TaoNode(p);
//	addNode(l,P,Q);
//	Output(l);
//	int q;
//	printf("\n Nhap Node q: "); scanf("%d",&q);
//	NODE *Q = TaoNode(q);
//	deleteRandomNode(l,q);
//	int data;
//	printf("\n Nhap data can tim: "); scanf("%d",&data);
//	int check = Search(l,data);
//	if (check == 1) printf("\nTim thay!");
//	if (check == 0) printf("\nKhong tim thay!");
//	Output(l);
	GiaiPhong(l);
	return 0;
}
