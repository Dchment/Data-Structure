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
typedef int shortpath[NUM][NUM];
typedef int patharc[NUM][NUM];
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

void floyd(dgraph &g,shortpath &s/*存储两顶点之间的最短距离！*/ ,patharc &p/*用于存储从一个顶点到另一个顶点的最短路径的必要前驱顶点（必须经过的点）*/){
	int v,w,k; 
	for(v=0;v<g.nodenum;v++){//初始化
		for(w=0;w<g.nodenum;w++){
			s[v][w]=g.am[v][w].data;//边路径输入 
			p[v][w]=w;//各点到其他点假设为“直接就能到” 
		}
	}

//同迪杰斯特拉算法一样，测试：起点已有最短路径+一个前驱顶点 or 起点已有最短路径+起点终点直连=终点的最短路径 
	for(k=0;k<g.nodenum;k++){//k:用于测试“绕路”是否更近，作为前驱顶点 
		for(v=0;v<g.nodenum;v++){//v:起点 
			for(w=0;w<g.nodenum;w++){//w:终点 
				if(s[v][w]>s[v][k]+s[k][w]){//如果“绕路”更近 
					s[v][w]=s[v][k]+s[k][w];//将最短路径长度替换为“绕远路的长度” 
					p[v][w]=p[v][k];//从v到w的最短路径的前驱顶点设为与从v到k的路线（绕的路）一样 
				}
			}
	    }
	}
}

int main(){
}	
	
	
