#include<stdio.h>
#include<stdlib.h>
#define LH 1
#define EQ 0
#define RH -1
typedef struct node{
	int data;
	int bf;//平衡因子
	struct node *rchild,*lchild; 
}*tree;

void r_rotate(tree &t/*主结点*/){//右旋 
	tree l;
	l=t->lchild;
	t->lchild=l->rchild;
	l->rchild=t;
	t=l;
}
void l_rotate(tree &t){//左旋 
	tree l;
	l=t->rchild;
	t->rchild=l->lchild;
	l->lchild=t;
	t=l;
}

void leftbalance(tree &t){//平衡二叉树左边失衡处理 
	tree l,lr;
	l=t->lchild;
	switch(l->bf){
		case LH://“左左”情况 ：（以头结点为主结点）右旋 
			t->bf=l->bf=EQ;//先修改子树当前根结点与其左孩子的平衡因子，因为右旋后根结点会变成右孩子，左孩子会变成根结点！右旋后均会平衡！ 
			r_rotate(t);
			break;
		case RH://“左右”情况 ：先（以头结点的右孩子为主结点）左旋再（以头结点为主结点）右旋 
			lr=l->rchild;
			switch(lr->bf){
				case LH://如果添加后根结点左孩子的右孩子lr平衡因子为1 
					t->bf=RH;//最后旋转完后根结点t会变成根结点右孩子，其平衡因子会变为-1 
					l->bf=EQ;//最后旋转完后根结点左孩子l会变成根结点，其平衡因子会变为0
					break;
				case EQ://如果添加后根结点左孩子的右孩子lr平衡因子为0 
					t->bf=l->bf=EQ;
					break;
				case RH://如果添加后根结点左孩子的右孩子lr平衡因子为-1 
					t->bf=EQ;
					l->bf=LH;
					break;
			}
			lr->bf=EQ;
			l_rotate(t->lchild);
			r_rotate(t);
			break;
	}
}
void rightbalance(tree &t){//平衡二叉树右边失衡处理 
	tree l,lr;
	l=t->rchild;
	switch(l->bf){
		case RH://“右右”情况 ：（以头结点为主结点）左旋 
			t->bf=l->bf=EQ;
			l_rotate(t);
			break;
		case LH://“右左”情况： 先（以头结点的左孩子为主结点）右旋再（以头结点为主结点）左旋 
			lr=l->lchild;
			switch(lr->bf){
				case RH:
					t->bf=LH;
					l->bf=EQ;
					break;
				case EQ:
					t->bf=l->bf=EQ;
					break;
				case LH:
					t->bf=EQ;
					l->bf=RH;
					break;
			}
			lr->bf=EQ;
			r_rotate(t->rchild);
			l_rotate(t);
	}
}

int insertavl(tree &t,int a,int *istaller/*标志平衡二叉树是否深度增加了*/){
	if(!t){
		t=(tree)malloc(sizeof(node));
		t->data=a;
		t->lchild=t->rchild=NULL;
		t->bf=EQ;
		*istaller=1;
	}
	else{
		if(a==t->data){
			*istaller=0;
			return 0;
		}
		if(a<t->data){//增加的是左孩子 
			if(!insertavl(t->lchild,a,istaller)){
				return 0;
			}
			if(*istaller){//如果深度增加了，需要对可能的失衡进行平衡处理 
				switch(t->bf)
				{
					case LH://如果本来左边就高，需要进行左平衡处理，树会回归原来的深度 
						leftbalance(t);
						*istaller=0;
						break;
					case EQ://如果原来树的两边等高，添加后左边就高了，深度增加1 
						t->bf=LH;
						*istaller=1;
						break;
					case RH://如果本来右边就高，就平衡了，树深度不变 
						t->bf=EQ;
						*istaller=0;
						break;	 
				}
			}
		}
		else{//增加的是右孩子，同左孩子类似的处理方式 
			if(!insertavl(t->rchild,a,istaller)){
					return 0;
				}
			}
			if(*istaller){
				switch(t->bf)
				{
					case LH:
						t->bf=EQ;
						*istaller=0;
						break;
					case EQ:
						t->bf=RH;
						*istaller=1;
						break;
					case RH:
						rightbalance(t);
						*istaller=0;
						break;	 
				}
			}
	}
}
int main(){
	
}
