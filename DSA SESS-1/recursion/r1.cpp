//print names n times using recursion
#include<iostream>
using namespace std;

void fun(int i, int n)
{
  if(i>n) //  base case
  {
    return;
  }
  else
  {
    cout<<"Shaiy";
    fun(i+1,n);
  }

}

int main()
{
  int n;
  cin>>n;
  fun(1,n);
  return 0;
}