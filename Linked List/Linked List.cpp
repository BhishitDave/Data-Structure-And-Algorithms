 #include <bits/stdc++.h>
using namespace std;

class Node { 
public: 
    int data; 
    Node* next; 
}*head=NULL; 


void insert(int data);
void Display(Node *temp);// recursive function to print linked list
int sum(Node *temp); // recursive sum of linked list
void insertNodeAtEnd(int data);
void print();
int Rsearch(Node *temp,int key); //recursive search
void insertAtIndex(Node *temp, int index, int data); 
int count(Node *temp);
void sortedInsertion(Node *temp,int data);
void deleteFirstNode();
void deleteNthNode(int index);
void checkIfSorted(Node *temp);
void deleteDuplicateNode(Node *temp);
void reverseLinkedlist(Node *temp); //changing data 
void reverseLinkedlist2(); // sliding pointers
void rreverseLinkedlist(Node *q, Node *p);// usinfg recursion
int main()
{
    insertNodeAtEnd(1);
    insertNodeAtEnd(1);
    insertNodeAtEnd(2);
    insertNodeAtEnd(2);
    insertNodeAtEnd(6);
    insertNodeAtEnd(6);
    // reverseLinkedlist(head);
    // reverseLinkedlist2();
    // rreverseLinkedlist(nullptr, head);
    // deleteDuplicateNode(head);
    // cout<<Rsearch(head,3);
    // Display(head);
    // cout<<sum(head);
    // insertAtIndex(head,2,10);
    print();
    deleteNthNode(1);
    // checkIfSorted(head);
    // deleteFirstNode();
    print(); 
    // sortedInsertion(head,3);
    // print();
    return 0; 
}
void print()
{   if(head == NULL)
    {
        printf("\nList is empty.\n");
    }
    Node *temp=head;
    cout<<"\nList:";

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void Display(Node *temp) //recursive wayof printing
{
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        Display(temp->next);
    }
}
void insert(int data)//Insert at start
{
    Node *temp=new Node();
    // struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
}
void insertNodeAtEnd(int data)
{
    Node *temp,*newNode;
    newNode=new Node();
    if(head==NULL)
    {
        newNode->data=data;
        newNode->next=head;
        head=newNode;
    }
    else
    {
        newNode->data=data;
        newNode->next=NULL; 
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }    
        temp->next=newNode;

    }

}
int sum(Node *temp)
{
    if(temp!=NULL)
    return sum(temp->next)+temp->data;
    else
    return 0;
    
}
int Rsearch(Node *temp, int key){
    int static index=0;
    if(temp==NULL){
        return -1;
    }
    if(key==temp->data)
    return index;
    index++;
    return (temp->next,key);
}
void insertAtIndex(Node *temp, int index, int data)
{
    if(index<0 || index>count(temp))
    return;
    if(index==0)
    {
        insert(data);
    }
    else
    {
        Node *newNode= new Node();
        newNode->data=data;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    // head->2 3 5 6 

}
int count(Node *temp){
    int l=0;
    while(temp)
    {   
        l++;
        temp=temp->next;
    }
    return l;
}
void sortedInsertion(Node *temp,int data)
{
    Node *q=NULL;
    Node *NewNode=new Node();
    NewNode->data=data;
    while(temp->data<data)
    {
        q=temp;
        temp=temp->next;
    }
    NewNode->next=q->next;
    q->next=NewNode;

}
void deleteFirstNode()
{
    Node *todelete;
    if(head==NULL)
    cout<<"Empty List"<<"\n";
    else
    {
        todelete=head;
        head=todelete->next;
        delete todelete;
    }
    

}
void deleteNthNode(int index)
{
    Node *todelete,*temp;
    todelete=head;
    temp=NULL;
    if(head==NULL)
    cout<<"Empty List"<<"\n";
    else
    {
        for(int i=0;i<index;i++)
        {
            temp=todelete;
            todelete=todelete->next;
        }
        temp->next=todelete->next;
        delete todelete;
    }   
}
void checkIfSorted(Node *temp)
{
    int val=INT_MIN;
    while(temp!=NULL)
    {
        if(temp->data<val)
        {
            cout<<"Not SORTED"<<"\n";
            return;
        }
        else
        {
            val=temp->data;
            temp=temp->next;
        }
    }
    cout<<"SORTED"<<"\n";

}
void deleteDuplicateNode(Node *temp)
{
    Node *first=temp->next;
    while(first!=NULL)
    {
        if((temp->data)!=(first->data))
        {
            temp=first;
            first=first->next;
        }
        else
        {
            temp->next=first->next;
            delete first;
            first=temp->next;
        }
        
    }
    print();
}

void reverseLinkedlist(Node *temp)
{
    int i=0;
    int a[100];
    while (temp!=NULL)
    {
        a[i]=temp->data;
        temp=temp->next;
        i++;
    }
    i--;
    temp=head;
    while (temp!=NULL)
    {
        temp->data=a[i--];
        temp=temp->next;
    }  
}
void reverseLinkedlist2()
{
    Node *p,*q,*r;
    p=head;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
      
}

void rreverseLinkedlist(Node *q, Node *p)
{
    if(p!=NULL)
    {
        rreverseLinkedlist(p,p->next);
        p->next=q;
    }
    else
    {
        head=q;    
    }
    
}