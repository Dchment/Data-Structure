#include<stdio.h>
#include<stdlib.h>
#define M 10
typedef struct arc{
	int nodeindex;
	arc *nextarc;
};//弧 
typedef struct node{
	int data;
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
	g.nodenum++; 
}
void shownode(algraph &g){
	for(int i=0;i<g.nodenum;i++){
		printf("%d ",g.na[i].data);
	}
	printf("\n");
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
	}
	
}
void showarc(algraph &g){
	for(int i=0;i<g.nodenum;i++){
		arc *now=g.na[i].firstarc;
		while(now!=NULL){
			printf("%d--%d\n",g.na[i].data,now->nodeindex);
			now=now->nextarc;
		}
	}
} 
void dfs(algraph &g,int a){
	g.na[a].visit=1;
	printf("%d ",searchnode(g,a));
	for(arc *w=g.na[searchnode(g,a)].firstarc;w!=NULL;w=w->nextarc){
		if(g.na[w->nodeindex].visit==0){
			dfs(g,w->nodeindex);
		}
	}
} 
int main(){
	algraph g;
	addnode(g,0);
	addnode(g,1);
	addnode(g,2);
	addnode(g,3);
	addnode(g,4);
	shownode(g);
	addarc(g,0,1);
	addarc(g,0,2);
	addarc(g,1,3);
	addarc(g,1,4);
	showarc(g);
	dfs(g,0);
} 
