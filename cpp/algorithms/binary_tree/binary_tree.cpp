#include<bits/stdc++.h>
using namespace std;
typedef struct Node {
	int data;
	Node *lchild;
	Node *rchild;
}Node,*root;
void preorder(root Root) {
	if(Root != NULL) {
		//访问节点信息
		cout<<Root->data<<endl;
		//访问左子树
		preorder(Root->lchild);
		//访问右子树 
		preorder(Root->rchild);
	}
}
void inorder(root Root) {
	if(Root != NULL) {
		//访问左子树
		preorder(Root->lchild);
		//访问节点信息
		cout<<Root->data<<endl;
		//访问右子树 
		preorder(Root->rchild);
	}
}
void postorder(root Root) {
	if(Root != NULL) {
		//访问左子树
		preorder(Root->lchild);
		//访问右子树 
		preorder(Root->rchild);
		//访问节点信息
		cout<<Root->data<<endl;
	}
}
int main(){
	root gen;
	gen=(root)malloc(sizeof(Node));
	gen->data=2;
	gen->lchild=(root)malloc(sizeof(Node));
	gen->lchild->data=7;
	gen->rchild=(root)malloc(sizeof(Node));
	gen->rchild->data=5;
	gen->lchild->lchild=(root)malloc(sizeof(Node));
	gen->lchild->lchild->data=11;
	gen->lchild->rchild=(root)malloc(sizeof(Node));
	gen->lchild->rchild->data=198;
	preorder(gen);
	cout<<endl;
	inorder(gen);
	cout<<endl;
	postorder(gen);
}