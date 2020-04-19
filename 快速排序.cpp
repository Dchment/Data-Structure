#include<stdio.h>
#define MAX 10
typedef struct{
	int a[MAX];//需要排序的数组 
	int length; //数组总元素数 
}list;
int partition(list &l,int low,int high){//分割函数（核心） 
	l.a[0]=l.a[low];//下界low开始一般为第一位，上界high开始一般为最后一位 
	int pivot=l.a[0];//数组第一位的值作为枢轴，先保存起来防止排序时丢失 
	while(low<high){
		while(low<high&&l.a[high]>=pivot){//high从尾部向头部前进，遇见比枢轴小的就与low交换，放到前面去 
			high--;
		}
		l.a[low]=l.a[high];
		while(low<high&&l.a[low]<=pivot){//low从头部向尾部前进，遇见比枢轴大的就与high交换，放到后面去 
			low++;
		}
		l.a[high]=l.a[low];
	}//直至low与high相遇 
	l.a[low]=pivot;//将枢轴放入low/high处 
	return low;//此时low/high是枢轴，也是数值高低分界点，比其低的都在左边，比其高的都在右边！ 
}
void quicksort(list &l,int low,int high){
	if(low<high){
	int pivotloc=partition(l,low,high);//将数组分割成高低两部分
	//分别对高低两部分用递归继续进行分割 ，直至有序 
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
