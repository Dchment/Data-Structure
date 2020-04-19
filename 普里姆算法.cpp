#include<stdio.h>
#include<stdlib.h>
#define NUM 10
#define INF 65535 
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
	int adjnode[NUM];//�洢���ж�������С����������˭���ӣ�һ��ÿһ��Ԫ�ص�ֵ�������Ԫ���±����ӵ����������С�������еĽ�㣨����1�� 
	int lowweight[NUM];//�洢����������ӵ���̱ߵ�Ȩֵ ������2�� 
	//���±�Ϊ0�ĵ������С����������Ϊ0Ϊ��ʼ���
	lowweight[0]=0; 
	adjnode[0]=0;
	//��ʼ�������±�Ϊ0�ĵ㿪ʼִ���㷨�� 
	for(i=0;i<g.nodenum;i++){
		lowweight[i]=g.matrix[0][i];//���������±�Ϊ0�ĵ������ıߵ�Ȩֵ��û��������ֵΪINF����Ϊ������������̱ߵĳ�ֵ 
		adjnode[i]=0;//�������ȫ��ʼ��Ϊ�±�Ϊ0�ĵ� 
	}
	
	for(i=0;i<g.nodenum;i++){
		min=INF;
		j=1;
		k=0;
		//����ȫ������ 
		while(j<g.nodenum){
			if(lowweight[j]!=0/*���ǽ��������δ������С������*/&&lowweight[j]<min){
				min=lowweight[j];//min�洢���·����Ȩֵ 
				k=j;//k�洢Ȩֵ��С�����ӵ���һ�� 
			}
			j++;
		}
		
		printf("����%d �����˶���%d\n",adjnode[k],k);
		lowweight[k]=0;//����ǰ����Ȩֵ��Ϊ0�������Ѽ�����С����������������� 
		//���ڽӾ����k�п�ʼ������������һ��Ӧ�����ӵıߣ������һ��Ϊ�Ѿ�������С�������Ķ���k�� 
		for(j=1;j<g.nodenum;j++){
			if(lowweight[j]!=0&&g.matrix[k][j]<lowweight[j]){
				lowweight[j]=g.matrix[k][j];//��j��������̱�Ϊk-j�� 
				adjnode[j]=k;//k-j�߼�����С������ 
			}//ͬ�ղű���һ�����ҳ����·�� 
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
