#include<stdio.h>
#include<stdlib.h>
typedef struct bithrnode{
	char data;
	struct bithrnode *lchild,*rchild;
	int ltag;//线索，0代表指向结点，1代表指向前驱与后继 
	int rtag;
}bithrnode,*bithrtree;

bithrtree pre;//全局变量，始终指向刚访问过的结点 
void createbithrtree(bithrtree *t){//前序方式创建二叉树 
	char c;
	scanf("%c",&c);
	if(c=='#'){
		*t=NULL;
	}
	else{
		*t=(bithrtree)malloc(sizeof(bithrnode));
		(*t)->data=c;
		(*t)->ltag=0;
		(*t)->rtag=0;
		createbithrtree(&(*t)->lchild);
		createbithrtree(&(*t)->rchild);
	}
}
void inthreading(bithrtree t){//中序遍历线索化 
	if(t){
		inthreading(t->lchild);
		
		//下面为正式执行步骤！分别设置现结点的前驱和上一个结点的后继 
		if(!t->lchild){//如果此结点无左孩子，则将其左线索设为1，让其左孩子指向其前驱 
			t->ltag=1;
			t->lchild=pre;
		}
		if(!pre->rchild){//如果上一个访问过的结点没有右孩子，则其为现在这个结点的前驱！上一个结点的后继也就是此结点！ 
			pre->rtag=1;
			pre->rchild=t;
		}
		pre=t;//pre跟进，成为已经访问过的这个结点t，同时也是下一个要访问的结点的可能前驱 
		
		inthreading(t->rchild);
	}
}
void inorderthreading(bithrtree *p,bithrtree t){//整个创建线索二叉树的函数 
	*p=(bithrtree)malloc(sizeof(bithrnode));//p作为整个线索二叉树的头指针（并不一定遵守线索二叉树的性质），其左孩子（结点）指向根结点t，其右孩子（线索）指向中序遍历的最后一个结点（相当于p的前驱） 
	(*p)->ltag=0;
	(*p)->rtag=1;
	(*p)->rchild=*p;//p初始化完毕
	if(!t){//t为空树，则p的左孩子指向自己就行 
		(*p)->lchild=*p;
	} 
	else{//t不是空树（正常情况）
	    //初始化 
		(*p)->lchild=t;//将t初始化为根结点 
		pre=*p;//将pre初始化（很重要！！！） 
		
		//中序遍历线索化 
		inthreading(t);//执行中序遍历线索化（核心） 
		
		//收尾： pre此时是中序遍历中最后一个被访问的结点，因此要让其右孩子（后继）指向整个线索二叉树的头指针p，pre为p的前驱，p是pre的后继，从而形成一个循环！ 
		pre->rtag=1;
		pre->rchild=*p;
		(*p)->rchild=pre;
	}
}
void inordertraverse(bithrtree t){//不递归中序遍历线索二叉树,t是整个线索二叉树的头指针而非根结点指针！ 
	bithrtree p;
	p=t->lchild; 
	while(p!=t){
		while(p->ltag==0){
			p=p->lchild;
		}
		printf("%c ",p->data);
		while(p->rtag==1&&p->rchild!=t){
			p=p->rchild;//线索二叉树的好处：不用递归或用栈来遍历，只要结点的右线索为1，右线索指针就直接指向了此结点的后继！
			//而右线索为0，此结点有右孩子时，右孩子本来就是此结点的中序后继！
			//因此，只要走到（子）树最左边后不停往右边走就可以了！ 
			printf("%c ",p->data);
		}
		p=p->rchild;//p递进 
	}
	printf("\n");
}
int main(){
	bithrtree p;
	bithrtree t=NULL;
	createbithrtree(&t);
	inorderthreading(&p,t);
	inordertraverse(p);
} 
