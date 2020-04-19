#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void merging_r(int *a1,int s1,int *a2,int s2){//将两个部分进行归并后排序
	int i=0,j=0,k=0;
	int temp[MAX];
	while(i<s1&&j<s2){
		if(a1[i]<a2[j]){
			temp[k++]=a1[i++];
		}
		else{
			temp[k++]=a2[j++];
		}
	}
	while(i<s1){
		temp[k++]=a1[i++];
	}
	while(j<s2){
		temp[k++]=a2[j++];
	}
	for(int m=0;m<s1+s2;m++){//将排序后的结果放入第一个数组中 
		a1[m]=temp[m];
	}
}
void mergesort_r(int a[],int n){//递归实现归并排序 
	if(n>1){
	int *p1=a;
	int *p2=a+n/2;
	int listsize1=n/2;
	int listsize2=n-listsize1;
	mergesort_r(p1,listsize1);
	mergesort_r(p2,listsize2);
	merging_r(p1,listsize1,p2,listsize2);
    }
} 

void mergesort_i(int a[],int n){//迭代实现归并排序 
	int i,next,leftmin,leftmax,rightmin,rightmax;
	int *temp=(int *)malloc(n*sizeof(int));
	for(i=1;i<n;i=i*2){//i为步长（每次归并的两个部分所含的元素个数） 
		for(leftmin=0;leftmin<n-i;leftmin=rightmax){
			rightmin=leftmax=leftmin+i;
			rightmax=leftmax+i;
			if(rightmax>n){
				rightmax=n;//不准数组超界！ 
			} 
			next=0;
			while(leftmin<leftmax&&rightmin<rightmax){
				if(a[leftmin]<a[rightmin]){
					temp[next++]=a[leftmin++];
				}
				else{
					temp[next++]=a[rightmin++];
				}
			}
			while(leftmin<leftmax){//防止左边比右边长，将多出但不用比较（因为他们已经全为最大值）的部分直接放在原数组最后边（如果右边比左边长，多出的部分本来就在最后边） 
				a[--rightmin]=a[--leftmax];//rightmin此时指着数组末位，可以存放！ 
			}
			while(next>0){//将已排序完成部分放入原数组
				a[--rightmin]=temp[--next];
			}
		}
	}
	for(int j=0;j<n;j++){
		printf("%d ",a[j]);
	}
	printf("\n");
}
int main(){
	int a[10]={0,2,5,3,6,9,8,7,4,1};
	mergesort_i(a,10);
	mergesort_r(a,10);
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
