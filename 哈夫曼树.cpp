#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int weight;
	int parent,lchild,rchild;
}huffnode,*hufftree;
typedef char**huffcode;

void select(hufftree HT, int end, int *s1, int *s2)//选择所有结点中权值最小的两个 
{
    int min1, min2;
    int i = 1;
    while(HT[i].parent != 0 && i <= end){
        i++;
    }//先找出一个没有双亲的结点 
    min1 = HT[i].weight;
    *s1 = i;  
    i++; 
    while(HT[i].parent != 0 && i <= end){
        i++;
    }//再找出第二个！ 
    if(HT[i].weight < min1){//将两个找出的结点进行权值大小比较，大的下标放s1,小的下标放s2 
        min2 = min1;
        *s2 = *s1;
        min1 = HT[i].weight;
        *s1 = i;
    }else{
        min2 = HT[i].weight;
        *s2 = i;
    }
    for(int j=i+1; j <= end; j++)//然后对还未进行查找的结点执行上面的过程（即更新s1与s2） 
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
	int m=2*n-1,i;//哈夫曼树总共会有2n-1个结点，其总数设为m，其中n为原有的结点 （叶子结点） 
	int s1,s2;
	int j,k;
	hufftree p;
	ht=(hufftree)malloc((m+1)*sizeof(huffnode));
	for(p=ht,i=1;i<=n;i++,p++,w++){//哈夫曼树现有n个叶子结点初始化 
		p->weight=*w;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
	} 
	for(i=n+1;i<=m;i++,p++){//哈夫曼树之后会有的m-n个非叶子结点初始化 
		p->weight=0;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
	}
	for(i=n+1;i<=m;i++){//找出两个权最小的结点，将他们作为新结点的左右孩子，新结点的权为他们的和，将新结点放在数组中已有结点的后面 
		select(ht,i-1,&s1,&s2);//找出两个权最小的结点的执行函数 
		ht[s1].parent=i;
		ht[s2].parent=i;
		ht[i].lchild=s1;
		ht[i].rchild=s2;
		ht[i].weight=ht[s1].weight+ht[s2].weight;
	}
	
	
	hc=(huffcode)malloc(sizeof(char *)*(n+1));//设立n个字符编码头指针存储空间，最后一位表结束 
	char * cd=(char *)malloc(n*sizeof(char));//每个叶子结点的字符编码最多会有n-1位
	cd[n-1]='\0';//编码是字符串，以'\0'结尾 
	for(i=1;i<=n;i++){
		int start=n-1;//编码一般是从相应叶子结点到根结点倒着得出
		for(j=i,k=ht[i].parent;k!=0;j=k,k=ht[k].parent){//因此用从叶子结点回溯式方法进行编码 
			if(ht[k].lchild==j){
				cd[--start]='0';
			}
			else{
				cd[--start]='1';
			}//左0右1 
		}
		hc[i]=(char *)malloc(sizeof(char)*(n-start));//为第i个字符编码分配空间（大小为n-start） 
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
