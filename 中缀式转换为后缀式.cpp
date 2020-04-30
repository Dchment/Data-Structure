#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
#define ERROR -1
typedef struct stack{
	int *top;
	int *bottom;
	int size;
};
void initstack(stack *s){
	s->size=STACKSIZE;
	s->bottom=(int *)malloc(sizeof(char)*STACKSIZE);
	s->top=s->bottom;
}
void push(stack *s,char a){
	if(s->top-s->bottom>=s->size){
		s->bottom=(int *)realloc(s->bottom,sizeof(char)*(STACKSIZE+10));
		s->size+=10;
	}
	*s->top++=a;
}
void pop(stack *s,char *a){
	if(s->top==s->bottom)
	exit(0); 
	*a=*(--s->top);
}
int stacklen(stack *s){
	int length=(s->top)-(s->bottom);
	return length;
}
int main(){
	stack s;
	char c,e;
	initstack(&s);
	scanf("%c",&c);
	while(c!='#'){
		while(c>='0'&&c<='9'){//�����־�ֱ������������������ջ�й� 
			printf("%c",c);
			scanf("%c",&c);
			if(c<'0'||c>'9'){//���������ʱ�ٿո����������ֵ�λ�� 
			printf(" ");
			}
		}
		if(c==')'){//����������� 
			pop(&s,&e); 
			while(e!='('){
				printf("%c",e);
				pop(&s,&e);
			}//����������֮���ȫ��������� 
		}
		else if(c=='+'||c=='-'){//����ǼӼ��� 
			if(!stacklen(&s)){
				push(&s,c);//��ջ�ͷŽ�ȥ 
			}
			else{
				do{//�Ӽ������ȼ���ͣ�Ҫ������ǰ���������Ƿ�Ҫ����֮ǰ�����ȥ 
					pop(&s,&e);//�ҼӼ���֮ǰ������� 
					if('('==e){
						push(&s,e);//�������žͲ��� 
					}
					else{//�����������������������üӼ������� 
						printf("%c",e);
					}
				}while(stacklen(&s)&&'('!=e);//ֱ����ջ��ֻ�������� 
				push(&s,c);//����Ӽ��� 
			}
		}
		else if('*'==c||'/'==c||'('==c){//�˳��������������������� 
			push(&s,c);
		}
		else if('#'==c){//����#��ֹͣ���� 
			break;
		}
		else{
			printf("����\n");
			return ERROR;
		}
		scanf("%c",&c);
	}
	while(stacklen(&s)){//��ջ������ʣ��������� 
		pop(&s,&e);
		printf("%c",e);
	}
	return 0;
}
