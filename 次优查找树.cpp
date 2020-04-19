#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node{
	int data;
	node *lchild;
	node *rchild;
}*bitree;
void fot(bitree &t){
	if(t!=NULL){
	printf("%d ",t->data);
    fot(t->lchild);
	fot(t->rchild);
	}
}
void secondoptimaltree(bitree &t,int r[],float sw[],int low,int high){
	int i=low;
	int j,k,m;
	float min=65535;
	for(j=low;j<=high;j++){
		float ltotal=0;
		float rtotal=0;
		for(k=low;k<j;k++){
			ltotal+=sw[k];
		}
		for(m=j+1;m<=high;m++){
			rtotal+=sw[m];
		}
		if(abs(rtotal-ltotal)<min){
			min=abs(rtotal-ltotal);
			i=j;
		}
	}
	/*
	float min=abs(sw[high]-sw[low]);
	float dw=sw[high]+sw[low-1];
	for(j=low+1;j<=high;j++){
		if(abs(dw-sw[j]-sw[j-1]<min)){
			i=j;
			min=abs(dw-sw[j]-sw[j-1]);
		}
	}
	*/
	t=(bitree)malloc(sizeof(node));
	t->data=r[i];
	if(i==low)
	t->lchild=NULL;
	else
	secondoptimaltree(t->lchild,r,sw,low,i-1);
	if(i==high)
	t->rchild=NULL;
	else
	secondoptimaltree(t->rchild,r,sw,i+1,high);
}
int main(){
	int r[9]={1,2,3,4,5,6,7,8,9};
	float sw[9]={1,1,2,5,3,4,4,3,5};
	int low=0;
	int high=8;
	bitree t;
	secondoptimaltree(t,r,sw,low,high);
	fot(t);
}
