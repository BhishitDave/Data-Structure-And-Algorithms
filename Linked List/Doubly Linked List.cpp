#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
} *head = NULL;

void print();
void Insert(Node *p, int index, int x);
void Display(Node *p);
int Length(Node *p);
void Delete(Node *p, int index);
void Reverse(Node *p);

int main()
{
    Insert(head, 0, 1);
    Insert(head, 0, 2);
    Insert(head, 0, 3);
    Display(head);
    Reverse(head);
    // Delete(head, 3);
    Display(head);
    return 0;
}
void Display(Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int Length(struct Node *p)
{
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void Insert(Node *p, int index, int x)
{
    Node *t;
    int i;
    if (index < 0 || index > Length(p))
    {
        cout << "Out of Bounds!!";
        return;
    }
    if (index == 0)
    {
        t = new Node();
        t->data = x;
        t->prev = NULL;
        t->next = head;
        if (head != NULL)
            head->prev = t;
        head = t;
        // cout << "done";
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node();
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
void Delete(Node *p, int index)
{
    int x = -1, i;
    if (index < 1 || index > Length(p))
    {
        cout << "Out Of Bounds";
        return;
    }
    if (index == 1)
    {
        head = head->next;
        if (head)
            head->prev = nullptr;
        free(p);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        free(p);
    }
}
void Reverse(Node *p)
{
    Node *temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            head = p;
    }
}