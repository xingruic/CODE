#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	node *l;
	node *r;
};
node* newnode(int value){
    node *Node=new node;
    Node->v=value;
    Node->l=NULL;
    Node->r=NULL;
    return Node;
}
void preorder(node *root){
    if(root==NULL) return;
    cout<<root->v<<endl;
    preorder(root->l);
    preorder(root->r);
}
int main(){
	node *root=newnode(2);
    root->l=newnode(4);
    root->r=newnode(5);
    root->l->l=newnode(1);
    root->l->r=newnode(1);
    preorder(root);
}