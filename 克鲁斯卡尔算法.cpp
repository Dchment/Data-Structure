#include<stdio.h>
#include<stdlib.h>
#define NUM 10
#define INF 65535 
typedef struct{
	int begin;
	int end;
	int weight;
}edge;

typedef struct{//�ڽӾ���������ͼ 
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
	//�ص��ǶԸ���Ȩֵ���д�С��������� (�ǳ���Ҫ���������������������� 
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


int find(int *parent,int a){//��ֹ���ֻ�·�ĺ��� 
	while(parent[a]>0){//������б����Ӵ˵㣬������ֻ�· 
		a=parent[a];//�������������ӵıߵ���һ�˽�㣨������һ�˺���Ҫ���ӵĵ㴦��ͬһ����С�������У������������ֻ�·��ѭ��ִ�� 
	}
	return a;
}
void minispantree_kruskal(graph g,edge edges[]){
	int i,n,m;
	int parent[NUM];//�����ж��Ƿ������ڻ��γɻ�·�� 
	
	for(i=0;i<g.nodenum;i++){//��parent��ʼ�� 
		parent[i]=0;
	} 
	
	for(i=0;i<g.arcnum;i++){
		n=find(parent,edges[i].begin);
		m=find(parent,edges[i].end);
		if(n!=m){//����������α��⻷·�ĺ���ִ�к�n��m����һ����,�ʹ�����γɱջ����˱߲�Ӧ������С�������� 
			parent[n]=m;//���˱ߵĽ�β�������parent�п�ͷ������±��У�����˶����ѽ�����С�����������ӵı�Ҳ��������� 
			//���ߣ�Ҳ���Դ���˽�β�������±�����������С�������У�
			printf("���Ӵ˱ߣ�%d-%d��ȨֵΪ��%d\n",edges[i].begin,edges[i].end,edges[i].weight); 
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
