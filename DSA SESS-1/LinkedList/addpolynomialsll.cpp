// Add 2 polynomials in linked list
#include<iostream>
using namespace std;
class polynomial;
class Term
{
  friend class polynomial;
  int coef;
  int exp;
  Term* next;

  public:
  Term(int c, int e)
  {
    coef=c;
    exp=e;
    next=NULL;
  }
};

class polynomial
{
  Term* head;
  public:
  polynomial()
  {
    head=NULL;
  }

  void insert(int c, int e)
  {
    Term* n=new Term(c,e);
    if(head==NULL)
    {
      head=n;
    }
    else
    {
      Term* temp=head;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=n;
    }
  }

  polynomial polyAdd(Term*i1, Term*i2)
  {
    Term* p1=i1;
    Term* p2=i2;
    polynomial p3;

    while(p1!=NULL && p2!=NULL)
    { 
      if(p1->exp == p2->exp)
      {
        p3.insert(p1->coef+p2->coef , p1->exp);
        p1=p1->next;
        p2=p2->next;
      }
      else if(p1->exp > p2->exp)
      {
        p3.insert(p1->coef , p1->exp);
        p1=p1->next;
      }
      else if(p1->exp < p2->exp)
      {
        p3.insert(p2->coef , p2->exp);
        p2=p2->next;
      }
    }

    while(p1!=NULL)
    {
      p3.insert(p1->coef , p1->exp);
      p1=p1->next;
    }

    while(p2!=NULL)
    {
      p3.insert(p2->coef , p2->exp);
      p2=p2->next;
    }

    return(p3);
  }

  Term* gethead()
  {
    return(head);
  }

  void display()
  {
    Term* temp=head;
    while(temp!=NULL)
    {
      cout<<temp->coef<<"x^"<<temp->exp<<" + ";
      temp=temp->next;
    }
    cout<<endl;
  }
};

int main()
{
  polynomial p1,p2,p3;
  int n1,n2;
  cout<<"Enter coef and exp of p1 : ";
  for(int i=0;i<3;i++)
  {
    cin>>n1>>n2;
    p1.insert(n1,n2);
  }

  cout<<"Enter coef and exp of p2 : ";
  for(int i=0;i<3;i++)
  {
    cin>>n1>>n2;
    p2.insert(n1,n2);
  }

  cout<<"Before Adding : \n";
  p1.display();
  p2.display();

  cout<<"After Adding polynomial : \n";
  p3=p3.polyAdd(p1.gethead(), p2.gethead());
  p3.display();
  return 0;
}