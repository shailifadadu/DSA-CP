//Addition of polynomial using array

#include<iostream>
using namespace std;
class poly
{
  public:
  int coeff;
  int exp;

  void insert(int c, int e)
  {
    coeff=c;
    exp=e;
  }

  void display()
  {
    cout<<coeff<<"x^"<<exp<<" + ";
  }

  int polyAdd(poly p1[], poly p2[], poly p3[], int n1, int n2)
  {
    int i,j,k,n3;
    i=j=k=0;
    while(i<n1 && j<n2)
    {
      if(p1[i].exp == p2[j].exp)
      {
      p3[k].coeff=p1[i].coeff+p2[j].coeff;
      p3[k].exp=p1[i].exp;
      i++;
      k++;
      j++;
      }
      else if(p1[i].exp > p2[j].exp)
      {
        p3[k].coeff=p1[i].coeff;
        p3[k].exp=p1[i].exp;
        i++;
        k++;
      }
      else if(p2[j].exp > p1[i].exp)
      {
        p3[k].coeff=p2[j].coeff;
        p3[k].exp=p2[j].exp;
        j++;
        k++;
      }
    }

    while(i<n1)
    {
      p3[k].coeff=p1[i].coeff;
      p3[k].exp=p1[i].exp;
      i++;
      k++;
    }

    while(j<n2)
    {
      p3[k].coeff=p2[j].coeff;
      p3[k].exp=p2[j].exp;
      j++;
      k++;
    }
    n3=k;
    return n3;
  }
};

int main()
{
  int n1,n2,c,e,n3,n;
  cout<<"Enter size of p1 : ";
  cin>>n1;
  poly p1[n1];
  cout<<"Enter coeff & exp of p1 : \n";
  for(int i=0;i<n1;i++)
  {
    cin>>c>>e;
    p1[i].insert(c,e);
  }
  for(int i=0;i<n1;i++)
  {
    p1[i].display();
  }
  cout<<endl;

  cout<<"Enter size of p2 : ";
  cin>>n2;
  poly p2[n2];
  cout<<"Enter coeff & exp of p1 : \n";
  for(int i=0;i<n2;i++)
  {
    cin>>c>>e;
    p2[i].insert(c,e);
  }
  for(int i=0;i<n2;i++)
  {
    p2[i].display();
  }
  cout<<endl;

  n=n1;
  poly p3[n];
  n3 = p3[n].polyAdd( p1, p2, p3, n1, n2);
  
  for(int i=0;i<n3;i++)
  {
    p3[i].display();
  }
  return 0;
}