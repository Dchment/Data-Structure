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
//�Ͻ�˹�����㷨��һ��̰���㷨��ÿ�ζ����뵱ǰ������ӵ���̱� 
void dij(dgraph &g,int v0,shortpath &s/*�洢���v0�㵽��������֮������·����*/ ,patharc &p/*���ڴ洢���·���ıߣ������ˣ�*/,int *final/*��¼���·���Ľ�㹹��*/){
	int min;
	int v,w,i,j,k,sn;
	for(v=0;v<g.nodenum;v++){//��ʼ�� 
		final[v]=FALSE;
		s[v]=g.am[v0][v].data;
		p[v]=0;
	}
	s[v0]=0;
	final[v0]=TRUE;
	for(i=1;i<g.nodenum;i++){//�ҳ���v0��Ŀǰ�����Ҿ�������ĵ� 
		min=INF;
		for(j=0;j<g.nodenum;j++){
			if(!final[j]){
				if(s[j]<min){
					min=s[j];//min�𲽸���ΪĿǰ���������δ�������·����v0������ 
					v=j;//v��Ϊ���Ϊv0������Ϊmin��·�����ӵ�δ�������·������һ�˽��j 
				}
			}
		}
		final[v]=TRUE;//�˽��v�������·�� 
		
		for(k=0;k<g.nodenum;k++){//�������·������s��p����ֹ������̰���㷨���µ���Զ·��� 
			if(!final[k]&&(min/*v0���ռ���Ľ��v�����·��*/+g.am[v][k].data
			/*�ռ���Ľ��v���ӵ�k�ľ��루����ΪINF��*/<s[k]/*���v0Ŀǰ����k����̾��루����ΪINF*/)){
				s[k]=min+g.am[v][k].data;//�����k����̾������Ϊv0ͨ���ռ���Ľ��v���� 
				p[k]=v;//�������·����k��ǰ������Ϊv 
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
	printf("v0�㵽����֮��ľ��룺");
	for(int i=0;i<NUM;i++){
		printf("%d ",sp[i]);
	}
	printf("\n");
	printf("����ÿ��·�ߵ�ǰ�����㣺");
	for(int i=0;i<NUM;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
/*https://img2018.cnblogs.com/blog/1363376/201811/1363376-20181108111225400-321027694.jpg*/ 
