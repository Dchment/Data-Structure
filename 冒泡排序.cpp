#include<stdio.h>
int main(){
	int a[10]={2,3,6,5,4,7,8,9,1,0};
	int i,j;
	for(i=9;i>=0;i--){//冒泡式正序排列：将最大值送至数列尾部（“冒泡”到顶部） 
		for(j=0;j<i;j++){//要求开始执行次数为数列长度的循环，然后递减至只循环第一位
		//（将最大值送至最后一位后，就要将次最大值送至倒数第二位了，然后重复!） 
			if(a[j]>a[j+1]){
				int temp;
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	for(int k=0;k<10;k++){
		printf("%d ",a[k]);
	}
	
	
	printf("\n"); 
	for(i=9;i>=0;i--){ 
		for(j=0;j<i;j++){
			if(a[j]<a[j+1]){//冒泡式逆序排列则只需改动判定标准这一处即可！
				int temp;
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	for(int k=0;k<10;k++){
		printf("%d ",a[k]);
	}
} 
