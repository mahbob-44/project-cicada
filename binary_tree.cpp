#include<bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
using namespace std;
class treenode{
public:
	int data;
	treenode* left;
	treenode* right;
	treenode(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};
void printspace(int level){
	loop(level){
		cout<<"   ";
	}
}
void print(treenode*root, int level){
	if(root==NULL){
		return;
	}
	if(root->left==NULL&&root->right==NULL){
	cout<<root->data<<endl;
    }
    else {	
	    cout<<endl;
    	printspace(level);
    	cout<<"Root: "<<root->data<<endl;
    }
    if(root->left!=NULL){
    printspace(level);
	cout<<"Left: ";
    print(root->left,level+1);
  	}
  	if(root->right!=NULL){ 		
    printspace(level);
    cout<<"Right: ";
    print(root->right,level+1);
  	}

}
int main(){
     int n;
     cin>>n;
     treenode* alnode[n];
     for(int i=0;i<n;i++){
     	
     	alnode[i]=new treenode(-1);
     }
     loop(n){
     	int value,x,y;
     	cin>>value>>x>>y;
     	alnode[i]->data=value;

     	if(x!=-1) alnode[i]->left=alnode[x];
     	if(y!=-1) alnode[i]->right=alnode[y];
     }
     print(alnode[0],0);
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

Output:
------------------
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