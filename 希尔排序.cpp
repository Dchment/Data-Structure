#include<stdio.h>
void shellsort(int a[],int interval,int size){//����ϣ������ 
	int i,j;
	for(i=1+interval;i<size;i++){//ÿ�������interval��һ�������Ԫ��֮���������򵥲�������
		if(a[i]<a[i-interval]){
			//����������򣬾�ִ������Щ���ɼ����Ԫ���е�����򵥲����������£� 
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
	for(int i=1;i<=3;i++){//�ֱ�ִ�м��1,2,3��Ԫ�ص�����ϣ������ 
		shellsort(a,i,10);
	}
	for(int k=0;k<10;k++){
		printf("%d ",a[k]);
	}
} 
