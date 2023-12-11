//Implementation of Queue using Array

#include<bits/stdc++.h>
#include<queue>
using namespace std;

class Queue
{
  int *arr;
  int front;
  int rear;
  int size;

  public:
  Queue()
  {
    size=100001;
    arr = new int[size];
    front=-1;
    rear=-1;
  }

  void EnQueue(int x)
  {
    if(front == -1)
    {
      front++;
    }
    if(rear >= size-1)
    {
      cout<<"Queue is full"<<endl;
      return;
    }
    else 
    {
      rear++;
      arr[rear]=x;
    }
  }

  int deQueue()
  {
    if(front == -1 || front>rear)
    {
      cout<<"Queue is Empty"<<endl;
      return -1;
    }
    else 
    {
      int ans = arr[front];
      front++;
      return ans;
    }
  }

  bool isEmpty()
  {
    if(front==-1 || front>rear)
    {
      return true;
    }
    else 
    {
      return false;
    }
  }
};

int main()
{
  Queue q;
  q.EnQueue(10);
  q.EnQueue(20);
  q.EnQueue(30);
  q.EnQueue(40);
  q.EnQueue(50);

  cout<<"FRONT ELEMENT"<<endl;
  cout<<q.deQueue()<<endl;
  cout<<q.deQueue()<<endl;
  cout<<q.deQueue()<<endl;
  cout<<q.deQueue()<<endl;
  cout<<q.deQueue()<<endl;

  cout<<"empty or not ? "<<endl;
  cout<<q.isEmpty()<<endl;
  return 0;
}