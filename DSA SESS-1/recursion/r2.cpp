//sum of 1st n numbers  1 -> parameterised way

#include<iostream>
using namespace std;

void f(int i, int sum)
{
  if(i<1)
  {
    cout<<sum<<endl;
    return;
  }
  else
  {
    f(i-1, sum+i);
  }
}

int main()
{
  int n;
  cin>>n;
  f(n,0);
  return 0;
}