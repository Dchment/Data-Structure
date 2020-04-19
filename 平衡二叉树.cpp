#include<stdio.h>
#include<stdlib.h>
#define LH 1
#define EQ 0
#define RH -1
typedef struct node{
	int data;
	int bf;//ƽ������
	struct node *rchild,*lchild; 
}*tree;

void r_rotate(tree &t/*�����*/){//���� 
	tree l;
	l=t->lchild;
	t->lchild=l->rchild;
	l->rchild=t;
	t=l;
}
void l_rotate(tree &t){//���� 
	tree l;
	l=t->rchild;
	t->rchild=l->lchild;
	l->lchild=t;
	t=l;
}

void leftbalance(tree &t){//ƽ����������ʧ�⴦�� 
	tree l,lr;
	l=t->lchild;
	switch(l->bf){
		case LH://��������� ������ͷ���Ϊ����㣩���� 
			t->bf=l->bf=EQ;//���޸�������ǰ������������ӵ�ƽ�����ӣ���Ϊ��������������Һ��ӣ����ӻ��ɸ���㣡���������ƽ�⣡ 
			r_rotate(t);
			break;
		case RH://�����ҡ���� ���ȣ���ͷ�����Һ���Ϊ����㣩�����٣���ͷ���Ϊ����㣩���� 
			lr=l->rchild;
			switch(lr->bf){
				case LH://�����Ӻ��������ӵ��Һ���lrƽ������Ϊ1 
					t->bf=RH;//�����ת�������t���ɸ�����Һ��ӣ���ƽ�����ӻ��Ϊ-1 
					l->bf=EQ;//�����ת�����������l���ɸ���㣬��ƽ�����ӻ��Ϊ0
					break;
				case EQ://�����Ӻ��������ӵ��Һ���lrƽ������Ϊ0 
					t->bf=l->bf=EQ;
					break;
				case RH://�����Ӻ��������ӵ��Һ���lrƽ������Ϊ-1 
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
void rightbalance(tree &t){//ƽ��������ұ�ʧ�⴦�� 
	tree l,lr;
	l=t->rchild;
	switch(l->bf){
		case RH://�����ҡ���� ������ͷ���Ϊ����㣩���� 
			t->bf=l->bf=EQ;
			l_rotate(t);
			break;
		case LH://����������� �ȣ���ͷ��������Ϊ����㣩�����٣���ͷ���Ϊ����㣩���� 
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

int insertavl(tree &t,int a,int *istaller/*��־ƽ��������Ƿ����������*/){
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
		if(a<t->data){//���ӵ������� 
			if(!insertavl(t->lchild,a,istaller)){
				return 0;
			}
			if(*istaller){//�����������ˣ���Ҫ�Կ��ܵ�ʧ�����ƽ�⴦�� 
				switch(t->bf)
				{
					case LH://���������߾͸ߣ���Ҫ������ƽ�⴦������ع�ԭ������� 
						leftbalance(t);
						*istaller=0;
						break;
					case EQ://���ԭ���������ߵȸߣ���Ӻ���߾͸��ˣ��������1 
						t->bf=LH;
						*istaller=1;
						break;
					case RH://��������ұ߾͸ߣ���ƽ���ˣ�����Ȳ��� 
						t->bf=EQ;
						*istaller=0;
						break;	 
				}
			}
		}
		else{//���ӵ����Һ��ӣ�ͬ�������ƵĴ���ʽ 
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
