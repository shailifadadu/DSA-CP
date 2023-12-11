//in CBT -> leaf node index is from (n/2+1) to (n)
//put nodes at right position from 1 to upto n/2 
// to place a node at its correct position is the work done by heapify

#include<iostream>
using namespace std;

class heap
{
  public :
  int arr[100];
  int size;

  heap()
  {
    arr[0]=-1;
    size=0;
  }

  void insert(int val)
  {
    size=size+1;
    int index = size;
    arr[index]=val;

    while(index > 1)
    {
      int parent = index/2;
      if(arr[parent] < arr[index])
      {
        swap(arr[parent],arr[index]);
        index=parent;
      }
      else 
      {
        return;
      }
    }
  }
};

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2*i;
  int right = 2*i+1;

  if(left < n && arr[largest] < arr[left])
  {
    largest = left;
  }

  if(right < n && arr[largest] < arr[right])
  {
    largest = right;
  }

  if(largest != i)
  {
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
  }
}

int main()
{
  int arr[6]={-1,54,53,55,52,50};
  int n=5;

  cout<<"Before heapifying : \n";
  for(int i=1;i<=n;i++)
  {
    cout<<arr[i]<<" ";
  }cout<<endl;

  for(int i=n/2;i>0;i--)
  {
    heapify(arr,n,i);
  }

  cout<<"After heapifying : \n";
  for(int i=1;i<=n;i++)
  {
    cout<<arr[i]<<" ";
  }cout<<endl;
  return 0;
}