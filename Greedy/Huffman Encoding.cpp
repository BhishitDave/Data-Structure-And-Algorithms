#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    char data;
    int frequency;
    Node *left , *right;
    Node(char data , int frequency)
    {
        left=right=NULL;
        this->data =data;
        this->frequency=frequency;
    }

};
class Compare {
public:
    bool operator()(Node* a,
                    Node* b)
    {
        return a->frequency > b->frequency;
    }
};
Node* generateTree(priority_queue<Node*,vector<Node*>,Compare> pq)
{
    
}
void HuffmanCodes(char data[] , int freq[] , int size)
{
    priority_queue<Node*,vector<Node*>,Compare> pq; // second arg is optional
    for(int i=0;i<size;i++)
    {
        Node* temp = new Node(data[i] , freq[i]);
        pq.push(temp);
    }
    Node* root = generateTree(pq);
}
int main()
{
    
    return 0; 
}