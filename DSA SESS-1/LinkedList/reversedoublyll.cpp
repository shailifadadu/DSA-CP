//reverse doubly likedlist

#include<iostream>
using namespace std;
class implement;
class node
{
  friend class implement;
  int data;
  node*next;
  node*prev;
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
  node*head;
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
      node*temp=head;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      n->prev=temp;
      temp->next=n;
    }
  }

  void reverse()
  {
    node*curr=head;
    node*temp=NULL;
    while(curr!=NULL)
    {
      temp=curr->prev;
      curr->prev=curr->next;
      curr->next=temp;
      curr=curr->prev;
    }
    head=temp->prev;
  }

  void display()
  {
    node*temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
  }
};
int main()
{
  implement obj;
  int x;
  cout<<"Enter elements : \n";
  for(int i=0;i<3;i++)
  {
    cin>>x;
    obj.insert(x);
  }

  cout<<"After reversing doubly : \n";
  obj.reverse();
  obj.display();
  return 0;
}