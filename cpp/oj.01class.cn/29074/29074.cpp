#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long a[n+1];
    for(long long i=1; i<=n; i++) cin>>a[i];
    // 中间的兵营编号，天降神兵的个数，天降神兵的兵营编号，你要发的工兵个数，你选的兵营
    long long m,s1,p1,s2,p2;
    cin>>m>>p1>>s1>>s2;
    a[p1]+=s1;
    long long init_l=0,init_r=0;
    // 每个兵营的气势
    long long s[n+1];
    for(long long i=1; i<=n; i++){
        s[i]=a[i]*abs(m-i);
        if(i<m)init_l+=s[i];
        if(i>m)init_r+=s[i];
        // cout<<init_l<<' '<<init_r<<endl;
    }
    // cout<<init_l<<' '<<init_r<<endl;
    long long min_diff=abs(init_l-init_r);
    for(long long i=1; i<=n; i++){
        if(i<m){
            if(abs(init_l+s2*abs(m-i)-init_r)<=min_diff){
                min_diff=abs(init_l+s2*(m-i)-init_r);
                // cout<<abs(m-i)<<endl;
                // cout<<i<<' '<<min_diff<<endl;
                p2=i;
            }
        }else if(abs(init_r+s2*abs(m-i)-init_l)<=min_diff){
            min_diff=abs(init_r+s2*abs(m-i)-init_l);
            // cout<<init_r+s2*abs(m-i)<<endl;
            // cout<<i<<' '<<min_diff<<endl;
            p2=i;
        }
    }
    cout<<p2<<endl;
}
