//Recursively merge sort

#include<iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
  int mid = (s+e)/2;
  int len1 = mid-s+1;
  int len2 = e-mid;

  int *first = new int[len1];
  int *sec = new int[len2];

  //copy values
  int mainArrayIndex=s;
  for(int i=0;i<len1;i++)
  {
    first[i]=arr[mainArrayIndex++];
  }

  mainArrayIndex=mid+1;
  for(int i=0;i<len2;i++)
  {
    sec[i]=arr[mainArrayIndex++];
  }

  //merge 2 sorted arrays
  int index1=0;
  int index2=0;
  mainArrayIndex=s;

  while(index1 < len1 && index2 < len2)
  {
    if(first[index1] < sec[index2])
    {
      arr[mainArrayIndex]=first[index1++];
    }
    else 
    {
      arr[mainArrayIndex]=sec[index2++];
    }
    mainArrayIndex++;
  }

  while(index1 < len1)
  {
    arr[mainArrayIndex]=first[index1++];
    mainArrayIndex++;
  }

  while(index2 < len2)
  {
    arr[mainArrayIndex]=sec[index2++];
    mainArrayIndex++;
  }
}

void mergeSort(int *arr, int s, int e)
{
  if(s>=e)
  {
    return ;
  }

  int mid = (s+e)/2;
  mergeSort(arr,s,mid);//sort left part
  mergeSort(arr,mid+1,e);//sort right part

  merge(arr,s,e);

}

int main()
{
  int arr[5]={2,5,1,6,9};
  int n=5;

  mergeSort(arr,0,n-1);

  cout<<"After sorting : \n";
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}