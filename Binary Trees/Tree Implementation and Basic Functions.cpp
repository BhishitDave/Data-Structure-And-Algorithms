/*
     Name: Bhishit Dave
     Link : NA
     Logic: 
     Source: Abdul Bari
     List Of functions:  
    void CreateTree(int arr[], int n); // generate tree from level order
    void Levelorder(Node *p); // !!O(n)
    void Preorder(Node *p); // !!O(n)
    void PreorderIterative(Node *p); // !!O(n)
    void Inorder(Node *p); // !!O(n)
    void InorderIterative(Node *p); // !!O(n)
    void Postorder(Node *p); // !!O(n)
    void PostorderIterative(Node *p);
    vector <int> ZigZagIterative(Node *p);
    int Height(Node *root); // !!O(n)
    pair<int,bool> HeightBalanced(Node *root); // !!O(n)
    void leftview(Node *root);
    void rightview(Node *root);
    void topview(Node *root);
    void bottomview(Node *root);
    int Count(Node *p);    
    int LeafCount(Node *p);  
    int diameter(Node *p);  
*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Tree{
    public:
    Node *root;
    Tree(){ root = NULL;}
    void CreateTree(int arr[], int n);
    void Levelorder(Node *p); // !!O(n)
    void Preorder(Node *p); // !!O(n)
    void PreorderIterative(Node *p); // !!O(n)
    void Inorder(Node *p); // !!O(n)
    void InorderIterative(Node *p); // !!O(n)
    void Postorder(Node *p); // !!O(n)
    void PostorderIterative(Node *p);
    vector <int> ZigZagIterative(Node *p);
    int Height(Node *root); // !!O(n)
    pair<int,bool> HeightBalanced(Node *root); // !!O(n)
    void leftview(Node *root);
    void rightview(Node *root);
    void topview(Node *root);
    void bottomview(Node *root);
    int Count(Node *p);    
    int LeafCount(Node *p);  
    int diameter(Node *p);  

};

void Tree::CreateTree(int arr[], int n){
    Node *p , *t;
    int x; // dummy variable for taking input
    deque<Node *>q;
    x=arr[0];
    root = new Node;
    root->data=x;
    root->lchild=NULL;
    root->rchild=NULL;
    q.push_back(root);
    int i=1;
    while(!q.empty())
    {   if(i>=n)
        {
        return;
        }
        p=q.front();
        q.pop_front(); // elimination from queue
        x=arr[i];
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;    
            p->lchild=t;
            q.push_back(t);
        }
        i++;
        if(i>=n)
        {
        return;
        }
        x=arr[i];
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.push_back(t);
        }
        i++;
    }

}
void Tree::Levelorder(Node *root)
{
    queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node* temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			//insert a new null for the next level
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";

			if(temp->lchild){
				q.push(temp->lchild);
			}
			if(temp->rchild){
				q.push(temp->rchild);
			}
		}

	}
	return;
}
void Tree::Preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
}
void Tree::Inorder(Node *root)
{
    if(root!=NULL)
    {
        Inorder(root->lchild);
        cout<<root->data<<" ";
        Inorder(root->rchild);
    }
}
void Tree::Postorder(Node *root)
{
    if(root!=NULL)
    {
        Postorder(root->lchild);
        Postorder(root->rchild);
        cout<<root->data<<" ";
    }
}
void Tree::PreorderIterative(Node *root)
{
    stack<Node *>st;
    while(root!=NULL or !st.empty())
    {
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            st.push(root);
            root=root->lchild;
        }
        else{
            root=st.top();
            st.pop();
            root=root->rchild;
        }
    }
}
void Tree::InorderIterative(Node *root)
{
    stack<Node *>st;
    while(root!=NULL or !st.empty())
    {
        if(root!=NULL)
        {
            st.push(root);
            root=root->lchild;
        }
        else{
            root=st.top();
            st.pop();
            cout<<root->data<<" ";
            root=root->rchild;
        }
    }
}
void Tree::PostorderIterative(Node *root)
{
    stack<Node *>st;
    while(true)
    {
        while(root!=NULL)
        {
            st.push(root);
            st.push(root);
            root=root->lchild;
        }
        if(st.empty())
            return;
        root=st.top();
        st.pop();
        if(!st.empty() and st.top()==root)
            root=root->rchild;
        else{
            cout<<root->data<<" ";
            root=NULL;
        }
    }
}
vector <int> Tree::ZigZagIterative(Node *root)
{
	// Code here
	queue<Node*> q;
	vector<int> v;
	if(!root) return v;
	q.push(root);
	int toggle=1;
	while(!q.empty())
	{
	    vector<int> temp;
	    int sz=q.size();
	        while(sz--)
	        {
	           	Node *t =q.front();
	            temp.push_back(t->data);
	            q.pop();
	            if(t->lchild) q.push(t->lchild);
	            if(t->rchild) q.push(t->rchild);
	            
	        }
	        if(toggle%2==0) reverse(temp.begin(), temp.end());
	        for(int i=0;i<temp.size();i++) v.push_back(temp[i]);
	        toggle=!toggle;
	}
	return v;
}
int Tree::Height(Node *root) 
{
    if(root==NULL)
    {
        return 0;
    }
    int h1=Height(root->lchild);
    int h2=Height(root->rchild);
    return max(h1,h2)+1;
}
pair<int,bool>Tree::HeightBalanced(Node *root){

	pair<int,bool> p, Left, Right;
 
	if(root==NULL){
		p.first = 0; //height
		p.second = true; // balanced
		return p;
	}

	//rec case (Postorder Traversal)
	Left = HeightBalanced(root->lchild);
	Right = HeightBalanced(root->rchild);

	int height = max(Left.first, Right.first) + 1;

	if(abs(Left.first - Right.first)<=1 and Left.second and Right.second){
			return make_pair(height,true);
	}
	return make_pair(height,false);
}
void Tree::leftview(Node *root)
{
   // Your code here
   queue<Node *>q;
   if(!root)
   return;
   q.push(root);
   while(!q.empty())
   {
       int sz=q.size();
       cout<<q.front()->data<<" ";
       while(sz--)
       {
           Node *t= q.front();
           q.pop();
           if(t->lchild)q.push(t->lchild);
           if(t->rchild)q.push(t->rchild);
       }
   }

}
void Tree::rightview(Node *root)
{
   // Your code here
   queue<Node *>q;
   if(!root)
   return;
   q.push(root);
   while(!q.empty())
   {
       int sz=q.size();
       cout<<q.front()->data<<" ";
       while(sz--)
       {
           Node *t= q.front();
           q.pop();
           if(t->rchild)q.push(t->rchild);
           if(t->lchild)q.push(t->lchild);
       }
   }

}
void Tree::topview(Node *root)
{
    queue<pair<Node *,int>> q;
    map<int, int> m;
    q.push({root,0});
    while(!q.empty())
    {
        Node* t=q.front().first;
        int h=q.front().second;
        q.pop();
        if(m[h]==0) m[h]=t->data;
        if(t->lchild) 
            q.push({t->lchild,h-1});
        if(t->rchild) 
            q.push({t->rchild,h+1});
    }
    for(auto x:m){
        cout<<x.second<<" ";
    }
}
void Tree::bottomview(Node *root)
{
    queue<pair<Node *,int>> q;
    map<int, int> m;
    q.push({root,0});
    while(!q.empty())
    {
        Node* t=q.front().first;
        int h=q.front().second;
        q.pop();
        m[h]=t->data;
        if(t->lchild) 
            q.push({t->lchild,h-1});
        if(t->rchild) 
            q.push({t->rchild,h+1});
    }
    for(auto x:m){
        cout<<x.second<<" ";
    }
}
int Tree::Count(Node *p) // postorder form
{
    int x, y;
    if(p)
    {
        x=Count(p->lchild);
        y=Count(p->rchild);
        return x+ y+ 1;
    }
    return 0;
}
// * if(p->lchild!=NULL || p->rchild!=NULL) all internal node degree 2 or 1
// * if((p->lchild!=NULL && p->rchild==NULL) || (p->lchild==NULL && p->rchild!=NULL)) all  node with degree 1
// * if(p->lchild !=NULL ^ p->rchild!=NULL) all  node with degree 1
// * if(p->lchild!=NULL && p->rchild!=NULL) degree 2
int Tree::LeafCount(Node *p) // postorder form
{
    int x, y;
     {
        x=LeafCount(p->lchild);
        y=LeafCount(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
        return x+ y+ 1;
        else
        return x+y; 
    }
    return 0;
}

int Tree::diameter(Node *p)
{ //** space complexcity O(h) and time complexity O(n);
    //  on gfg practice
    // int res=0;
    // int diameter(Node* root) {
    //     int x=height(root);
    //     return res;
    // }
    // int height(Node *root){
    // if(root==NULL)
    //     return 0;
    // int lh=height(root->left);
    // int rh=height(root->right);
    // res=max(res,1+lh+rh);
    // return 1+max(lh,rh);
}

int main()
{
    Tree t;
    int arr[]={1,2,3,4,5,6,7,8,-1,-1,-1,-1,-1,-1,-1,9};
    t.CreateTree(arr,16);
    cout<<"Level Order"<<endl;
    t.Levelorder(t.root);
    cout<<endl;
    // pair<int,bool> p = t.HeightBalanced(t.root);
    // cout<<p.first<<" ";
	// if(p.second){
	// 	cout << "Yes, its height balanced";
	// }
	// else{
	// 	cout << "Not a height balanced tree";
	// }
    // vector<int> ans=t.ZigZagIterative(t.root);
    // for(auto a: ans)
    // {
    //     cout<<a<<" ";
    // }
    t.leftview(t.root);
    cout<<endl;
    t.rightview(t.root);
    cout<<endl;
    t.topview(t.root);
    
}
