#include<bits/stdc++.h>
using namespace std;
stack<int>a1,a2;
int max_=0,m1=0;
bool isSameStack(){
    if(a1.size()!=a2.size()){
        a1=stack<int>();
        a2=stack<int>();
        return 0;
    }
    while(!a1.empty()){
        if(a1.top()!=a2.top()){
            a1=stack<int>();
            a2=stack<int>();
            return 0;
        }
        a1.pop();
        a2.pop();
    }
    a1=stack<int>();
    a2=stack<int>();
    return 1;
}
void inorder(int v[], int idxl[], int idxr[], int i=1){
    if(idxl[i]!=-1) inorder(v,idxl,idxr,idxl[i]);
    a1.push(v[i]);
    // cout<<v[i]<<' ';
    m1++;
    if(idxr[i]!=-1) inorder(v,idxl,idxr,idxr[i]);
}
void rinorder(int v[], int idxl[], int idxr[], int i=1){
    if(idxr[i]!=-1) rinorder(v,idxl,idxr,idxr[i]);
    a2.push(v[i]);
    // cout<<v[i]<<' ';
    if(idxl[i]!=-1) rinorder(v,idxl,idxr,idxl[i]);
}
int main(){
    int n;
    cin>>n;
    int v[n+1];
    for(int i=1; i<=n; i++) cin>>v[i];
    int idxl[n+1],idxr[n+1];
    for(int i=1; i<=n; i++){
        cin>>idxl[i]>>idxr[i];
    }
    // inorder(v,idxl,idxr);
    // cout<<endl;
    // rinorder(v,idxl,idxr);
    // cout<<endl;
    for(int i=1; i<=n; i++){
        inorder(v,idxl,idxr,i);
        // cout<<endl;
        rinorder(v,idxl,idxr,i);
        // cout<<endl;
        if(isSameStack())
        max_=max(max_,m1);
        // cout<<"a1 empty "<<a1.empty()<<endl;
        // cout<<"a2 empty "<<a2.empty()<<endl;
        // cout<<m1<<endl<<endl<<endl;
        m1=0;
    }
    cout<<max_<<endl;
}