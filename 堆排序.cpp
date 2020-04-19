#include<stdio.h>//�����󶥶� ������˳��ṹ�洢�� 
void swap(int k[],int a,int b){//�������� 
	int temp;
	temp=k[a];
	k[a]=k[b];
	k[b]=temp;
}
void heapadjust(int k[],int a,int n){//��һ�ã��ӣ�������Ϊ�󶥶�(a�����ĸ�����±�,n��������ĩ����±�) 
	int i;
	int temp=k[a];
	for(i=2*a;i<=n;i=i*2){//k[i]��ʼʱ����ÿ��˫�׽������� 
		if(i<n&&k[i]<k[i+1]){
			i++;//�ҵ����Һ����еĽϴ�ֵ������1�� 
		} 
		if(temp>=k[i]){
			break;
		}//�����ʱ�������Ϊ���ֵ������ȡ��ѭ�� 
		k[a]=k[i];//�ҵ��ϴ�ĺ��ӣ�����������佻��������2��
		a=i;//�����±����i�У��������ѭ��ִ�е����󶥶Ѳ��� 
	}
	k[a]=temp;
}
void heapsort(int k[],int n){
	int i;
	for(i=n/2;i>0;i--){
		heapadjust(k,i,n);//������������ߵķ�Ҷ�ӽ�㿪ʼ���ϵ��� 
	}
	for(i=n;i>1;i--){
		swap(k,1,i);//����һ��Ԫ�������һ��Ԫ�ػ��� 
		heapadjust(k,1,i-1);//���µ���ȥ����ĩ����ʣ�µĽ����ɵ���Ϊ�󶥶ѣ���ʱk[i]������ĩ�����Ϊ���н������Сֵ���������Ｔ�ɣ� 
	}
}

int main(){
	int a[10]={0,1,5,6,9,8,3,2,4,7};
	int n=9;
	heapsort(a,n);
	for(int i=0;i<n+1;i++){
		printf("%d ",a[i]);
	}
}
