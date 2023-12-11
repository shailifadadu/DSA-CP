//insert using recursion

#include<iostream>
using namespace std;
class Implement;
class Node
{
  friend class Implement;
  public:
  int data;
  Node* next;
  
  Node(int val)
  {
    data=val;
    next=NULL;
  }
};
class Implement
{
  public:
  Node* head;
  
  Implement()
  {
    head=NULL;
  }

  void insertAtTail(Node* temp, int d)
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
  Node* first = head;
  i.insertAtTail(first,1);
  i.insertAtTail(first,2);
  i.insertAtTail(first,3);
  i.insertAtTail(first,4);
  i.insertAtTail(first,5);
  cout<<"Before inserting : "<<endl;
  i.display();
  cout<<"Enter value after which u want to insert : ";
  cin>>n;
  i.insertAfter(n,6);
  cout<<"After inserting : "<<endl;
  i.display();
  return 0;
}