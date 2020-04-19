#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int *elemarray;
	int elemnum;
	int size;
}sqlist;
void initlist(sqlist &s){
	s.size=10;
	s.elemarray=(int *)malloc(sizeof(int)*s.size);
	s.elemnum=0;
}
void insertlist(sqlist &s,int a){
	s.elemarray[s.elemnum]=a;
	s.elemnum++;
}
void showlist(sqlist &s){
	for(int i=0;i<s.elemnum;i++){
		printf("%d ",s.elemarray[i]);
	}
	printf("\n");
}
void deletelist(sqlist &s,int a){
	int i;
	printf("%d\n",s.elemarray[a]);
	for(i=a;i<s.elemnum-1;i++){
		s.elemarray[i]=s.elemarray[i+1];
	}
	s.elemarray[i]=NULL;
	s.elemnum--;
} 
int main(){
	sqlist s;
	initlist(s);
	insertlist(s,1);
	insertlist(s,2);
	insertlist(s,3);
	showlist(s);
	deletelist(s,1);
	showlist(s);
}
