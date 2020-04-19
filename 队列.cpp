#include<stdio.h>
#include<stdlib.h>
#define QNUM 10
typedef struct queue{//循环队列 
	int *body;
	int head;
	int tail;
	int num; 
};
void initqueue(queue &q){
	q.body=(int *)malloc(sizeof(int)*QNUM);
	q.head=0;
	q.tail=0;
	q.num=0;
}
void insertelem(queue &q,int a){
	if((q.tail+1)%QNUM==q.head)
	exit(0);
	q.body[q.tail]=a;
	q.tail=(q.tail+1)%QNUM;
	if(q.num<QNUM)
	q.num++;
} 
void deleteelem(queue &q,int *a){
	if(q.tail==q.head)
	exit(0);
	*a=q.body[q.head];
	q.head=(q.head+1)%QNUM;
	if(q.num>0)
	q.num--;
}
void showqueue(queue &q){
	for(int i=q.head;i!=q.tail;i=(i+1)%QNUM){
		printf("%d ",q.body[i]);
	}
	printf("\n");
	printf("当前队头：%d\n",q.body[q.head]);
	printf("当前队尾：%d\n",q.body[q.tail-1]);
	printf("当前队列元素数：%d\n",q.num); 
}

int main(){
	queue q;
	initqueue(q);
	for(int i=1;i<10;i++){
		insertelem(q,i);
	} 
	int a;
	deleteelem(q,&a);
	showqueue(q);
} 
