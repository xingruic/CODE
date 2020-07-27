#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,n;
  cin>>k>>n;
  int a[k];
  set<int> hum;
  for(int i=0; i<k; i++){
    cin>>a[i];
    hum.insert(a[i]);
  }
  if(n<=k){
    cout<<a[n-1]<<endl;
    return 0;
  }
  sort(a,a+k);
//  for(int i=0; i<2; i++)
  for(int i=0; i<k; i++){
//int i=0;
    int hp=a[i];
    for(set<int>::iterator itr=hum.begin(); itr!=hum.end(); itr++){
//    	if(*itr*hp==27)cout<<endl<<27<<endl<<endl;
      if(*itr*hp<=0){
        break;
      }
      if(hum.size()==n){
        if(*itr*hp<*--hum.end()){
          hum.insert(*itr*hp);
//        	cout<<*itr*hp<<" is added;\n"<<*--hum.end()<<" is erased\n\n";
			if(hum.size()>n){
//				if(*--hum.end()==27){
//	        		cout<<"<------------------------------>"<<endl;
//	        		for(set<int>::iterator itr=hum.begin(); itr!=hum.end(); itr++){
//					  	cout<<*itr<<' ';
//					}cout<<endl;
//	        		cout<<"<------------------------------>"<<endl;
//				}
				hum.erase(--hum.end());
			}
        }
      }else{
      	hum.insert(*itr*hp);
//      	cout<<*itr*hp<<" was added;\n\n";
      }
    }
  }
//  for(set<int>::iterator itr=hum.begin(); itr!=hum.end(); itr++){
//  	cout<<*itr<<' ';
//  }cout<<endl;
  cout<<*--hum.end()<<endl;
  return 0;
}
