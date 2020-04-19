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
	printf("��˳�������沨�����ʽ��������������ÿո��������#�������룺\n");
	scanf("%c",&c);//һ��һ�����룡 
	while(c!='#'){
		int d,e;
		int i=0,j;
		while(isdigit(c)/*�ж��ַ�Ϊ�����ַ���*/){
			char buffer[10];
			buffer[i++]=c;
			buffer[i]='\0';
			scanf("%c",&c);
			if(c==' '/*����ֵΪ�ո�ʱ���������ֵ�������*/){
				j=(int)atof(buffer);//�ַ�����ת��Ϊ��ֵ 
				push(&s,j);
				i=0;
				break;
			}
		}
		switch(c){//��׺���ʽ�����㣺ǰ����Ϊ��������������Ϊ������� 
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
	printf("�����%d\n",a);
}

