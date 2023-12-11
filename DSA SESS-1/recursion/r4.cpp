//factorial in recursion

#include<iostream>
using namespace std;

int fact(int n)
{
  if(n==0)
  {
    return 1; //if return 0 then ans will be 0
  }
  else
  {
    return n*fact(n-1);
  }
}

int main()
{
  int n;
  cin>>n;
  cout<<fact(n);
  return 0;
}