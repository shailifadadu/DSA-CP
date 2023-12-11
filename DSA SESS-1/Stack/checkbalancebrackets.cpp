// check the balanced brackets

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool balanceBrackets(string s)
{
  int n=s.size();
  stack<char>st;
  for(int i=0;i<n;i++)
  {
    if(s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
      st.push(s[i]);
    }
    else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
    {
      if(st.empty())
      {
        return false;
      }
      char top = st.top();
      st.pop();

      if((s[i] == ')' && top!='(') ||
          (s[i] == '}' && top!='{') ||
          (s[i] == ']' && top!='['))
          {
            return false;
          }
    }
  }
  return st.empty();//it indicates all brackets are matched
}

int main()
{
  string s;
  cout<<"Enter an expression : ";
  getline(cin,s);

  if(balanceBrackets(s))
  {
    cout<<"The brackets are balanced"<<endl;
  }
  else
  {
    cout<<"The brackets are not balanced"<<endl;
  }
  return 0;
}