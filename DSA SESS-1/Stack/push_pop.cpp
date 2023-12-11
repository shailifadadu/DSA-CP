//push and pop in stack

#include<iostream>
using namespace std;
const int MAX_SIZE = 4;

class stack
{
  int top;
  int st[MAX_SIZE];

  public:
  stack()
  {
    top=-1;
  }

  int push(int b)
  {
    if(top==MAX_SIZE-1)
    {
      return 0;
    }
    else
    {
      top++;
      st[top]=b;
      return 1;
    }
  }

  int pop()
  {
    if(top==-1)
    {
      return 0;
    }
    else 
    {
      int x=st[top];
      top--;
      return x;
    }
  }
};
int main()
{
  stack s1;
  int x;

  cout<<"Enter element : \n";
  for(int i=0;i<MAX_SIZE;i++)
  {
    cin>>x;
    int res=s1.push(x);

    if(res==1)
    {
      cout<<"Element inserted successfully\n";
    }
    else if(res==0)
    {
      cout<<"stack overflow\n";
    }
  }

  cout<<"pop elements : \n";
  for(int i=0;i<MAX_SIZE; i++)
  {
    int res=s1.pop();
    if(res==0)
    {
      cout<<"Stack is empty\n";
    }
    else
    {
      cout<<"popped element : "<<res<<endl;
    }
  }
  return 0;
}