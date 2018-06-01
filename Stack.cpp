#include <stdio.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isEmpty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isFull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int Top() {
   return stack[top];
}


int pop() {
   int data;
	
   if(!isEmpty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   }else {
      printf("Khong the thu thap du lieu, ngan xep (Stack) la trong.\n");
   }
}

int push(int data) {

   if(!isFull()) {
      top = top + 1;   
      stack[top] = data;
   }else {
      printf("Khong the chen du lieu, ngan xep (Stack) da day.\n");
   }
}

int main() {
   // chen cac phan tu vao ngan xep
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);
   push(100);
   push(60);
   push(10);

   printf("Phan tu tai vi tri tren cung cua ngan xep: %d\n" ,Top());
   printf("Cac phan tu: \n");

   // in cac phan tu trong ngan xep
   while(!isEmpty()) {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Ngan xep da day: %s\n" , isFull()?"true":"false");
   printf("Ngan xep la trong: %s\n" , isEmpty()?"true":"false");
   
   return 0;
}
