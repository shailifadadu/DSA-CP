//Queue using singly linked list
//first in first out

#include<iostream>
using namespace std;
class queue;
class node
{
  friend class queue;
  int data;
  node* next;
  public:
  node(int val)
  {
    data=val;
    next=NULL;
  }
};
class queue
{
  node* front;
  node* rear;
  public:
  queue()
  {
    front=rear=NULL;
  }

  void insert(int d)
  {
    node*n=new node(d);
    if(front == NULL && rear==NULL)
    {
      front=n;
      rear=n;
    }
    else
    {
      rear->next=n;
      rear=rear->next;
    }
  }

  int del()
  {
    if(front==NULL)
    {
      return 0;
    }
    else
    {
      int x=front->data;
      front=front->next;
      return x;
    }
  }
};
int main()
{
  queue q;
  int x,res;
  for(int i=0;i<3;i++)
  {
    cin>>x;
    q.insert(x);
  }

  for(int i=0;i<3;i++)
  {
    res=q.del();
    if(res==0)
    {
      cout<<"Queue is empty"<<endl;
    }
    else
    {
      cout<<"element deletd : "<<res<<endl;
    }
  }
  return 0;
}