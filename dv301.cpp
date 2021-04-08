#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define Saif ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
int main()
{
    ll t,r,c,x;
    cin>>t;

    while (t--)
    {
      cin>>r>>c>>x;
       ll arr[r][c];

       for(int i=0; i<r; i++)
       {
           for(int j=0; j<c; j++)
           {
               cin>>arr[i][j];
           }
       }

       for(int i=0; i<r; i++)
       {
             cout<<arr[i]<<endl;
           for(int j=0; j<c; j++)
           {
               cout<<arr[j]<<" ";
           }
           cout<<endl;
       }
    }
    
}