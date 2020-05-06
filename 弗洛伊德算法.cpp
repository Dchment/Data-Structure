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

void floyd(dgraph &g,shortpath &s/*�洢������֮�����̾��룡*/ ,patharc &p/*���ڴ洢��һ�����㵽��һ����������·���ı�Ҫǰ�����㣨���뾭���ĵ㣩*/){
	int v,w,k; 
	for(v=0;v<g.nodenum;v++){//��ʼ��
		for(w=0;w<g.nodenum;w++){
			s[v][w]=g.am[v][w].data;//��·������ 
			p[v][w]=w;//���㵽���������Ϊ��ֱ�Ӿ��ܵ��� 
		}
	}

//ͬ�Ͻ�˹�����㷨һ�������ԣ�����������·��+һ��ǰ������ or ����������·��+����յ�ֱ��=�յ�����·�� 
	for(k=0;k<g.nodenum;k++){//k:���ڲ��ԡ���·���Ƿ��������Ϊǰ������ 
		for(v=0;v<g.nodenum;v++){//v:��� 
			for(w=0;w<g.nodenum;w++){//w:�յ� 
				if(s[v][w]>s[v][k]+s[k][w]){//�������·������ 
					s[v][w]=s[v][k]+s[k][w];//�����·�������滻Ϊ����Զ·�ĳ��ȡ� 
					p[v][w]=p[v][k];//��v��w�����·����ǰ��������Ϊ���v��k��·�ߣ��Ƶ�·��һ�� 
				}
			}
	    }
	}
}

int main(){
}	
	
	
