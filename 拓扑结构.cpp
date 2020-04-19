#include<stdio.h>
#include<stdlib.h>
#define M 10
typedef struct arc{
	int nodeindex;
	arc *nextarc;
};//�� 
typedef struct node{
	int data;
	int in;//��� 
	arc *firstarc;
	int visit;
}nodearray[M];//��㣨�����������ŵĻ��� 
typedef struct{
	nodearray na;
	int nodenum=0;
	int arcnum=0;
}algraph;//�ڽӱ�������ͼ

void addnode(algraph &g,int a){
	g.na[g.nodenum].data=a;
	g.na[g.nodenum].firstarc=NULL;
	g.na[g.nodenum].visit=0;
	g.na[g.nodenum].in=0;
	g.nodenum++; 
}
int searchnode(algraph &g,int a){
	for(int i=0;i<g.nodenum;i++){
		if(g.na[i].data==a){
			return i;
		}
	}
}
void addarc(algraph &g,int a,int b){
	if(g.na[searchnode(g,a)].firstarc==NULL){
		arc *s=(arc *)malloc(sizeof(arc));
	    s->nodeindex=searchnode(g,b);
	    s->nextarc=NULL;
	    g.na[searchnode(g,a)].firstarc=s;
	    g.arcnum++;
	    g.na[searchnode(g,b)].in++;
	}
	else{
		arc *s=(arc *)malloc(sizeof(arc));
	    s->nodeindex=searchnode(g,b);
	    s->nextarc=NULL;
	    arc *now=g.na[searchnode(g,a)].firstarc;
		while(now->nextarc!=NULL){
			now=now->nextarc;
		}
		now->nextarc=s;
		g.arcnum++;
		g.na[searchnode(g,b)].in++;
	}	
}

void topologicalsort(algraph g){
	arc *e;
	int i,k,gettop;
	int top=0;
	int count=0;
	int *stack;
	stack=(int *)malloc(sizeof(int)*g.nodenum);
	
	for(i=0;i<g.nodenum;i++){
		if(g.na[i].in==0){
			stack[++top]=i;//���Ϊ0�Ķ�����ջ 
		}
	}
	while(top!=0){
		gettop=stack[top--];//��ջ����������Ϊ0�Ľ�� 
		printf("%d ",g.na[gettop].data);
		count++;//����ѽ������˽ṹ 
		for(e=g.na[gettop].firstarc;e;e=e->nextarc){
			k=e->nodeindex;//Ѱ��������һ�������ڽӽ�� 
	        if(!(--g.na[k].in)){//���ģ��������ڽӽ���������һ�����Ϊ0�Ľ�������֮���û����������������ˣ���������һ�����Ϊ0�Ľ�㣡 
		        stack[++top]=k;
	        }
	    }
    }
    if(count<g.nodenum){
    	exit(0);
    }
}
