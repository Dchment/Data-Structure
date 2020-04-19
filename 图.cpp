#include<stdio.h>
#include<stdlib.h>
typedef struct{//邻接矩阵型无向图 
	int node[10];
	int nodevisited[10];
	int matrix[10][10];
	int nodenum=0;
	int arcnum=0;
}graph;

typedef struct{
	int *body;
	int front;
	int rear;
	int total;
	int num;
}nodequeue;//队列用于广度优先遍历 



void initqueue(nodequeue &q,graph &g){
	q.body=(int *)malloc(sizeof(int)*g.nodenum);
	q.front=0;
	q.rear=0;
	q.total=g.nodenum;
	q.num=0;
}
void enqueue(nodequeue &q,int a){
	if((q.rear+1)%q.total==q.front)
	exit(0);
	q.body[q.rear]=a;
	q.rear=(q.rear+1)%q.total;
	if(q.num<q.total)
	q.num++;
}
void dequeue(nodequeue &q,int *a){
	if(q.rear==q.front)
	exit(0);
	*a=q.body[q.front];
	q.front=(q.front+1)%q.total;
	if(q.num>0)
	q.num--;
}

void initgraph(graph &g){
	for(int i=0;i<10;i++){
		g.node[i]=0;
		g.nodevisited[i]=0;
		for(int j=0;j<10;j++){
			g.matrix[i][j]=0;
		}
    }
}
void addnode(graph &g,int a){
	g.node[g.nodenum]=a;
	g.nodenum++;
}
void addarc(graph &g,int a,int b){
	g.matrix[a][b]=1;
	g.matrix[b][a]=1;
	g.arcnum++;
}
void shownode(graph &g){
	for(int i=0;i<g.nodenum;i++){
		printf("%d ",g.node[i]);
	}
	printf("\n");
}
void showarc(graph &g){
	for(int i=0;i<10;i++){
		for(int j=i;j<10;j++){
			if(g.matrix[i][j]!=0){
				printf("%d--%d\n",i,j);
			}
		}
    }
}
int getarc(graph &g,int a,int b){
		if(g.matrix[a][b]!=0||g.matrix[b][a]!=0){
			return 1;
		}
		else{
			return 0;
		}
}
void dfs(graph &g,int a){//深度优先遍历 
	g.nodevisited[a]=1;
	printf("%d ",g.node[a]);
	for(int i=0;i<g.nodenum;i++){
		int value=getarc(g,a,i);
		if(value!=0){
			if(g.nodevisited[i]!=0){
				continue;
			}
			else{
				dfs(g,i);
			}
		}
		else{
			continue;
		}
	}
}
void bfs(graph &g){//广度优先遍历 
	int i,j;
	nodequeue q;
	initqueue(q,g);
	for(i=0;i<g.nodenum;i++){
		if(g.nodevisited[i]==0){
		g.nodevisited[i]=1;
		printf("%d ",g.node[i]);
		enqueue(q,i);
		while(q.num!=0){
			dequeue(q,&i);
			for(j=0;j<g.nodenum;j++){
				if(getarc(g,i,j)==1&&g.nodevisited[j]==0)
				{
					printf("%d ",g.node[j]);
					g.nodevisited[j]=1;
					enqueue(q,j);
				}
			}
		}
		
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
	addarc(g,0,1);
	addarc(g,0,2);
	addarc(g,1,3);
	addarc(g,1,4); 
	printf("%d,%d\n",g.nodenum,g.arcnum);
	shownode(g);
	showarc(g);
	bfs(g);
}
