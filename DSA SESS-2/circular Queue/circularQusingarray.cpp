//implementation of Circular Queue using Array

#include<bits/stdc++.h>
using namespace std;

class CircularQ
{
  int front,rear,size;
  int *arr;

  public:
  CircularQ(int s)
  {
    size=s;
    front=rear=-1;
    arr = new int[size];
  }

  void EnQueue(int x)
  {
    if((front == 0 && rear == size-1) || (front == (rear+1)%size))
    {
      cout<<"Queue is Full"<<endl;
      return;
    }
    else if(front == -1)
    {
      front=rear=0;
      arr[rear]=x;
    }
    else if(rear == size-1 && front!=0)
    {
      rear=0;
      arr[rear]=x;
    }
    else 
    {
      rear++;
      arr[rear]=x;
    }
  }

  int deQueue()
  {
    if(front == -1)
    {
      cout<<"Queue is empty"<<endl;
      return -1;
    }

    int ans=arr[front];
    arr[front]=-1;
    
    if(front == rear)//if single element is present
    {
      front=rear=-1;
    }
    else if(front == size-1)
    {
      front=0;//to maintain cyclic nature
    }
    else 
    {
      front++;
    }
    return ans;
  }

void display()
{
  if(front==-1)
  {
    cout<<"Queue is Empty"<<endl;
    return;
  }
  if(rear >= front)
  {
    for(int i=0;i<size;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
}
};
int main()
{
  CircularQ q(5);
  q.EnQueue(10);
  q.EnQueue(20);
  q.EnQueue(30);
  q.EnQueue(40);
  q.EnQueue(50);

  cout<<"BEFORE DELETING "<<endl;
  q.display();

  cout<<"DELETED ELEMENT"<<endl;
  cout<<q.deQueue()<<endl;
  cout<<q.deQueue()<<endl;

  cout<<"AFTER DELETING : "<<endl;
  q.display();

// cout<<"After iserting"<<endl;
//   q.EnQueue(1);
//   q.EnQueue(2);
//   q.display();
  return 0;
}