//insertBefore in circular linked list

#include<iostream>
using namespace std;
class CLL;

class node
{
  friend class CLL;
  int data;
  node* next;
  public:
  node(int d,node* h)
  {
    data=d;
    next=h;
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
  void insertBefore(int d)
  {
    node*n=new node(d,head);
    if(head==NULL)
    {
      head=n;
      head->next=head;
    }
    else 
    {
      node* temp=head;
      while(temp->next!=head)
      {
        temp=temp->next;
      }
      temp->next=n;
      head=n;
    }
  }

  void display()
  {
    node*temp=head;
    do
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    } while (temp!=head);
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
    obj.insertBefore(x);
  }

  cout<<"after inserting before : \n";
  obj.display();
  return 0;
}
