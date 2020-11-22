#include<algorithm>
#include<iostream>
using namespace std;
struct stu{
	unsigned int number;
	float grade;
};
bool custom_cmp(stu a,stu b){
	return a.grade>b.grade;
}
int main(){
	stu student[5];
	float grades[]={45.6,87.5,99.9,84.5,7};
	for(int i=0; i<5; i++){
		student[i].number=i+1;
		student[i].grade=grades[i];
	}
	sort(student,student+5,custom_cmp);
	for(int i=0; i<5; i++){
		cout<<student[i].number<<endl;
	}
}
