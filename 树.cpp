#include<stdio.h>
#include<stdlib.h> 
typedef struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
}*tree;
int count=0;
void createtree(tree &t){//һ��Ҫ������&����ΪҪ��t�ĵ�ַ����ֹ��ָ���ֵ���иı䣡	
	int i;
	scanf("%d",&i);
	if(i==0){
		t=NULL;
	}
	else{
	t=(tree)malloc(sizeof(node));
	t->data=i;
	count++;
	createtree(t->lchild);
	createtree(t->rchild);
    }
}//����ʽ���������� 
void fot(tree t){//������� 
	if(t!=NULL){
	printf("%d ",t->data);
	fot(t->lchild);
	fot(t->rchild);
    }
}
void mot(tree t){//������� 
	if(t!=NULL){
	mot(t->lchild);
	printf("%d ",t->data);
	mot(t->rchild);
    }	
}
void pot(tree t){//������� 
	if(t!=NULL){
	pot(t->lchild);
	pot(t->rchild);
	printf("%d ",t->data);
    }
}
int main(){
	tree t;
	createtree(t);
	fot(t);
	printf("\n");
	mot(t);
	printf("\n");
	pot(t); 
	printf("\n");
    return 0;
}
