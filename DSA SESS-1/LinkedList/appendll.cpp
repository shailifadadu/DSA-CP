//append in singly linked list
#include<iostream>
using namespace std;
class implement;
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
      Node*temp=head;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=n;
    }
  }

  void append(Implement *l1, Implement *l2)
  {
    head=l1->head;
    Node* temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=l2->head;
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
  Implement i1,i2;
  int n;
  
  cout<<"Enter Elements for i1 : ";
  for(int i=0;i<5;i++)
  {
    cin>>n;
    i1.insert(n);
  }
  i1.display();

  
  cout<<"Enter Elements for i2 : ";
  for(int i=0;i<5;i++)
  {
    cin>>n;
    i2.insert(n);
  }
  i2.display();


  Implement i3;
  i3.append(&i1, &i2);
  i3.display();

  return 0;
}