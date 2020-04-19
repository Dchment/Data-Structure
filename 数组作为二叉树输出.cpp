#include<stdio.h>
#include<math.h> 
int main(){
	int a[100];
	for(int i=0;i<100;i++){
		a[i]=i;
	}
	int layer=1;
	int count=0;
	int layernum;
	while(count<100){
		layernum=(int)pow(2,layer-1);
		for(int j=count;j<count+layernum;j++){
			printf("%d ",a[j]);
			if(j>=99)
			break;
		}
		count=count+layernum;
		layer++;
		printf("\n");
	}
} 
