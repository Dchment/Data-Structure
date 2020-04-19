#include<stdio.h>
#include<string.h>
struct stu{
	char name[10];
	int num;
	int grade;
};
int main(){
	struct stu st[5]; 
	struct stu *s;
	int sort[5];
	s=st;
	for(int i=0;i<5;i++){
		scanf("%s %d %d",(s+i)->name,&(s+i)->num,&(s+i)->grade);
		sort[i]=(s+i)->grade;
		puts((s+i)->name);
		printf("%d %d\n",(s+i)->num,(s+i)->grade);
	}
	for(int k=0;k<5;k++){
		for(int l=k;l<5;l++){
			if(sort[k]<sort[l]){
				int temp;
				temp=sort[k];
				sort[k]=sort[l];
				sort[l]=temp;
			}
		}
	}
	for(int m=0;m<5;m++){
		printf("%d",sort[m]);
	}
}
