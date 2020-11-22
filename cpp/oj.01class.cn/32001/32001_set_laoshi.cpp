#include <bits/stdc++.h>
using namespace std;

set<int> s;
int n,k,prime[105],cnt=0;
int main(){
    cin>>k>>n;
    for(int i=1;i<=k;i++) {cin>>prime[i];s.insert(prime[i]);}
    for(int i=1;i<=k;i++){
        set<int>::iterator itr=s.begin();
        while(1) {
            int tm=(*itr)*prime[i];
//                cout<<tm<<" ";
                if(tm<0) {cout<<"000000000"<<endl;cout<<tm<<endl;break;}
            if(s.size()>n) {
//                    cout<<"nnnnnnnnnnnnnnnnnn"<<endl;
                s.erase(--s.end());
                if(tm>(*--s.end()))
                    break;
            }
            s.insert(tm);
            ++itr;
            cnt++;
        }
//    cout<<cnt<<endl;
    }
    cout<<*(--s.end());
}

