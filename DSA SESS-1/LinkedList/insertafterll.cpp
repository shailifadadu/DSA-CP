//insert after in singly linked list
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

  void insertAtTail(int d)
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

  void insertAfter(int x, int d)
  {
    Node* n=new Node(d);
    Node*temp=head;
    while(temp->data!=x)
    {
      temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
  }

  void display()
  {
    Node* temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<"NULL"<<endl;
  }
};
int main()
{
  Implement i;
  int n;
  i.insertAtTail(1);
  i.insertAtTail(2);
  i.insertAtTail(3);
  i.insertAtTail(4);
  i.insertAtTail(5);
  cout<<"Before inserting : "<<endl;
  i.display();
  cout<<"Enter value after which u want to insert : ";
  cin>>n;
  i.insertAfter(n,6);
  cout<<"After inserting : "<<endl;
  i.display();
  return 0;
}