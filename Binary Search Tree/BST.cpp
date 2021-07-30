#include <iostream>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};
Node* insert(Node * root, int key){
	if(root==NULL){
		return new Node(key);
	}

	//rec case 
	if(key < root->key){
		root->left = insert(root->left,key);
	}
	else{
		root->right = insert(root->right,key);
	}
	return root;

}

bool search(Node * root, int key){
	//Homework
    if(root==NULL)
        return false;
    if(root->key==key)
        return root;
    else if(root->key>key)
        return search(root->left, key);
    else
        return search(root->right,key);
	
}

Node *getSuccessor(Node* curr)
{
    curr=curr->right;
    while(curr!=NULL and curr->left!=NULL)
        curr=curr->left;
    return curr;
}
Node *deleteNode(Node *root,  int X)
{
    // your code goes here
    if(root==NULL)
        return NULL;
    if(root->key > X)
        root->left=deleteNode(root->left,X);
    else if(root->key < X)
        root->right=deleteNode(root->right,X);
    else
    {
        if(root->left==NULL)
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ=getSuccessor(root);
            root->key=succ->key;
            root->right=deleteNode(root->right, succ->key);
        }
    }
    return root;
}


void printInOrder(Node *root){
	if(root==NULL){
		return;
	}
	//left, root, right
	printInOrder(root->left);
	cout << root-> key <<" ";
	printInOrder(root->right);
}


int main(){

	Node * root = NULL;
	int arr[] = {8,3,10,1,6,14,4,7,13};

	for(int x : arr){
		root = insert(root,x);
	}
	printInOrder(root);
    cout<<endl;
    cout<<search(root,39);
	return 0;
}