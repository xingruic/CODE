#include<bits/stdc++.h>
using namespace std;
vector<pair<char,string> > huffmanCodeVec;
struct Node{
    int n;
    char c;
    Node* l;
    Node* r;
    Node(int _n,char _c,Node* _l=NULL,Node* _r=NULL){
        n=_n;
        c=_c;
        l=_l;
        r=_r;
    }
};
struct cmp{
    bool operator()(Node* a,Node* b){
        return a->n>b->n;
    }
};
void printQ(priority_queue<Node*,vector<Node*>,cmp> Q){
    priority_queue<Node*,vector<Node*>,cmp> q=Q;
    while(!q.empty()){
        cout<<q.top()->n<<'\t';
        q.pop();
    }
    cout<<endl;
}
void getcode(Node* node,string str=""){
    if(node->l==NULL&&node->r==NULL){
        huffmanCodeVec.push_back(make_pair(node->c,str));
        cout<<node->c<<' '<<str<<endl;
        return;
    }
    getcode(node->l,str+'0');
    getcode(node->r,str+'1');
    return;
}
string encode(string s){
    for(vector<pair<char,string> >::iterator j=huffmanCodeVec.begin();j!=huffmanCodeVec.end();j++){
        int index;
        while((index=s.find(j->first))!=string::npos){
            s.replace(index,1,j->second);
        }
    }
    return s;
}
int main(){
    freopen("HarryPotter.in","r",stdin);
    freopen("HarryPotter.out","w",stdout);
    string s;
    getline(cin,s);
    int n=s.size();
    int cnt[n];
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(s[j]==s[i]){
                cnt[j]++;
                break;
            }
        }
    }
    priority_queue<Node*,vector<Node*>,cmp> Q;
    for(int i=0; i<n; i++){
        // cout<<cnt[i]<<' ';
        Node* tmp=new Node(cnt[i],s[i]);
        if(cnt[i]>0) Q.push(tmp);
    }
    // cout<<endl;
    // printQ(Q);
    Node* tmp;
    while(Q.size()>1){
        Node* x=Q.top();
        Q.pop();
        tmp=new Node(Q.top()->n+x->n,'\0',x,Q.top());
        Q.pop();
        Q.push(tmp);
    }
    // cout<<tmp->n<<endl;
    getcode(tmp);
    string t=encode(s);
    cout<<t<<endl;
    cout<<s.size()*8<<endl;
    cout<<t.size()<<endl;
}