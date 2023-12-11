//Insertion sort

#include<iostream>
#include<vector>
using namespace std;

void insertionSort(int n, vector<int>&arr)
{
  for(int i=1;i<n;i++)
  {
    int temp=arr[i];
    int j=i-1;
    while(j>=0)
    {
      if(arr[j] > temp)
      {
        arr[j+1]=arr[j];//shifted right
      }
      else 
      {
        break;
      }
      j--;  //j is decremented to check the previous element in the sorted part of the array.
    }
    arr[j+1]=temp;
  }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    insertionSort(n, arr);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}