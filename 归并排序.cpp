#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void merging_r(int *a1,int s1,int *a2,int s2){//���������ֽ��й鲢������
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
	for(int m=0;m<s1+s2;m++){//�������Ľ�������һ�������� 
		a1[m]=temp[m];
	}
}
void mergesort_r(int a[],int n){//�ݹ�ʵ�ֹ鲢���� 
	if(n>1){
	int *p1=a;
	int *p2=a+n/2;
	int listsize1=n/2;
	int listsize2=n-listsize1;
	mergesort_r(p1,listsize1);//һֱ�ݹ鵽����޷��ٷ֣�ֻ��һ��Ԫ�� 
	mergesort_r(p2,listsize2);//һֱ�ݹ鵽�ұ��޷��ٷ֣�ֻ��һ��Ԫ�� 
	merging_r(p1,listsize1,p2,listsize2);//�ݹ���ɺ��ٷֱ���������
    }
} 

void mergesort_i(int a[],int n){//����ʵ�ֹ鲢���� 
	int i,nextl;
	int leftmin,leftmax,rightmin,rightmax;//�ĸ������ֱ�Ϊ����ͷ������β���Ұ��ͷ���Ұ��β�������Ԫ�ط�ΧΪ[����ͷ,�Ұ��β)�� 
	int *temp=(int *)malloc(n*sizeof(int));
	for(i=1;i<n;i=i*2){//iΪ������ÿ�ι鲢���������ָ�������Ԫ�ظ����� 
		for(leftmin=0;leftmin<n-i;leftmin=rightmax){
			rightmin=leftmax=leftmin+i;
			rightmax=leftmax+i;
			if(rightmax>n){
				rightmax=n;//��׼���鳬�磡���Ұ��βΪ��һ���鲢���������ͷ���˴β����򣬵�Ҫ����ã� 
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
			while(leftmin<leftmax){//��ֹ��߱��ұ߳�������������ñȽϣ���Ϊ�����Ѿ�ȫΪ���ֵ���Ĳ���ֱ�ӷ���ԭ�������ߣ�����ұ߱���߳�������Ĳ��ֱ����������ߣ� 
				a[--rightmin]=a[--leftmax];//rightmin��ʱָ������ĩλ�����Դ�ţ� 
			}
			while(next>0){//����������ɲ��ַ���ԭ����
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
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	int b[10]={0,2,5,3,6,9,8,7,4,1};
	mergesort_r(b,10);
	printf("\n");
}
