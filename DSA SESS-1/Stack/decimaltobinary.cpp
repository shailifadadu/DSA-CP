//decimal to binary using stack

#include<iostream>
#include<stack>
using namespace std;

void dectobin(int n)
{
  stack<int>st;
  while(n > 0)
  {
    int r=n%2;
    st.push(r);
    n=n/2;
  }

  cout<<"Binary representation : ";
  while(!st.empty())
  {
    cout<<st.top();
    st.pop();
  }
  cout<<endl;
}

int main()
{
  int num;
  cout<<"Enter any number : ";
  cin>>num;

  dectobin(num);
  return 0;
}