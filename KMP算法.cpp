#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char* String; 
void getnext(String t,int *next){
	int i,j;
	j=0;//ǰ׺���̶��� 
	i=1;//��׺����Ե� 
	next[1]=0;//��ͷ��ʧ������ 
	while(i<t[0]){//t[0]λΪ�Ӵ����� 
	if(j=0/*��ʼʱǰ׺*/||t[i]==t[j]){//ǰ׺���׺��ͬ���Ϳ�����ǰ������Ϊ���������ں�׺��������ǰ׺��Ϊ���½��бȽϵ�λ�� 
		i++;
		j++;
		next[i]=j;
		/*������һ���Ż�,��ֹ֮���ظ���ʧ��Ԫ�س���Ӱ��Ч�ʣ�
		if(t[i]!=t[j]){
			next[i]=j;
		}
		else{
			next[i]=next[j];
		}
		*/
	}
	else{//ǰ׺���׺����ͬ���ͻ�����ʧ��ص㣬��ʧ��ص��nextֵ�����׺����Ϊ��׺�Ѳ������ǰ׺��Ϊ���½��бȽϵ�λ�ã�Ҫʹ����һ��ƥ��ɹ���λ�ã�Ҳ����ʧ��ص��nextֵ 
		j=next[j];
	}
}
}
//�����Ӵ�t������s��pos���ַ�֮���λ�� 
int index_kmp(String s,String t,int pos){
	int i=pos;//iΪ��׺����ʼ��Ϊposλ�� 
	int j=0;//jΪǰ׺����ʼָ��������ͷ 
	int next[255];//next���飬���ڱ�־��Ӧ�Ӵ���λʧ��ʱӦ���Ӵ�����һλ������������ʼ�Ƚϣ����ģ� 
	getnext(t,next);//��ȡ������Ӧ��next���� 
	while(i<=s[0]&&j<=t[0]){
		if(j==0||s[i]==t[i]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>t[0]){//ƥ��ɹ�(j���Ƶ��Ӵ����һ��Ԫ��֮�� 
		return i-t[0];
	}
	else{
		return 0;
	}
}
int main(){
	int t[10]={9,1,2,3,5,6,9,8,7,4};
}
