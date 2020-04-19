#include<iostream>
using namespace std;

class time{
	public:
		int hp,mp,sp;
		time(int h,int m,int s){
			hour=h;
	        minute=m;
	        second=s;
	        hp=hour;
	        mp=minute;
	        sp=second;
	        cout<<"构造完成！"<<endl;
		};
		time(time &t){
			hour=t.hour;
			second=t.second;
			minute=t.minute;
			cout<<"复制构造完成！"<<endl;
		};
		void show();
		void input();
		void get();
		void extract();
		~time(){
			cout<<"析构完成！"<<endl;
		}
	private:
		int hour;
		int minute;
		int second;
};
void time::show(){
	cout<<hour<<":"<<minute<<":"<<second<<endl;
	cout<<"输出完成！"<<endl;
}
void time::input(){
	int i,j,k;
	cin>>i;
	cin>>j;
	cin>>k;
	hour=i;
	minute=j;
	second=k;
	cout<<"输入完成！"<<endl;
}
void time::get(){
	hp=hour;
	mp=minute;
	sp=second;
	cout<<"接收完成！"<<endl; 
}

class A:public time{
	public:
		A(int d,int h,int m,int s):time(h,m,s){
			day=d; 
		cout<<"派生类构造完成！"<<endl;
		}
		void show();
	private:
		int day;
};
void A::show(){
	cout<<day<<":"<<hp<<":"<<mp<<":"<<sp<<endl;
	cout<<"派生类输出完成！"<<endl;
}
int main()
{
	time m(0,0,0);
	m.show();
	time s=m;
	s.show();
	A d(1,0,0,0);
	d.show();
	return 0;
}
