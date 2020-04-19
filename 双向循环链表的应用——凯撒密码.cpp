#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0

typedef char etype;
typedef struct dualnode{
	etype data;
	struct dualnode *prior;
	struct dualnode *next;
}dualnode,*(duallist);

int initlist(duallist &l){
	dualnode *p,*q;
	int i;
	l=(duallist)malloc(sizeof(dualnode));
	if(!l){
		return ERROR;
	}
	l->next=l->prior=NULL;
	p=l;
	for(i=0;i<26;i++){
		q=(dualnode *)malloc(sizeof(dualnode));
		if(!q){
			return ERROR;
		}
		q->data='A'+i;
		q->prior=p;
		q->next=p->next;
		p->next=q;
		p=q;
	}
	p->next=l->next;
	l->next->prior=p;
	return OK;
} 

void caecar(duallist &l,int i){
	if(i>0){
		do{
			l=l->next;//直接调整链表开始遍历的位置就行！ 
		}while(--i);
	}
	if(i<0){
		do{
			l=l->next;
		}while(++i);
	}
}
int main(){
	int i,n;
	scanf("%d",&n);
	duallist l;
	initlist(l);
	caecar(l,n);
	for(i=0;i<26;i++){
		l=l->next;
		printf("%c",l->data);
	}
}
