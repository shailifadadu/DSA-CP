//infix to postfix

#include<iostream>
#include<stack>
using namespace std;

int prec(char c)//3>2>1>-1
{
  if(c=='^')
  {
    return 3;
  }
  else if(c=='*' || c=='/')
  {
    return 2;
  }
  else if(c=='+' || c=='-')
  {
    return 1;
  }
  else 
  {
    return -1;
  }
}

string infixtopostfix(string s)
{
  string res;
  stack<char>st;

  for(int i=0;i<s.length();i++)
  {
    if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
    {
      res+=s[i];
    }
    else if(s[i]=='(')
    {
      st.push(s[i]);
    }
    else if(s[i]==')')
    {
      while(!st.empty() && st.top()!='(')
      {
        res+=st.top();
        st.pop();
      }
      if(!st.empty())
      {
        st.pop();
      }
    }
    else
    {
      while(!st.empty() && prec(st.top())>prec(s[i]))
      {
        res+=st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }
  while(!st.empty())
  {
    res+=st.top();
    st.pop();
  }
  return res;
}

int main()
{
  string result;
  string s;
  cout<<"Enter infix expression : \n";
  cin>>s;
  result=infixtopostfix(s);
  cout<<"Postfix expression is : \n";
  cout<<result<<endl;
  return 0;
}