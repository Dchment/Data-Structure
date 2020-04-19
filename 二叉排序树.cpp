#include<stdio.h>
#include<stdlib.h> 
#define FALSE 0
#define TRUE 1
typedef struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
}*tree;

void createbst(tree &t){//һ��Ҫ������&����ΪҪ��t�ĵ�ַ����ֹ��ָ���ֵ���иı䣡	
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
}//����ʽ����������  

//���Ҷ��������� 
int searchbst(tree &t,int key,node *f,node *p){//tΪ������������keyΪ���ҹؼ��֣�fָ��t��˫�ף�p���ҳɹ�ʱָ��Ŀ���㣬����ʧ��ʱָ�������ʵ�һ����� 
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
//������ 
int insertbst(tree &t,int key){
	tree p,s;
	if(!searchbst(t,key,NULL,p)){//������һ�£�����������ݣ��Ͳ��ò��룬���û�У�p����ָ�������Ϊ˫�׵Ľ�� 
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

void deletenode(tree &t){//ɾ����㲢����ʣ����λ�õĺ��� 
	tree p,q;
	if(t->rchild==NULL){//ֻ�������������������� 
		p=t;
		t=t->lchild;
		free(p);
	}
	else if(t->lchild==NULL){//ֻ�������������������� 
		p=t;
		t=t->rchild;
		free(p);
	}
	else{//������������ 
		p=t;
		q=t->lchild;
		while(q->rchild!=NULL){//�ҵ�t��ֱ��ǰ������t������������󣬵��Ա�tС���Ǹ���㣡���ڶ��������������ʣ����û���Һ��ӣ��� 
			p=q;//p����q��˫�� 
			q=q->rchild;//q����t��ֱ��ǰ�� 
		}
		t->data=q->data;//��t�������滻Ϊ����ֱ��ǰ��q�����ݣ�֮���ֱ��ǰ���ĺ��ӽ��д��� 
		if(p!=t){//������� 
			p->rchild=q->lchild;//ֱ�ӽ�ǰ��q��������������˫��p���������� �����ڶ��������������ʣ�q���������Һ��ӣ� 
		}
		else{//������������t��ֱ��ǰ��q��˫����t������t��������û���Һ��ӣ�ֻ��qһ����㣩
			p->lchild=q->lchild;//�ǾͰ���֮ǰ����ֻ����/����������ķ������д��� 
		}
		free(q);
	}
}

void deletebst(tree &t,int key){//����������ɾ������ 
	if(!t){
		return FALSE;
	}
	else{
		if(key==t->data){//�ҵ����ִ��ɾ������ 
			return deletenode(t);
		}
		else if(key<t->data){//�ݹ�Ѱ����Ҫɾ���Ľ�� 
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
