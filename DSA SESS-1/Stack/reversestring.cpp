//reversing string using stack

#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverseString(string s)
{
  int n=s.size();
  stack<char>st;
  for(int i=0;i<n;i++)
  {
    st.push(s[i]);
  }

  string ans;
  while(!st.empty())
  {
    ans+=st.top();
    st.pop();
  }
  return ans;
}

int main()
{
  string s;
  cout<<"Enter string : ";
  getline(cin,s);

  string result=reverseString(s);
  cout<<"after reversing : ";
  cout<<result<<endl;
  return 0;
}