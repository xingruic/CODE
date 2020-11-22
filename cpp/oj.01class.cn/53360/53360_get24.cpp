#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int calc(stack<int> a, stack<char> op){
	int ans=0;
	while(a.size()>0){
		int x=a.top();
		cout<<"x = "<<x<<endl;
		char y=' ';
		if(!op.empty()){
			y=op.top();
			cout<<"y = '"<<y<<"'"<<endl<<endl;
		}
		int temp;
		a.pop();
		op.pop();
		switch(y){
			case '*':
				temp=x*a.top();
				a.pop();
				a.push(temp);
				break;
			case '+':
				ans+=x;
				break;
			case '-':
				ans-=x;
				break;
			default:
				ans+=x;
				break;
		}
	}
	return ans;
}
void get24(int num,stack<int> a,stack<char> op,int i=0){
	if(i==num-1&&calc(a,op)==24){
		cnt++;
		stack<char> temp=op;
		for(int i=0; i<temp.size(); i++){
			cout<<temp.top()<<' ';
			temp.pop();
		}cout<<endl<<endl;
		return;
	}
	char ops[3]={'*','+','-'};
	for(int i=0; i<3; i++){
		op.push(ops[i]);
		get24(num,a,op,i+1);
		op.pop();
	}
	return;
}
int main(){
	int d;
	cin>>d;
	stack<int> a;
	stack<char> op;
	for(int i=0; i<d; i++){
		int temp;
		cin>>temp;
		a.push(temp);
	}
	get24(d,a,op);
	cout<<cnt<<endl;
}
