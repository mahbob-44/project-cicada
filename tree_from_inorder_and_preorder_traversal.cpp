#include <bits/stdc++.h>
using namespace std;

class treenode{
public:
    int data;
    treenode* leftchild;
    treenode* rightchild;
    treenode(int val){
    	data=val;
    	leftchild=NULL;
    	rightchild=NULL;
    }
};

void printtree(treenode* root, int level );

void inorder(treenode*root, string& chk);

void preorder(treenode*root, string& chk);

void postorder(treenode*root, string& chk);

void levelorder(treenode* root, string& chk);

void  printspace(int level);

treenode* buildtreeprein(int inor[],int preor[], int start,int en); 

void printtree(treenode* root, int level ){
	if(root==NULL){
		return;
	}
	if(root->leftchild==NULL&&root->rightchild==NULL){
		cout<<root->data<<endl;
		return;
	}
	else{ //case: 2
	cout<<endl;
	printspace(level);
	cout<<"Root: "<<root->data<<endl;
    }
    if(root->leftchild!=NULL){
    printspace(level);
	cout<<"Left: ";
	printtree(root->leftchild,level+1);
    }
    if(root->rightchild!=NULL){
    printspace(level);
	cout<<"Right: ";
	printtree(root->rightchild,level+1);
     }
}

void inorder(treenode*root, string& chk){
	if(root==NULL){
		return;
	}
	inorder(root->leftchild,chk);
	chk+=to_string(root->data);
	inorder(root->rightchild,chk);
}

void preorder(treenode*root, string& chk){
	if(root==NULL){
		return;
	}
	chk+=to_string(root->data);
	preorder(root->leftchild,chk);
	preorder(root->rightchild,chk);
}

void postorder(treenode*root, string& chk){
	if(root==NULL){
		return;
	}
	postorder(root->leftchild,chk);
	postorder(root->rightchild,chk);
	chk+=to_string(root->data);
}

void levelorder(treenode* root, string& chk){
      if(root==NULL){
      	return;
      }
      queue<treenode*> q;
      q.push(root);
      q.push(NULL);

      while(!q.empty()){
      	treenode* chknode=q.front();
      	q.pop();
      	if(chknode!=NULL){
      		cout<<chknode->data<<" ";
      		if(chknode->leftchild!=NULL){
      			q.push(chknode->leftchild);
      		}
      		if(chknode->rightchild!=NULL){
      			q.push(chknode->rightchild);
      		}
      	}
      	else {
      		if(!q.empty()){
      			q.push(NULL);
      		}
      	}
      }
}

void  printspace(int level){
	for(int i=0;i<level;i++){
          cout<<"   ";
	}
}

treenode* buildtreeprein(int inor[],int preor[], int start,int en){
    int id=0;
    int current= preor[id];
    int pos=searc
}

int main() {
	int n;
    cin>>n;
    int inor[n], preor[n];
    for(int i=0;i<n;i++){
        cin>>inor[i];
    }
    for(int i=0;i<n;i++){
        cin>>preor[i];
    }
    treenode* root=buildtreeprein(inor, preor, 0, n-1);
}
/*
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1 
7 -1 -1
8 -1 -1
*/
/*
root: 0
left: 1
     root: 1
     left: 3
     right: 4
right:2
    root: 2
    left: 5
         root: 5
         left: 7
         right: 8
    right: 6

*/