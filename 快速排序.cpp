#include<stdio.h>
#define MAX 10
typedef struct{
	int a[MAX];//��Ҫ��������� 
	int length; //������Ԫ���� 
}list;
int partition(list &l,int low,int high){//�ָ�������ģ� 
	l.a[0]=l.a[low];//�½�low��ʼһ��Ϊ��һλ���Ͻ�high��ʼһ��Ϊ���һλ 
	int pivot=l.a[0];//�����һλ��ֵ��Ϊ���ᣬ�ȱ���������ֹ����ʱ��ʧ 
	while(low<high){
		while(low<high&&l.a[high]>=pivot){//high��β����ͷ��ǰ��������������С�ľ���low�������ŵ�ǰ��ȥ 
			high--;
		}
		l.a[low]=l.a[high];
		while(low<high&&l.a[low]<=pivot){//low��ͷ����β��ǰ���������������ľ���high�������ŵ�����ȥ 
			low++;
		}
		l.a[high]=l.a[low];
	}//ֱ��low��high���� 
	l.a[low]=pivot;//���������low/high�� 
	return low;//��ʱlow/high�����ᣬҲ����ֵ�ߵͷֽ�㣬����͵Ķ�����ߣ�����ߵĶ����ұߣ� 
}
void quicksort(list &l,int low,int high){
	if(low<high){
	int pivotloc=partition(l,low,high);//������ָ�ɸߵ�������
	//�ֱ�Ըߵ��������õݹ�������зָ� ��ֱ������ 
	quicksort(l,low,pivotloc-1);
	quicksort(l,pivotloc+1,high);
    }
}
int main(){
	list l={{0,6,2,3,1,4,7,9,8,5},9};
	int low=0;
	int high=l.length;
	quicksort(l,low,high);
	for(int i=0;i<MAX;i++){
		printf("%d ",l.a[i]);
	}
	printf("\n");
}
