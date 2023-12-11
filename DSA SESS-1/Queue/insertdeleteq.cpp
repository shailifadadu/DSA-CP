//insertion and deletion in queue

#include<iostream>
using namespace std;
int const MAX=3;
class queue
{
  int front;
  int rear;
  int q[MAX];
  public:
  queue()
  {
    rear=-1;
    front=-1;
  }

  void insert()
  {
    if(rear==MAX)
    {
      cout<<"Queue is full"<<endl;
    }
    else
    {
      rear++;
      cin>>q[rear];
    }
  }

  int del()
  {
    if(rear==front)
    {
      cout<<"Queue is empty"<<endl;
    }
    else
    {
      front++;
      int x=q[front];
      return x;
    }
  }
};

int main()
{
  queue obj;
  for(int i=0;i<MAX;i++)
  {
    obj.insert();
  }

  for(int i=0;i<MAX ;i++)
  {
    int a=obj.del();
    cout<<"number "<<a<<" is deleted"<<endl;
  }
  return 0;
}