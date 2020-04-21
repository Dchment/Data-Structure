#include<stdio.h>
#include<stdlib.h>
#define NUM 10
#define INF 65535 
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
int getarc(graph &g,int a,int b){
		if(g.matrix[a][b]<INF||g.matrix[b][a]<INF){
			return 1;
		}
		else{
			return 0;
		}
}


void minispantree_prim(graph g){
	int min,i,j,k; 
	int adjnode[NUM];//存储所有顶点在最小生成树中与谁连接，一般每一个元素的值代表与此元素下标连接的最近且在最小生成树中的结点（核心1） 
	int lowweight[NUM];//存储与各顶点连接的最短边的权值 （核心2） 
	//将下标为0的点加入最小生成树，因为0为起始结点
	lowweight[0]=0; 
	adjnode[0]=0;
	//初始化（从下标为0的点开始执行算法） 
	for(i=0;i<g.nodenum;i++){
		lowweight[i]=g.matrix[0][i];//各顶点与下标为0的点相连的边的权值（没有相连则值为INF）设为各顶点相连最短边的初值 
		adjnode[i]=0;//最近顶点全初始化为下标为0的点 
	}
	for(i=0;i<g.nodenum;i++){
		min=INF;
		j=1;
		k=0;
		//遍历全部顶点 
		while(j<g.nodenum){
			if(lowweight[j]!=0/*不是结点自身且未加入最小生成树*/&&lowweight[j]<min){
				min=lowweight[j];//min存储最短路径的权值 
				k=j;//k存储权值最小边连接的另一端 
			}
			j++;
		}
		
		printf("顶点%d 连接了顶点%d，长度为%d\n",adjnode[k],k,lowweight[k]);
		lowweight[k]=0;//将当前顶点k的权值设为0，表明已加入最小生成树，完成了任务 
		//对邻接矩阵的k行开始遍历，即寻找下一个应该连接的边，其起点一端为已经加入最小生成树的当前顶点k！ 
		for(j=1;j<g.nodenum;j++){
			if(lowweight[j]!=0&&g.matrix[k][j]<lowweight[j]){
				lowweight[j]=g.matrix[k][j];//与j相连的最短边为k-j边 
				adjnode[j]=k;//k-j边加入最小生成树 
			}//同刚才遍历一样，找出最短路径 
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
	minispantree_prim(g);
}
