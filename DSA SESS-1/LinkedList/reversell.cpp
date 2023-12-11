//reverse singly linked list

#include<iostream>
using namespace std;
class Implement;
class Node
{
friend class Implement;
int data;
Node* next;

public:
Node(int val)
{
data=val;
next=NULL;
}
};

class Implement
{
Node* head;
public:
Implement()
{
  head=NULL;
}

void insert(int d)
{
  Node* n=new Node(d);
  if(head==NULL)
  {
    head=n;
  }
  else
  {
    Node* temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=n;
  }
}

void reverse()
{
  Node* curr=head;
  Node* prev=NULL;
  Node* forward=NULL;
  while(curr!=NULL)
  {
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
  }
  head=prev;
}

void display()
{
  Node* temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

};
int main()
{
  Implement i;
  i.insert(10);
  i.insert(20);
  i.insert(30);
  i.insert(40);
  i.insert(50);
  cout<<"Before Reversing : "<<endl;
  i.display();
  cout<<"After Reversing : "<<endl;
  i.reverse();
  i.display();
  return 0;
}