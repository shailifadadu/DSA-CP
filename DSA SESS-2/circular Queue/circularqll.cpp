//circular Queue using LinkedList

#include<bits/stdc++.h>
using namespace std;

class Queue;
class Node
{
  friend class Queue;
  int data;
  Node*next;

  public:
  Node(int d)
  {
    data=d;
    next=NULL;
  }
};

class Queue
{
  Node* front;
  Node* rear;
  public:
  Queue()
  {
    rear=front=NULL;
  }

  void enQueue(int val)
  {
    Node* temp=new Node(val);
    if(front == NULL)
    {
      front=temp;
    }
    else {
      rear->next=temp;
    }
    rear=temp;
    rear->next=front;//to build circular queue
  }

  int deQueue()
  {
    if(front==NULL)
    {
      cout<<"Queue is Empty"<<endl;
    }
    int value;
    if(front==rear)
    {
      value=front->data;
      free(front);
      front=rear=NULL;
    }
    else
    {
      Node* temp=front;
      value=front->data;
      front=front->next;
      rear->next=front;
      free(temp);
    }
    return value;
  }

  void display()
  {
    Node*temp=front;
    while(temp->next != front)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
  }
};
int main()
{
  Queue q;
  q.enQueue(10);
  q.enQueue(20);
  q.enQueue(30);
  q.enQueue(40);
  q.enQueue(50);

  cout<<"Queue after inserting : \n";
  q.display();

  cout<<"Deleted value : "<<q.deQueue()<<endl;
  cout<<"Deleted value : "<<q.deQueue()<<endl;

  cout<<"Queue after deleting : \n";
  q.display();

  return 0;
}