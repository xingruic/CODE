#include<bits/stdc++.h>
using namespace std;
int main(){
	struct{
		string name;
		int grade;
		int age;
		char group;
		float score;
	}stu[100], stu2;
	for(int i=0; i<100; i++){
		stu[i].name="student";
		stu[i].grade=5;
		stu[i].age=i;
		stu[i].group=(char)i;
		stu[i].score=100;
	}
	cout<<stu[50].age<<' '<<stu[50].grade<<endl;
}
