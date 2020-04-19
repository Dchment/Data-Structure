#include<stdio.h>
int main(){
	int array[10]={2,5,6,8,9,15,16,19,20,31};
	int key;
	int front=0;
	int rear=9;
	scanf("%d",&key);
	while(front<=rear){
		int mid=(rear+front)/2;
		if(array[mid]==key){
			printf("%d %d",mid,key);
			break;
		}
		else if(array[mid]>key){
			rear=mid-1;
		}
		else{
			front=mid+1;
		}		
	}
	
} 
