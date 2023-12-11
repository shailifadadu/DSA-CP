//polynomial multiplication

#include<iostream>
using namespace std;

class poly
{
public:
    int coeff;
    int exp;

    void insert(int c, int e)
    {
        coeff = c;
        exp = e;
    }

    poly operator*(poly other)
    {
        poly result;
        result.coeff = coeff * other.coeff;
        result.exp = exp + other.exp;
        return result;
    }

    void display()
    {
        cout << coeff << "x^" << exp << " ";
    }
};

int main()
{
    int n1, n2, c, e, n3 = 0;
    cout << "Enter size of p1: ";
    cin >> n1;
    poly p1[n1];

    cout << "Enter coeff & exp of p1: \n";
    for (int i = 0; i < n1; i++)
    {
        cin>>c>>e;
        p1[i].insert(c, e);
    }

    cout << "Enter size of p2: ";
    cin >> n2;
    poly p2[n2];

    cout << "Enter coeff & exp of p2: \n";
    for (int i = 0; i < n2; i++)
    {
        cin>>c>>e;
        p2[i].insert(c, e);
    }

    poly p3[n1 * n2];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            p3[n3] = p1[i] * p2[j];
            n3++;
        }
    }

    cout << "After multiplying: \n";
    for (int i = 0; i < n3; i++)
    {
        p3[i].display();
    }
    return 0;
}
