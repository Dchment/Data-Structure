#include<stdio.h>
#define NUM 5
#define TRUE 1
#define FALSE 0
#define INF 65535
typedef struct{
	int head;
	int tail;
	int data;
}arc,arcmatrix[NUM][NUM];
typedef struct{
	arcmatrix am;
	int nodelist[NUM];
	int arcnum;
	int nodenum; 
}dgraph; 
typedef int shortpath[NUM];
typedef int patharc[NUM];
void initgraph(dgraph &g){
	for(int i=0;i<NUM;i++){
		for(int j=0;j<NUM;j++){
			g.am[i][j].data=INF;
		}
	}
	for(int i=0;i<NUM;i++){
		g.nodelist[i]=i;
	}
	g.arcnum=0;
	g.nodenum=NUM;
}
void addarc(dgraph &g,int a,int b,int c){
	g.am[a][b].data=c;
	g.am[a][b].tail=a;
	g.am[a][b].head=b;
	g.arcnum++;
}
//迪杰斯特拉算法是一种贪心算法，每次都找与当前结点连接的最短边 
void dij(dgraph &g,int v0,shortpath &s/*存储起点v0点到各其他点之间的最短路径！*/ ,patharc &p/*用于存储最短路径的边（的两端）*/,int *final/*记录最短路径的结点构成*/){
	int min;
	int v,w,i,j,k,sn;
	for(v=0;v<g.nodenum;v++){//初始化 
		final[v]=FALSE;
		s[v]=g.am[v0][v].data;
		p[v]=0;
	}
	s[v0]=0;
	final[v0]=TRUE;
	for(i=1;i<g.nodenum;i++){//找出离v0点目前相连且距离最近的点 
		min=INF;
		for(j=0;j<g.nodenum;j++){
			if(!final[j]){
				if(s[j]<min){
					min=s[j];//min逐步更新为目前距离最短且未加入最短路径的v0相连边 
					v=j;//v变为起点为v0，长度为min的路程连接的未加入最短路径的另一端结点j 
				}
			}
		}
		final[v]=TRUE;//此结点v加入最短路径 
		
		for(k=0;k<g.nodenum;k++){//更新最短路径数组s与p，防止出现因贪心算法导致的绕远路情况 
			if(!final[k]&&(min/*v0到刚加入的结点v的最短路径*/+g.am[v][k].data
			/*刚加入的结点v连接到k的距离（可能为INF）*/<s[k]/*起点v0目前与结点k的最短距离（可能为INF*/)){
				s[k]=min+g.am[v][k].data;//到结点k的最短距离更新为v0通过刚加入的结点v连接 
				p[k]=v;//设置最短路径中k的前驱顶点为v 
			}
		}
	} 
}
int main(){
	dgraph g;
	shortpath sp;
	patharc p;
	int final[NUM];
	initgraph(g);
	addarc(g,0,1,10);
	addarc(g,0,4,100);
	addarc(g,1,2,50);
	addarc(g,2,3,20);
	addarc(g,3,4,60);
	addarc(g,0,3,30);
	addarc(g,2,4,10);
	int v0=0; 
	dij(g,v0,sp,p,final);
	printf("v0点到各点之间的距离：");
	for(int i=0;i<NUM;i++){
		printf("%d ",sp[i]);
	}
	printf("\n");
	printf("现在每个路线的前驱顶点：");
	for(int i=0;i<NUM;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
/*https://img2018.cnblogs.com/blog/1363376/201811/1363376-20181108111225400-321027694.jpg*/ 
