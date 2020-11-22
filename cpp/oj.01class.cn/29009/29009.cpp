#include<iostream>
using namespace std;
struct student{
  int LA, M, G, sum, num;
};
int main(){
  int students;
  cin>>students;
  student stu[students];
  for(int i=0; i<students; i++){
    cin>>stu[i].LA>>stu[i].M>>stu[i].G;
    stu[i].sum=stu[i].LA+stu[i].M+stu[i].G;
    cout<<stu[i].sum<<' ';
    stu[i].num=i+1;
    cout<<stu[i].num<<endl;
  }
  for(int i=0; i<students; i++){
    for(int j=0; j<students-1; j++){
      if(stu[j].sum<stu[j+1].sum){
        swap(stu[j], stu[j+1]);
        cout<<stu[j].sum<<"<>"<<stu[j+1].sum<<endl;
      }else if(stu[j].LA<stu[j+1].LA){
        swap(stu[j], stu[j+1]);
        cout<<stu[j].sum<<"<>"<<stu[j+1].sum<<endl;
      }else if(stu[j].num>stu[j+1].num){
        swap(stu[j], stu[j+1]);
        cout<<stu[j].sum<<"<>"<<stu[j+1].sum<<endl;
      }
    }
  }
  for(int i=0; i<5; i++){
    cout<<stu[i].num<<' '<<stu[i].sum<<endl;
  }
}
