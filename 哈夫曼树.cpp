#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int weight;
	int parent,lchild,rchild;
}huffnode,*hufftree;
typedef char**huffcode;

void select(hufftree HT, int end, int *s1, int *s2)//ѡ�����н����Ȩֵ��С������ 
{
    int min1, min2;
    int i = 1;
    while(HT[i].parent != 0 && i <= end){
        i++;
    }//���ҳ�һ��û��˫�׵Ľ�� 
    min1 = HT[i].weight;
    *s1 = i;  
    i++; 
    while(HT[i].parent != 0 && i <= end){
        i++;
    }//���ҳ��ڶ����� 
    if(HT[i].weight < min1){//�������ҳ��Ľ�����Ȩֵ��С�Ƚϣ�����±��s1,С���±��s2 
        min2 = min1;
        *s2 = *s1;
        min1 = HT[i].weight;
        *s1 = i;
    }else{
        min2 = HT[i].weight;
        *s2 = i;
    }
    for(int j=i+1; j <= end; j++)//Ȼ��Ի�δ���в��ҵĽ��ִ������Ĺ��̣�������s1��s2�� 
    {
        if(HT[j].parent != 0){
            continue;
        }
        if(HT[j].weight < min1){
            min2 = min1;
            min1 = HT[j].weight;
            *s2 = *s1;
            *s1 = j;
        }
        else if(HT[j].weight >= min1 && HT[j].weight < min2){
            min2 = HT[j].weight;
            *s2 = j;
        }
    }
}
void huffcoding(hufftree &ht,huffcode &hc,int *w,int n){
	int m=2*n-1,i;//���������ܹ�����2n-1����㣬��������Ϊm������nΪԭ�еĽ�� ��Ҷ�ӽ�㣩 
	int s1,s2;
	int j,k;
	hufftree p;
	ht=(hufftree)malloc((m+1)*sizeof(huffnode));
	for(p=ht,i=1;i<=n;i++,p++,w++){//������������n��Ҷ�ӽ���ʼ�� 
		p->weight=*w;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
	} 
	for(i=n+1;i<=m;i++,p++){//��������֮����е�m-n����Ҷ�ӽ���ʼ�� 
		p->weight=0;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
	}
	for(i=n+1;i<=m;i++){//�ҳ�����Ȩ��С�Ľ�㣬��������Ϊ�½������Һ��ӣ��½���ȨΪ���ǵĺͣ����½��������������н��ĺ��� 
		select(ht,i-1,&s1,&s2);//�ҳ�����Ȩ��С�Ľ���ִ�к��� 
		ht[s1].parent=i;
		ht[s2].parent=i;
		ht[i].lchild=s1;
		ht[i].rchild=s2;
		ht[i].weight=ht[s1].weight+ht[s2].weight;
	}
	
	
	hc=(huffcode)malloc(sizeof(char *)*(n+1));//����n���ַ�����ͷָ��洢�ռ䣬���һλ����� 
	char * cd=(char *)malloc(n*sizeof(char));//ÿ��Ҷ�ӽ����ַ�����������n-1λ
	cd[n-1]='\0';//�������ַ�������'\0'��β 
	for(i=1;i<=n;i++){
		int start=n-1;//����һ���Ǵ���ӦҶ�ӽ�㵽����㵹�ŵó�
		for(j=i,k=ht[i].parent;k!=0;j=k,k=ht[k].parent){//����ô�Ҷ�ӽ�����ʽ�������б��� 
			if(ht[k].lchild==j){
				cd[--start]='0';
			}
			else{
				cd[--start]='1';
			}//��0��1 
		}
		hc[i]=(char *)malloc(sizeof(char)*(n-start));//Ϊ��i���ַ��������ռ䣨��СΪn-start�� 
		strcpy(hc[i],&cd[start]);
		puts(&cd[start]); 
	}
	free(cd);
}
int main(){
	hufftree ht;
	huffcode hc;
	int w[5]={7,5,2,4,6};
	huffcoding(ht,hc,w,5);
}
