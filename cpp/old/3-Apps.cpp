#include <bits/stdc++.h>
using namespace std;

//MISC

template<int n>
bool all_eq(int a[n]){
	for(int i=0; i<n-1; i++){
		if(a[i]!=a[i+1]){
			return 0;
		}
	}
	return 1;
}

pair<double,double> read_pair(string text){
	bool on_b=0;
	double a=0,b=0;
	for(int i=0; i<text.size(); i++){
			if((int)text[i]>=48&&(int)text[i]<=57){
				if(!on_b)
				a=a*10+(int)text[i]-'0';
				else
				b=b*10+(int)text[i]-'0';
			}else{
				on_b=1;
			}
	}
	return pair<double,double>(a,b);
}

//MY APPS

//calculator

double calc_pair(pair<double,double> ab, char op){
	double a=ab.first;
	double b=ab.second;
	switch(op){
		case 'a':
			return a+b;
		case 's':
			return a-b;
		case 'm':
			return a*b;
		case 'd':
			return (float)a/b;
		default:
			return 0;
	}
}

void calculator(){
	string text;
	string command="add";
	while(1){
		cout<<command<<" > ";
		getline(cin,text);
		if(text=="add"||text=="sub"||text=="mult"||text=="div"){
			command=text;
			continue;
		}else if(text=="help"){
			cout<<"type 'add' to add, 'sub' to subtract, 'mult' to multiply, 'div' to divide, and 'exit' to exit. input format: a b."<<endl;
			continue;
		}else if(text=="exit"){
			cout<<"calculator ended."<<endl;
			break;
		}
		cout<<calc_pair(read_pair(text),command[0])<<endl;
	}
}

//counter

int cnt=0;

void counter(){
	string text;
	while(1){
		cout<<"current count: "<<cnt<<endl;
		cout<<"counter > ";
		getline(cin,text);
		if(text=="inc"){
			cnt++;
		}else if(text=="dec"){
			cnt--;
		}else if(text=="help"){
			cout<<"type 'inc' to increase count, 'dec' to decrease count, and 'exit' to exit."<<endl;
			continue;
		}else if(text=="exit"){
			cout<<"counter ended."<<endl;
			break;
		}else{
			cout<<"type 'help' for help."<<endl;
			continue;
		}
	}
}

//tic tac toe

void tictactoe(){
	char text;
	char symbols[3]={' ','X','O'};
	char board[3][3];
	int cnt=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j]=(char)(++cnt+'0');
		}
	}
	string player="1";
	while(1){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				cout<<'|'<<board[i][j]<<'|';
			}
			cout<<endl<<"----------"<<endl;
		}
		cout<<"player"+player+" > ";
		cin>>text;
		bool text_valid=0;
		if(text=='e'){
			return;
		}
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(board[i][j]==text){
					board[i][j]=symbols[(int)(player[0]-'0')];
					text_valid=1;
				}
			}
		}
		for(int i=0; i<3; i++){
			int temp[]={board[i][0],board[i][1],board[i][2]};
			if(all_eq<3>(temp)){
				cout<<"player "+player+" has won the game!"<<endl;
				return;
			}
		}
		int temp[]={board[0][0],board[1][1],board[2][2]};
		if(all_eq<3>(temp)){
			cout<<"player "+player+" has won the game!"<<endl;
			return;
		}
		for(int i=0; i<3; i++){
			int temp[]={board[0][1],board[1][i],board[2][i]};
			if(all_eq<3>(temp)){
				cout<<"player "+player+" has won the game!"<<endl;
				return;
			}
		}
		if(!text_valid){
			cout<<"invalid text."<<endl;
		}
		if(player=="1"){
			player="2";
		}else{
			player='1';
		}
	}
}

//APP LIST

string apps[]={"calculator","counter","tictactoe"};
typedef void(*a)();
a app[]={calculator,counter,tictactoe};
void printapps(){
	cout<<"apps: ";
	for(int i=0; i<sizeof(apps)/sizeof(string); i++){
		cout<<apps[i]<<", ";
	}cout<<"exit"<<endl;
}

//MISC

void read_and_do(string text){
	string *itr=find(begin(apps), end(apps), text);
	if(itr != end(apps)){
		int d=itr-apps;
		app[d]();
		printapps();
	}else{
		printapps();
	}
}

//MAIN

int main(){
	string text;
  while(1){
  	cout<<"Apps > ";
  	getline(cin,text);
		if(text=="exit"){
			cout<<"'YES' to exit."<<endl;
			cout<<"exit > ";
			string EXIT;
			getline(cin,EXIT);
			if(EXIT=="YES"){
				cout<<"Apps ended."<<endl;
				return 0;
			}
		}
		read_and_do(text);
  }
}