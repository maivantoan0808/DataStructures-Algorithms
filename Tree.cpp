#include <stdio.h>
#include <stdlib.h>

struct node {
   int data; 
	
   struct node *leftChild;
   struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //kiem tra neu cay la trong
   if(root == NULL) {
      root = tempNode;
   }else {
      current = root;
      parent = NULL;

      while(1) { 
         parent = current;
         
         //chuyen toi cay con ben trai
         if(data < parent->data) {
            current = current->leftChild;                
            
            //chen du lieu vao cay con ben trai
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }//chuyen toi cay con ben phai
         else {
            current = current->rightChild;

            //chen du lieu vao cay con ben phai
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }            
   }
}

struct node* search(int data) {
   struct node *current = root;
   printf("Truy cap cac phan tu cua cay: ");

   while(current->data != data) {
      if(current != NULL)
         printf("%d ",current->data); 

      //chuyen toi cay con ben trai
      if(current->data > data) {
         current = current->leftChild;
      }
      //chuyen toi cay con ben phai
      else {                
         current = current->rightChild;
      }

      //khong tim thay
      if(current == NULL) {
         return NULL;
      }
   }
   
   return current;
}

void pre_order_traversal(struct node* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->leftChild);
      pre_order_traversal(root->rightChild);
   }
}

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->leftChild);
      printf("%d ",root->data);          
      inorder_traversal(root->rightChild);
   }
}

void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->leftChild);
      post_order_traversal(root->rightChild);
      printf("%d ", root->data);
   }
}

void t1(struct node* root) {
	if(root != NULL) {
		printf("%d ", root->data);
		t1(root->leftChild);
		t1(root->rightChild);
		printf("%d ", root->data);
	}
}

int main() {
   int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

   for(i = 0; i < 7; i++)
      insert(array[i]);

   i = 31;
   struct node * temp = search(i);

   if(temp != NULL) {
      printf("[%d] Da tim thay phan tu.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Khong tim thay phan tu (%d).\n", i);
   }

   i = 15;
   temp = search(i);

   if(temp != NULL) {
      printf("[%d] Da tim thay phan tu.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Khong tim thay phan tu (%d).\n", i);
   }            

   printf("\nCach duyet tien thu tu: ");
   pre_order_traversal(root);

   printf("\nCach duyet trung thu tu: ");
   inorder_traversal(root);

   printf("\nCach duyet hau thu tu: ");
   post_order_traversal(root);       
	
	printf("\nCach duyet hau thu tu: ");
	t1(root);
   return 0;
}
