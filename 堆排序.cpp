#include<stdio.h>//构建大顶堆 （树用顺序结构存储） 
void swap(int k[],int a,int b){//交换函数 
	int temp;
	temp=k[a];
	k[a]=k[b];
	k[b]=temp;
}
void heapadjust(int k[],int a,int n){//将一棵（子）树调整为大顶堆(a：树的根结点下标,n：树的最末结点下标) 
	int i;
	int temp=k[a];
	for(i=2*a;i<=n;i=i*2){//k[i]开始时代表每个双亲结点的左孩子 
		if(i<n&&k[i]<k[i+1]){
			i++;//找到左右孩子中的较大值（核心1） 
		} 
		if(temp>=k[i]){
			break;
		}//如果此时根结点已为最大值，可以取消循环 
		k[a]=k[i];//找到较大的孩子，将根结点与其交换（核心2）
		a=i;//将其下标放入i中，方便继续循环执行调整大顶堆操作 
	}
	k[a]=temp;
}
void heapsort(int k[],int n){
	int i;
	for(i=n/2;i>0;i--){
		heapadjust(k,i,n);//从整棵树最左边的非叶子结点开始往上调整 
	}
	for(i=n;i>1;i--){
		swap(k,1,i);//将第一个元素与最后一个元素互换 
		heapadjust(k,1,i-1);//重新调整去掉最末结点后剩下的结点组成的树为大顶堆（此时k[i]，即最末结点已为所有结点中最小值，放在那里即可） 
	}
}

int main(){
	int a[10]={0,1,5,6,9,8,3,2,4,7};
	int n=9;
	heapsort(a,n);
	for(int i=0;i<n+1;i++){
		printf("%d ",a[i]);
	}
}
