#include<stdio.h>
#include<stdlib.h>
typedef struct bithrnode{
	char data;
	struct bithrnode *lchild,*rchild;
	int ltag;//������0����ָ���㣬1����ָ��ǰ������ 
	int rtag;
}bithrnode,*bithrtree;

bithrtree pre;//ȫ�ֱ�����ʼ��ָ��շ��ʹ��Ľ�� 
void createbithrtree(bithrtree *t){//ǰ��ʽ���������� 
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
void inthreading(bithrtree t){//������������� 
	if(t){
		inthreading(t->lchild);
		
		//����Ϊ��ʽִ�в��裡�ֱ������ֽ���ǰ������һ�����ĺ�� 
		if(!t->lchild){//����˽�������ӣ�������������Ϊ1����������ָ����ǰ�� 
			t->ltag=1;
			t->lchild=pre;
		}
		if(!pre->rchild){//�����һ�����ʹ��Ľ��û���Һ��ӣ�����Ϊ�����������ǰ������һ�����ĺ��Ҳ���Ǵ˽�㣡 
			pre->rtag=1;
			pre->rchild=t;
		}
		pre=t;//pre��������Ϊ�Ѿ����ʹ���������t��ͬʱҲ����һ��Ҫ���ʵĽ��Ŀ���ǰ�� 
		
		inthreading(t->rchild);
	}
}
void inorderthreading(bithrtree *p,bithrtree t){//�������������������ĺ��� 
	*p=(bithrtree)malloc(sizeof(bithrnode));//p��Ϊ����������������ͷָ�루����һ���������������������ʣ��������ӣ���㣩ָ������t�����Һ��ӣ�������ָ��������������һ����㣨�൱��p��ǰ���� 
	(*p)->ltag=0;
	(*p)->rtag=1;
	(*p)->rchild=*p;//p��ʼ�����
	if(!t){//tΪ��������p������ָ���Լ����� 
		(*p)->lchild=*p;
	} 
	else{//t���ǿ��������������
	    //��ʼ�� 
		(*p)->lchild=t;//��t��ʼ��Ϊ����� 
		pre=*p;//��pre��ʼ��������Ҫ�������� 
		
		//������������� 
		inthreading(t);//ִ��������������������ģ� 
		
		//��β�� pre��ʱ��������������һ�������ʵĽ�㣬���Ҫ�����Һ��ӣ���̣�ָ������������������ͷָ��p��preΪp��ǰ����p��pre�ĺ�̣��Ӷ��γ�һ��ѭ���� 
		pre->rtag=1;
		pre->rchild=*p;
		(*p)->rchild=pre;
	}
}
void inordertraverse(bithrtree t){//���ݹ������������������,t������������������ͷָ����Ǹ����ָ�룡 
	bithrtree p;
	p=t->lchild; 
	while(p!=t){
		while(p->ltag==0){
			p=p->lchild;
		}
		printf("%c ",p->data);
		while(p->rtag==1&&p->rchild!=t){
			p=p->rchild;//�����������ĺô������õݹ����ջ��������ֻҪ����������Ϊ1��������ָ���ֱ��ָ���˴˽��ĺ�̣�
			//��������Ϊ0���˽�����Һ���ʱ���Һ��ӱ������Ǵ˽��������̣�
			//��ˣ�ֻҪ�ߵ����ӣ�������ߺ�ͣ���ұ��߾Ϳ����ˣ� 
			printf("%c ",p->data);
		}
		p=p->rchild;//p�ݽ� 
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
