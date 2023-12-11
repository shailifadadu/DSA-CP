//insertion in doubly linked list

#include<iostream>
using namespace std;
class implement;
class node
{
  friend class implement;
  int data;
  node* next;
  node* prev;
  public:
  node(int val)
  {
    data=val;
    next=NULL;
    prev=NULL;
  }
};
class implement
{
  node *head;
  public:
  implement()
  {
    head=NULL;
  }

  void insert(int d)
  {
    node* n=new node(d);
    if(head==NULL)
    {
      head=n;
    }
    else
    {
      node* temp=head;
      while(temp->next!=NULL)
      {
        temp->prev=temp;
        temp=temp->next;
      }
      temp->next=n;
    }
  }

  void display()
  {
    node* temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp->prev=temp;
      temp=temp->next;
    }
    cout<<"NULL"<<endl;
  }
};
int main()
{
  implement i;
  i.insert(1);
  i.insert(2);
  i.insert(3);
  i.insert(4);
  i.display();
  return 0;
}