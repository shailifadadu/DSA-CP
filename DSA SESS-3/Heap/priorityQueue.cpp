//MAxHeap and MinHeap using priority Queue

#include<iostream>
#include<queue>
using namespace std;

int main()
{
  cout<<"Priority Queue here"<<endl;
  //maxheap
  priority_queue<int>pq;

  pq.push(4);
  pq.push(2);
  pq.push(5);
  pq.push(3);

  cout<<"Element at top : "<<pq.top()<<endl;
  pq.pop();
  cout<<"element at top : "<<pq.top()<<endl;
  cout<<"size is : "<<pq.size();


  //minheap
  priority_queue<int, vector<int>, greater<int>>minheap;
  minheap.push(4);
  minheap.push(2);
  minheap.push(5);
  minheap.push(3);

  cout<<"Element at top : "<<minheap.top()<<endl;
  minheap.pop();
  cout<<"element at top : "<<minheap.top()<<endl;
  cout<<"size is : "<<minheap.size();
  return 0;
}