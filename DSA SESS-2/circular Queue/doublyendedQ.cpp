//implementation of doubly ended Queue

#include<bits/stdc++.h>
using namespace std;

class Deque
{
  int *arr;
  int front,rear,size;

  public:
  Deque(int s)
  {
    size=s;
    arr = new int[s];
    front=rear=-1;
  }

  void pushFront(int n)
  {
    if(isFull())
    {
      cout<<"Queue is Full"<<endl;
      return;
    }
    else if(isEmpty())
    {
      front=rear=0;
    }
    else if(front == 0 && rear!=size-1)
    {
      front=size-1;
    }
    else 
    {
      front--;
    }
    arr[front]=n;
  }

  void pushRear(int x)
  {
    if(isFull())
    {
      cout<<"Queue is Full"<<endl;
      return;
    }
    else if(isEmpty())
    {
      front=rear=0;
    }
    else if(rear == size-1 && front!=0)
    {
      rear=0;
    }
    else 
    {
      rear++;
    }
    arr[rear]=x;
  }

  int popFront()
  {
    if(isEmpty())
    {
      cout<<"queue is empty"<<endl;
      return -1;
    }

    int ans=arr[front];
    arr[front]=-1;

    if(front == rear)
    {
      front=rear=-1;
    }
    else if(front == size-1)
    {
      front=0;
    }
    else {
      front++;
    }
    return ans;
  }

  int popRear()
  {
    if(isEmpty())
    {
      cout<<"Queue is empty"<<endl;
      return -1;
    }

    int ans=arr[rear];
    arr[rear]=-1;

    if(front == rear)//if single element is present
    {
      front=rear=-1;
    }
    else if(rear == 0)
    {
      rear=size-1;
    }
    else 
    {
      rear--;
    }
    return ans;
  }

  int getFront()
  {
    if(isEmpty())
    {
      return -1;
    }
    return arr[front];
  }

  int getRear()
  {
    if(isEmpty())
    {
      return -1;
    }
    return arr[rear];
  }

  bool isEmpty()
  {
    if(front == -1)
    {
      return true;
    }
    else 
    {
      return false;
    }
  }

  bool isFull()
  {
    if((front == 0 && rear == size-1) || (front == (rear+1)%size))
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
  Deque d(5);

  d.pushFront(10);
  d.pushFront(20);
  d.pushFront(30);
  d.pushFront(40);
  d.pushFront(50);

  cout<<"Front element : "<<d.getFront()<<endl;
  cout<<"End element : "<<d.getRear()<<endl;

  cout<<"ELEMENT DELETED"<<endl;
  cout<<d.popRear()<<endl;
  cout<<d.popRear()<<endl;
  return 0;
}