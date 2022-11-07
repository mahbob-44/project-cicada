#include<bits/stdc++.h>
#define lld long long int
#define loop(n) for(int i=0;i<n;i++)
#define lop(m) for(int j=0;j<m;j++)
#define en "\n"
using namespace std;
class treenode{
public:
	int data;
	treenode*left;
	treenode*right;
	treenode(int val){
		this->data=val;
		this->left=NULL;
		this->right=NULL;
	}
};

void inorder(treenode*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(treenode*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(treenode*root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void levelorder(treenode*root){
	if(root==NULL){
		return;
	}
	queue<treenode*>k;
	k.push(root);
	while(!k.empty()){
		treenode* present_root=k.front();
		cout<<present_root->data<<" ";
		k.pop();
		if(present_root->left!=NULL) k.push(present_root->left);
		if(present_root->right!=NULL) k.push(present_root->right);
	}
}

int main(){
	int n;
	cin>>n;
	treenode*root=new treenode(n);
	queue<treenode*>k;
	k.push(root);
	while(!k.empty()){
		treenode*present_root=k.front();
		k.pop();

		int x,y;
		cin>>x>>y;

		treenode* n1=NULL;
		treenode* n2=NULL;
		if(x!=-1) n1=new treenode(x);
		if(y!=-1) n2=new treenode(y);

		present_root->left=n1;
		present_root->right=n2;

		if(n1!=NULL) k.push(n1);
		if(n2!=NULL) k.push(n2);
	}
    cout<<"Inorder traversal: ";
	inorder(root);cout<<endl;
	cout<<"Preorder traversal: ";
	preorder(root);cout<<endl;
	cout<<"Postorder traversal: ";
	postorder(root);cout<<endl;
	cout<<"Levelorder traversal: ";
	levelorder(root);cout<<endl;
}
/*
Sample input:
3
9 20 
-1 -1 15 7
-1 -1 -1 -1
*/

/* 
Sambple output:
Inorder traversal: 9 3 15 20 7 
Preorder traversal: 3 9 20 15 7 
Postorder traversal: 9 15 7 20 3 
Levelorder traversal: 3 9 20 15 7 
*/