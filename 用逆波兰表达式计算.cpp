#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define STACKSIZE 10
typedef struct stack{
	int *top;
	int *bottom;
	int size;
};
void initstack(stack *s){
	s->size=STACKSIZE;
	s->bottom=(int *)malloc(sizeof(int)*STACKSIZE);
	s->top=s->bottom;
}
void push(stack *s,int a){
	if(s->top-s->bottom>=s->size){
		s->bottom=(int *)realloc(s->bottom,sizeof(int)*(STACKSIZE+10));
		s->size+=10;
	}
	*s->top++=a;
}
void pop(stack *s,int *a){
	if(s->top==s->bottom)
	exit(0); 
	*a=*(--s->top);
}
int main(){
	stack s;
	initstack(&s);
	char c;
	printf("按顺序输入逆波兰表达式，数字与运算符用空格隔开，用#结束输入：\n");
	scanf("%c",&c);//一个一个输入！ 
	while(c!='#'){
		int d,e;
		int i=0,j;
		while(isdigit(c)/*判断字符为数字字符！*/){
			char buffer[10];
			buffer[i++]=c;
			buffer[i]='\0';
			scanf("%c",&c);
			if(c==' '/*输入值为空格时代表这个数值输入完毕*/){
				j=(int)atof(buffer);//字符数组转换为数值 
				push(&s,j);
				i=0;
				break;
			}
		}
		switch(c){//后缀表达式的运算：前两个为运算数，第三个为运算符！ 
			case '+':
				pop(&s,&d);
				pop(&s,&e);
				push(&s,d+e);
				break;
			case '-':
				pop(&s,&d);
				pop(&s,&e);
				push(&s,d-e);
				break;
			case '*':
				pop(&s,&d);
				pop(&s,&e);
				push(&s,d*e);
				break;
			case '/':
				pop(&s,&d);
				pop(&s,&e);
				if(e=='0')
				return -1;
				push(&s,d/e);
				break;
		}
		scanf("%c",&c);
	}
	int a;
	pop(&s,&a);
	printf("结果：%d\n",a);
}

