#include<stdio.h>
#include<stdlib.h>
#define NUM 10
#define INF 65535 
typedef struct{
	int begin;
	int end;
	int weight;
}edge;

typedef struct{//邻接矩阵型无向图 
	int node[NUM];
	int nodevisited[NUM];
	int matrix[NUM][NUM];
	int nodenum=0;
	int arcnum=0;
}graph;
void initgraph(graph &g){
	for(int i=0;i<NUM;i++){
		g.node[i]=0;
		g.nodevisited[i]=0;
		for(int j=0;j<10;j++){
			g.matrix[i][j]=INF;
		}
    }
}
void addnode(graph &g,int a){
	g.node[g.nodenum]=a;
	g.nodenum++;
}
void addarc(graph &g,int a,int b,int c){
	g.matrix[a][b]=c;
	g.matrix[b][a]=c;
	g.arcnum++;
}
int getarc(graph &g,edge *e){
	int count=0;
	for(int i=0;i<NUM;i++){
		for(int j=0;j<i;j++){
			if(g.matrix[i][j]<INF){
				e[count].begin=i;
				e[count].end=j;
				e[count].weight=g.matrix[i][j];
				count++;
			}
		}
	}
	//重点是对各边权值进行从小到大的排序！ (非常重要！！！！！！！！！！） 
	for(int i=0;i<count;i++)
	{
		for(int j=i;j<count;j++){
			if(e[i].weight>e[j].weight){
				edge temp;
				temp=e[j];
				e[j]=e[i];
				e[i]=temp;
			}
		}
	}
	for(int j=0;j<count;j++){
		printf("%d-%d,%d\n",e[j].begin,e[j].end,e[j].weight); 
	}
		
}


int find(int *parent,int a){//防止出现回路的函数 
	while(parent[a]>0){//如果已有边连接此点，即会出现回路 
		a=parent[a];//就连接与它连接的边的另一端结点（代表另一端和需要连接的点处在同一棵最小生成树中），如果还会出现回路就循环执行 
	}
	return a;
}
void minispantree_kruskal(graph g,edge edges[]){
	int i,n,m;
	int parent[NUM];//用于判断是否在树内会形成回路！ 
	
	for(i=0;i<g.nodenum;i++){//将parent初始化 
		parent[i]=0;
	} 
	
	for(i=0;i<g.arcnum;i++){
		n=find(parent,edges[i].begin);
		m=find(parent,edges[i].end);
		if(n!=m){//如果经过几次避免环路的函数执行后，n与m还是一样了,就代表会形成闭环，此边不应加入最小生成树！ 
			parent[n]=m;//将此边的结尾顶点放入parent中开头顶点的下标中，代表此顶点已进入最小生成树，连接的边也可以输出了 
			//或者，也可以代表此结尾顶点与下标代表顶点均在最小生成树中！
			printf("连接此边：%d-%d，权值为：%d\n",edges[i].begin,edges[i].end,edges[i].weight); 
		}
	} 
}
int main(){
	graph g;
	initgraph(g);
	addnode(g,0);
	addnode(g,1);
	addnode(g,2);
	addnode(g,3);
	addnode(g,4);
	addarc(g,0,1,1);
	addarc(g,0,2,2);
	addarc(g,1,3,3);
	addarc(g,1,4,4); 
	addarc(g,2,4,1);
	addarc(g,3,4,1);
	edge e[g.arcnum];
	getarc(g,e);
	minispantree_kruskal(g,e);
} 
