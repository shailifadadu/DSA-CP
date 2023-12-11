//delete after in singly linked list
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

  void deleteAfter(int x)
  {
    
    Node*temp=head;
    while(temp->data!=x)
    {
      temp=temp->next;
    }
    Node *todelete=temp->next;
    temp->next=temp->next->next;
    delete(todelete);
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
  cout<<"Before deleting : "<<endl;
  i.display();
  cout<<"Enter element after which u want to delete : ";
  cin>>n;
  i.deleteAfter(n);
  cout<<"After deleting : "<<endl;
  i.display();
  return 0;
}