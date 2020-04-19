#include<stdio.h>
void shellsort(int a[],int interval,int size){//正向希尔排序 
	int i,j;
	for(i=1+interval;i<size;i++){//每个间隔（interval）一定距离的元素之间进行正向简单插入排序
		if(a[i]<a[i-interval]){
			//如果碰到逆序，就执行在这些规律间隔的元素中的正向简单插入排序（如下） 
			a[0]=a[i];
			for(j=i-interval;j>0&&a[0]<a[j];j=j-interval){
				a[j+interval]=a[j];
			}
			a[j+interval]=a[0];
		}
	}
	a[0]=0;
}
int main(){
	int a[10]={0,1,3,5,4,6,9,7,8,2};
	for(int i=1;i<=3;i++){//分别执行间隔1,2,3个元素的正向希尔排序 
		shellsort(a,i,10);
	}
	for(int k=0;k<10;k++){
		printf("%d ",a[k]);
	}
} 
