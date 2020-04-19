#include<stdio.h> 
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}*linkq;
void initlinkq(linkq &q){
	q=(linkq)malloc(sizeof(node));
	q->next=NULL;
	q->data=0;
}
void insertnode(linkq &q,int a){
	linkq l=q;
	while(l->next!=NULL){
		l=l->next;
	}
	linkq in=(linkq)malloc(sizeof(node));
	in->data=a;
	l->next=in;
	in->next=NULL;
}
void showlinkq(linkq &q){
	linkq temp=q;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void deletenode(linkq &q,int a){
	linkq l=q;
	linkq before=q;
	while(l->data!=a){
		before=l;
		l=l->next;
	}
	if(l==NULL){
		printf("Î´ÕÒµ½£¡");
	}
	else{
		before->next=l->next;
		l->next=NULL;
		free(l);
	}
}
int main(){
	linkq q;
	initlinkq(q);
	insertnode(q,1);
	insertnode(q,2);
	showlinkq(q);
	deletenode(q,1);
	showlinkq(q);
}
