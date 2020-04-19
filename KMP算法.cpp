#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char* String; 
void getnext(String t,int *next){
	int i,j;
	j=0;//前缀，固定的 
	i=1;//后缀，相对的 
	next[1]=0;//开头就失配的情况 
	while(i<t[0]){//t[0]位为子串长度 
	if(j=0/*初始时前缀*/||t[i]==t[j]){//前缀与后缀相同，就可以向前进，因为可以用现在后缀代替现在前缀作为重新进行比较的位置 
		i++;
		j++;
		next[i]=j;
		/*对上面一句优化,防止之后重复的失配元素出现影响效率：
		if(t[i]!=t[j]){
			next[i]=j;
		}
		else{
			next[i]=next[j];
		}
		*/
	}
	else{//前缀与后缀不相同，就回溯至失配地点，将失配地点的next值赋予后缀，因为后缀已不可替代前缀作为重新进行比较的位置，要使用上一次匹配成功的位置，也就是失配地点的next值 
		j=next[j];
	}
}
}
//返回子串t在主串s第pos个字符之后的位置 
int index_kmp(String s,String t,int pos){
	int i=pos;//i为后缀，初始即为pos位置 
	int j=0;//j为前缀，初始指向主串开头 
	int next[255];//next数组，用于标志对应子串各位失配时应用子串中哪一位重新与主串开始比较（核心） 
	getnext(t,next);//获取主串对应的next数组 
	while(i<=s[0]&&j<=t[0]){
		if(j==0||s[i]==t[i]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>t[0]){//匹配成功(j已移到子串最后一个元素之后） 
		return i-t[0];
	}
	else{
		return 0;
	}
}
int main(){
	int t[10]={9,1,2,3,5,6,9,8,7,4};
}
