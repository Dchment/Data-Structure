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
	        cout<<"������ɣ�"<<endl;
		};
		time(time &t){
			hour=t.hour;
			second=t.second;
			minute=t.minute;
			cout<<"���ƹ�����ɣ�"<<endl;
		};
		void show();
		void input();
		void get();
		void extract();
		~time(){
			cout<<"������ɣ�"<<endl;
		}
	private:
		int hour;
		int minute;
		int second;
};
void time::show(){
	cout<<hour<<":"<<minute<<":"<<second<<endl;
	cout<<"�����ɣ�"<<endl;
}
void time::input(){
	int i,j,k;
	cin>>i;
	cin>>j;
	cin>>k;
	hour=i;
	minute=j;
	second=k;
	cout<<"������ɣ�"<<endl;
}
void time::get(){
	hp=hour;
	mp=minute;
	sp=second;
	cout<<"������ɣ�"<<endl; 
}

class A:public time{
	public:
		A(int d,int h,int m,int s):time(h,m,s){
			day=d; 
		cout<<"�����๹����ɣ�"<<endl;
		}
		void show();
	private:
		int day;
};
void A::show(){
	cout<<day<<":"<<hp<<":"<<mp<<":"<<sp<<endl;
	cout<<"�����������ɣ�"<<endl;
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
