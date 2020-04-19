#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node,*clinklist;

void initclinklist(clinklist &l){
	fflush(stdin);
	l=(node *)malloc(sizeof(node));
	l->data=0;
	l->next=l;
}
void showclinklist(clinklist &l){
	node *temp=l->next;
	for(temp=l->next;temp->next!=l;temp=temp->next){
		printf("%d ",temp->data);
	}
	printf("\n");
}
void insertclinklist(clinklist &l,int a){
	node *temp;
	node *target;
	for(temp=l;temp->next!=l;temp=temp->next){}
	target=(node *)malloc(sizeof(node));
	target->data=a;
	temp->next=target;
	target->next=l;
}
int main(){
	clinklist l=NULL;
	initclinklist(l);
	insertclinklist(l,1);
	insertclinklist(l,2);
	insertclinklist(l,3);
	showclinklist(l);

}
