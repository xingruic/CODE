#include<bits/stdc++.h>
using namespace std;
void pause(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string dummy;
    cout << "Press any key to continue . . .";
    getline(cin, dummy);
}
string value(int n){
    string ans="";
    if(n<0){
        return value(abs(n));
    }
    if(n==0) return "0";
    while(n>0){
        ans=(char)(n%10+'0')+ans;
        n/=10;
    }
    return ans;
}
string make_eq(int a[],int n){
    string ans="";
    if(!n) return "";
    if(n==1) return value(a[0]);
    if(a[0]<0) ans+='-';
    ans+=value(a[0])+"x^"+value(n-1);
    for(int i=1; i<n; i++){
        if(a[i]==0) continue;
        else if(i==n-1){
          if(a[i]>0) ans+='+';
          else ans+='-';
          ans+=value(a[i]);
        }else if(i==n-2){
          if(a[i]>0) ans+='+';
          else ans+='-';
          if(a[i]!=1&&a[i]!=-1)
          ans+=value(a[i]);
          ans+='x';
        }else{
          if(a[i]>0) ans+='+';
          else ans+='-';
          if(a[i]!=1&&a[i]!=-1)
          ans+=value(a[i]);
          ans+="x^"+value(n-1-i);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0; i<=n; i++){
        cin>>a[i];
    }
    cout<<make_eq(a,n+1)<<endl;
    pause();
}
