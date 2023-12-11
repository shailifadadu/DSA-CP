//insertAfter in circular linked list
#include<iostream>
using namespace std;
class CLL;

class node
{
  friend class CLL;
  int data;
  node* next;
  public:
  node(int d)
  {
    data=d;
    next=NULL;
  }
};

class CLL
{
  node* head;
  public:
  CLL()
  {
    head=NULL;
  }

  void insertAfter(int d)
  {
    node* n=new node(d);
    if(head==NULL)
    {
      head=n;
      head->next=head;
    }
    else
    {
      node*temp=head;
      while(temp->next!=head)
      {
        temp=temp->next;
      }
      temp->next=n;
      n->next=head;
    }
  }

  void display()
  {
    node*temp=head;
    do 
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;
  }
};
int main()
{
  CLL obj;
  int x;
  cout<<"Enter elements : \n";
  for(int i=0;i<3;i++)
  {
    cin>>x;
    obj.insertAfter(x);
  }

  cout<<"After inserting : \n";
  obj.display();
  return 0;
}
