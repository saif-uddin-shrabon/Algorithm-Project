#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n1, n2;

    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }

    cout << "HCF = " << n1;
    cout<<endl;
    }
    return 0;
}
