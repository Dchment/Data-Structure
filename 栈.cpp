#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
typedef struct stack{
	int *top;
	int *bottom;
	int size;
};
void initstack(stack &s){
	s.size=STACKSIZE;
	s.bottom=(int *)malloc(sizeof(int)*STACKSIZE);
	s.top=s.bottom;
}
void push(stack &s,int a){
	if(s.top-s.bottom>=s.size){
		s.bottom=(int *)realloc(s.bottom,sizeof(int)*(STACKSIZE+10));
		s.size+=10;
	}
	*s.top++=a;
}
void pop(stack &s,int &a){
	a=*--s.top;
}
void showstack(stack &s){
	int *temp=s.bottom;
	while(temp!=s.top){
		printf("%d ",*temp);
		temp++;
	}
}
void gettop(stack &s,int a){
	a=*(s.top-1);
} 
int main(){
	stack s;
	initstack(s);
	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	showstack(s);
	printf("\n");
	int e;
	pop(s,e);
	printf("%d\n",e);
	showstack(s);
}
