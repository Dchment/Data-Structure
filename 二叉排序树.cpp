#include<stdio.h>
#include<stdlib.h> 
#define FALSE 0
#define TRUE 1
typedef struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
}*tree;

void createbst(tree &t){//一定要加引用&！因为要对t的地址而不止是指向的值进行改变！	
	int i;
	scanf("%d",&i);
	if(i==0){
		t=NULL;
	}
	else{
	t=(tree)malloc(sizeof(node));
	t->data=i;
	createtree(t->lchild);
	createtree(t->rchild);
    }
}//先序方式创建二叉树  

//查找二叉排序树 
int searchbst(tree &t,int key,node *f,node *p){//t为二叉排序树，key为查找关键字，f指向t的双亲，p查找成功时指向目标结点，查找失败时指向最后访问的一个结点 
	if(!t){
		p=f;
		return FALSE;
	}
	else if(key==t->data){
		p=t;
		return t->data;
	} 
	else if(key<t->data){
		return searchbst(t->lchild,key,t,p);
	}
	else{
		return searchbst(t->rchild,key,t,p);
	}
}
//插入结点 
int insertbst(tree &t,int key){
	tree p,s;
	if(!searchbst(t,key,NULL,p)){//先搜索一下，如果已有数据，就不用插入，如果没有，p正好指向可以作为双亲的结点 
		s=(tree)malloc(sizeof(node));
		s->data=key;
		s->lchild=s->rchild=NULL;
		if(!t){
			t=s;
		}
		else if(s->data<t->data){
			p->lchild=s;
		}
		else{
			p->rchild=s;
		}
		return TRUE;
	}
	else{
		return FALSE;
	}
} 

void deletenode(tree &t){//删除结点并处理剩余结点位置的函数 
	tree p,q;
	if(t->rchild==NULL){//只有左子树，左子树接上 
		p=t;
		t=t->lchild;
		free(p);
	}
	else if(t->lchild==NULL){//只有右子树，右子树接上 
		p=t;
		t=t->rchild;
		free(p);
	}
	else{//左右子树都有 
		p=t;
		q=t->lchild;
		while(q->rchild!=NULL){//找到t的直接前驱（即t的左子树中最大，但仍比t小的那个结点！由于二叉排序树的性质，其必没有右孩子！） 
			p=q;//p代表q的双亲 
			q=q->rchild;//q代表t的直接前驱 
		}
		t->data=q->data;//将t的数据替换为它的直接前驱q的数据，之后对直接前驱的孩子进行处理！ 
		if(p!=t){//正常情况 
			p->rchild=q->lchild;//直接将前驱q的子树接在它的双亲p的右子树上 （由于二叉排序树的性质，q不可能有右孩子） 
		}
		else{//特殊情况：如果t的直接前驱q的双亲是t本身（即t的左子树没有右孩子，只有q一个结点）
			p->lchild=q->lchild;//那就按照之前处理只有左/右子树情况的方法进行处理 
		}
		free(q);
	}
}

void deletebst(tree &t,int key){//二叉排序树删除操作 
	if(!t){
		return FALSE;
	}
	else{
		if(key==t->data){//找到结点执行删除函数 
			return deletenode(t);
		}
		else if(key<t->data){//递归寻找需要删除的结点 
			return deletebst(t->lchild,key);
		}
		else{
			return deletebst(t->rchild.key);
		}
	}
} 
int main(){
	tree t,p;
	tree f=NULL; 
	createbst(t);
}
