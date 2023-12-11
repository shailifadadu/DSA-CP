//Multiple recursion calls
//fibonacci number

#include<iostream>
using namespace std;

int f(int n)
{
  if(n<=1)
  {
    return n;
  }
  else
  {
    int last=f(n-1);
    int slast=f(n-2);
    return last+slast;
  }
}

int main()
{
  cout<<f(4);
  return 0;
}