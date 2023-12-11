//in functional way do sum of n terms

#include<iostream>
using namespace std;

int f(int n)
{
  if(n==0)
  {
    return 0;
  }
  else
  {
    return n+f(n-1);
  }
}

int main()
{
  int n;
  cin>>n;
  cout<<f(n);
  return 0;
}