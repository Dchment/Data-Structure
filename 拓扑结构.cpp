#include<stdio.h>
#include<stdlib.h>
#define M 10
typedef struct arc{
	int nodeindex;
	arc *nextarc;
};//弧 
typedef struct node{
	int data;
	int in;//入度 
	arc *firstarc;
	int visit;
}nodearray[M];//结点（包括其连接着的弧） 
typedef struct{
	nodearray na;
	int nodenum=0;
	int arcnum=0;
}algraph;//邻接表型有向图

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
			stack[++top]=i;//入度为0的顶点入栈 
		}
	}
	while(top!=0){
		gettop=stack[top--];//出栈并输出此入度为0的结点 
		printf("%d ",g.na[gettop].data);
		count++;//结点已进入拓扑结构 
		for(e=g.na[gettop].firstarc;e;e=e->nextarc){
			k=e->nodeindex;//寻找所有上一个结点的邻接结点 
	        if(!(--g.na[k].in)){//核心：如果这个邻接结点除了与上一个入度为0的结点的连接之外就没有其他进入的连接了，它就是下一个入度为0的结点！ 
		        stack[++top]=k;
	        }
	    }
    }
    if(count<g.nodenum){
    	exit(0);
    }
}
