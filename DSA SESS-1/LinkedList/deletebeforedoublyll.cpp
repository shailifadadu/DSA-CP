// delete before some position in doubly linked list

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
      temp->next=n;
      n->prev=temp;
    }
  }

  void del(int x)
  {
    node*temp=head;
    while(temp->data!=x)
    {
      temp=temp->next;
    }
    node* todelete = temp->prev;
    temp->prev->prev->next=temp;
    temp->prev=temp->prev->prev;
    delete(todelete);
  }

  void display()
  {
    node* temp=head;
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
  implement i;
  i.insert(1);
  i.insert(2);
  i.insert(3);
  i.insert(4);
  i.insert(5);
  cout<<"Before inserting : \n";
  i.display();
  int x;
  cout<<"Enter element before which u want to delete : ";
  cin>>x;
  cout<<"after deleting : \n";
  i.del(x);
  i.display();
  return 0;
}