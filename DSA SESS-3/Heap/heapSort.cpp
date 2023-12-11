 //heap sort

 #include<iostream>
 using namespace std;

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2*i;
  int right = 2*i+1;

  if(left <= n && arr[largest] < arr[left])
  {
    largest = left;
  }
  if(right <= n && arr[largest] < arr[right])
  {
    largest = right;
  }

  if(largest!=i)
  {
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
  }
}

 void heapSort(int arr[], int n)//TC -> O(nlogn)
 {
    int size=n;
    while(size>1)
    {
      //step1 : swap
      swap(arr[size],arr[1]);
      size--;

      //step2
      heapify(arr,size,1);
    }
 }

 int main()
 {
  int arr[6]= {-1,54,53,55,52,50};
  int n=5;

  for(int i=1;i<=n;i++)
  {
    heapify(arr,n,i);
  }

  cout<<"After heapifying : \n";
  for(int i=1;i<=n;i++)
  {
    cout<<arr[i]<<" ";
  }cout<<endl;

  //heapsort
  heapSort(arr,n);

  cout<<"After heap sort : \n";
  for(int i=1;i<=n;i++)
  {
    cout<<arr[i]<<" ";
  }cout<<endl;
  return 0;
 }