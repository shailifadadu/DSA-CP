//stack using singly linked list

#include<iostream>
using namespace std;
class stack;
class node
{
  friend class stack;
  int data;
  node*next;
  public:
  node(int val, node* t)
  {
    data=val;
    next=t;
  }
};
class stack
{
  node* top;
  public:
  stack()
  {
    top=NULL;
  }

  int push(int d)
  {
    top=new node(d,top);
    return 1;
  }
  
  int pop()
  {
    if(top==NULL)
    {
      return 0;
    }
    else
    {
      int x=top->data;
      top=top->next;
      return x;
    }
  }
};
int main()
{
  stack st;
  int x,res;
  for(int i=0;i<3;i++)
  {
    cin>>x;
    res=st.push(x);
    if(res==1)
    {
      cout<<"element inserted in stack"<<endl;
    }
  }

  for(int i=0;i<3;i++)
  {
    res=st.pop();
    if(res==0)//res==(int)"empty"
    {
      cout<<"Stack is empty"<<endl;
    }
    else
    {
      cout<<"element poped : "<<res<<endl;
    }
  }
  return 0;
}