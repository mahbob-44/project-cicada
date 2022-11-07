#include<bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define lop (m) for(int j=0;j<m;j++)
using namespace std;

class treenode{
public:
	int data;
	treenode*left;
	treenode* right;
	treenode(int val){
		this->data=val;
		this->left=NULL;
		this->right=NULL;
	}
};

void preorder(treenode*root, string& chk){
	if(root==NULL){
		return;
	}
	chk+=to_string(root->data);
	preorder(root->left,chk);
	preorder(root->right,chk);
}

bool isSame(treenode*&head1, treenode*&head2){
	if(head1==NULL&&head2==NULL){
		return true;
	}
	else if(head1==NULL&&head2!=NULL||head1!=NULL&&head2==NULL){
		return false;
	}
	string preorder_traversal_tree1="";
	string preorder_traversal_tree2="";
	preorder(head1,preorder_traversal_tree1);
	preorder(head2,preorder_traversal_tree2);
	if(preorder_traversal_tree1==preorder_traversal_tree2){
		return true;
	}
	else return false;
} 

int main(){	
    int a,b;
    	cin>>a>>b;
    	treenode* root1=new treenode(a);
    	treenode* root2=new treenode(b);
    		queue<treenode*>k;
    		k.push(root1);
    		while(!k.empty()){
    			treenode* present_root1=k.front();
    			k.pop();
    			int x,y;
    			cin>>x>>y;
    			treenode* n1=NULL;
    			treenode* n2=NULL;
    			if(x!=-1) n1=new treenode(x);
    			if(y!=-1) n2=new treenode(y);
    			present_root1->left=n1;
    			present_root1->right=n2;
    			if(n1!=NULL) k.push(n1);
    			if(n2!=NULL) k.push(n2);
    		}
    		queue<treenode*>l;
    		l.push(root2);
    		while(!l.empty()){
    			treenode* present_root2=l.front();
    			l.pop();
    			int x,y;
    			cin>>x>>y;
    			treenode* n3=NULL;
    			treenode* n4=NULL;
    			if(x!=-1) n3=new treenode(x);
    			if(y!=-1) n4=new treenode(y);
    			present_root2->left=n3;
    			present_root2->right=n4;
    			if(n3!=NULL) l.push(n3);
    			if(n4!=NULL) l.push(n4);
    	    }
	bool is=isSame(root1,root2);
	if(is==true){
		cout<<"Trees are same"<<endl;
	} 
	else cout<<"Trees are not same"<<endl;
}