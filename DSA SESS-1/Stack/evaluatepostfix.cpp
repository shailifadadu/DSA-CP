//postfix evaluation

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int postfixEvaluation(string s)
{
  stack<int>st;
  for(int i=0;i<s.length();i++)
  {
    //if char is operand
    if(s[i]>='0' && s[i]<='9')
    {
      st.push(s[i]-'0');  //character to integer
    }
    //if char is operator
    else 
    {
      int op2=st.top();
      st.pop();
      int op1=st.top();
      st.pop();

      switch(s[i])
      {
        case '+' : st.push(op1+op2);
                    break;
        case '-' : st.push(op1-op2);
                    break;
        case '*' : st.push(op1*op2);
                    break;
        case '/' : st.push(op1/op2);
                    break;
        case '^' : st.push(pow(op1,op2));
                    break;
      }

    }
  }

  return st.top();
}

int main()
{
  int result;
  string s;
  cout<<"Enter postfix expression : \n";
  cin>>s;
  result=postfixEvaluation(s);
  cout<<"Evaluated postfix expression : \n";
  cout<<result<<endl;
  return 0;
}