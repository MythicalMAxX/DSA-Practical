#include <stdio.h>

#define size 10

int arry[size+1];
int top = 0;

int IsEmpty() {
if(top == 0)
  return 1;
return 0;
}

void push(int x) {
top = top+1;
if(top > size) {
  printf("Stack Overflow\n");
}
else {
  arry[top] = x;
}
}

int pop() {
if(IsEmpty()) {
  printf("Stack Underflow\n");
  return -1000;
}
else {
  top = top-1;
  return arry[top+1];
}
}

int main() {
pop();
push(1);
push(2);
push(3);
push(4);
push(5);
pop();
push(6);
push(7);
push(8);
push(9);
push(10);
push(11);
pop();

int i;
for(i=1; i<=size; i++) {
  printf("%d\n",arry[i]);
}
return 0;
}
