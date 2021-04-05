#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define Saif ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
 /*
int greedy[int coin[], int limit, int size]
{
    int box= limit, big_value,need_coin;
      sort(coin, coin+size);
    int vectoe<int>bag;
      while (box > 0)
      {
          big_value = coin[size--];
          need_coin = box / big_value;
          box= box - need_coin*big_value;
          v.pb(box);
      }

}

void Dynamic()
{

}
*/
int main()
{
   // Saif;
    int limit,type;
    cout<<"Coin limit : ";
    cin>>limit;
    cout<<endl;

    cout<<"Coin type: ";
    cin>>type;
    int coin[type];
    cout<<endl;

    cout<<"Coins: ";
    for(int i=0; i<type; i++)
        cin>>coin[i];

//....Greedy Aproh Impliment... but it's not parfect and not efisient
    int box= limit, big_value,need_coin,cnt=0,ans=0;
    sort(coin, coin+type);
    vector<int>bag;

    while (box > 0)
    {
        big_value = coin[--type];
        need_coin = box / big_value;
        box= box - need_coin*big_value;
        if(need_coin>0)
        {

            while(need_coin!=0)
            {
                bag.pb(big_value);
                cnt++;
                need_coin--;
                ans+=big_value;
            }
        }

    }

    cout<<"Greedy need minimum "<<cnt<<" coins. ";
    for(int i=0; i<bag.size(); i++)
    {
        cout<<bag[i];
        if(i<bag.size()-1) cout<<"+";
    }
    cout <<" = "<<ans;


    return 0;
}

