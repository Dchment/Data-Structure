#include<stdio.h>
void selectsort(int *array,int n){
	int i,j,min;
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(array[j]<array[min]){
				min=j;
			}
		}
		if(min!=i){
			int temp;
			temp=array[min];
			array[min]=array[i];
			array[i]=temp;
		}
	}
} 
int main(){
	int a[10]={0,2,5,3,6,9,8,7,4,1};
	selectsort(a,10);
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
}
