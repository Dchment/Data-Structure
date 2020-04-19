#include<stdio.h>
#include<stdlib.h>
#define HASHSIZE 10
#define NKEY 65535
typedef struct{
	int *elem;//�������Ԫ��
	int count;//��ǰԪ�ظ��� 
}hashtable;

int inithash(hashtable *h){
	h->count=HASHSIZE;
	h->elem=(int *)malloc(HASHSIZE*sizeof(int));
	if(!h->elem){
		return -1; 
	}
	for(int i=0;i<HASHSIZE;i++){
		h->elem[i]=NKEY;
	}
	return 0;
} 

//���������������ϣ���� 
int hash(int key){
	return key%HASHSIZE;
}

void inserthash(hashtable *h,int key){
	int addr;
	addr=hash(key);
	while(h->elem[addr]!=NKEY){//��ͻ����ʱ 
		addr=(addr+1)%HASHSIZE;//ʹ������̽����ɢ�� 
	}
	h->elem[addr]=key;
} 

int searchhash(hashtable *h,int key,int *addr){
	*addr=hash(key);
	while(hash(*addr)!=key){
		*addr=(*addr+1)%HASHSIZE;
		if(h->elem[*addr]==NKEY||*addr==hash(key)){
			return -1;
		}
	}
	return 0;
}

int main(){
	hashtable h;
	inithash(&h);
	inserthash(&h,0);
	inserthash(&h,1);
	inserthash(&h,2);
	inserthash(&h,3);
	inserthash(&h,11);
	int addr;
	searchhash(&h,11,&addr);
	printf("%d",addr);
}
