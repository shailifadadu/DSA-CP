//insertion in linked list
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

  void display()
  {
    Node*temp=head;
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
  i.insertAtTail(10);
  i.insertAtTail(20);
  i.insertAtTail(30);
  i.insertAtTail(40);
  i.insertAtTail(50);
  i.display();
  return 0;
}