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
		while(c>='0'&&c<='9'){//是数字就直接输出，是运算符才与栈有关 
			printf("%c",c);
			scanf("%c",&c);
			if(c<'0'||c>'9'){//到输入符号时再空格，以区分数字的位数 
			printf(" ");
			}
		}
		if(c==')'){//如果是右括号 
			pop(&s,&e); 
			while(e!='('){
				printf("%c",e);
				pop(&s,&e);
			}//将左右括号之间的全部内容输出 
		}
		else if(c=='+'||c=='-'){//如果是加减号 
			if(!stacklen(&s)){
				push(&s,c);//空栈就放进去 
			}
			else{
				do{//加减号优先级最低，要考虑它前面的运算符是否要在它之前输出出去 
					pop(&s,&e);//找加减号之前的运算符 
					if('('==e){
						push(&s,e);//是左括号就不动 
					}
					else{//是其他运算符，就先输出，让加减号最后进 
						printf("%c",e);
					}
				}while(stacklen(&s)&&'('!=e);//直至空栈或只有左括号 
				push(&s,c);//放入加减号 
			}
		}
		else if('*'==c||'/'==c||'('==c){//乘除号与左括号无特殊需求 
			push(&s,c);
		}
		else if('#'==c){//见到#就停止输入 
			break;
		}
		else{
			printf("出错！\n");
			return ERROR;
		}
		scanf("%c",&c);
	}
	while(stacklen(&s)){//将栈中所有剩余内容输出 
		pop(&s,&e);
		printf("%c",e);
	}
	return 0;
}
