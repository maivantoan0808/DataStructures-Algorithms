#include <stdio.h>

struct  Node {
	int data;
	struct Node* pLeft;
	struct Node* pRight;	
};
typedef struct Node Tree;

Tree* MakeTree(int value);
Tree* DeleteNode(Tree* T, float x);
Tree* FindMin(Tree* T);
Tree* FindMax(Tree* T);
Tree* Insert(Tree* p, int item);
Tree* Search(Tree* p, int item);
void PrintInorder(const Tree* p);

Tree *insert(Tree* p, int item) {
	if (p == NULL) p = MakeTree(item);
	else if (item < p->data)
		p->pLeft = Insert(p->pLeft, item);
	else if(item > p->data)
		p->pRight = Insert(p->pRight, item);
	return p;
}

Tree *Search(Tree *p, int item){
	if(p!=NULL) {
		if(item < p->data) {
			p = Search(p->pLeft, item);
		}
		else {
			if(item > p->data)
			p = Search(p->pRight, item);
		}
		return p;
	}
}

Tree *DeleteNode(Tree *T, int x){
	Tree tmp;
	if(T==NULL) printf("not found");
	else if(x< T->data) T->pLeft = DeleteNode(T->pLeft,x);
	else if(x> T->data) T->pRight = DeleteNode(T->pRight,x);
	else if(T->pLeft && T->pRight){
		tmp = FindMin(T->pRight);
		T->data = tmp->data;
		T->pRight = DeleteNode(T->data,T->pRight);
	}
	else {
		tmp = T;
		if(T->pLeft==NULL)
			T = T->pRight;
		else 
			T = T->pLeft;
		free(tmp);
	}
	return(T);
}

main() {
	
}
