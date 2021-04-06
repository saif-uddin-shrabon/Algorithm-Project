#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define Saif ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
const int MAX_INT = 1e6+50;   
int limit,type,box, big_value,need_coin,store,coin[MAX_INT];

void greedy()
{

   int sum=0;
    sort(coin, coin+type);
    map<int ,int>bag;
     store = box;
    while (box > 0)
    {
        big_value = coin[--type];
        need_coin = box / big_value;
        if(need_coin>0)
        bag[big_value]+=need_coin;
        sum+=need_coin;
        box= box - need_coin*big_value;
    }

     cout<<"Greedy need minimum "<<sum<<" coins. ";
    int mp_sz=bag.size(), value=0;
    for(auto it: bag)
    {
        value++;
        if(it.second>1)
            cout<<it.first<<"*"<<it.second;
            else cout<<it.first;
        if(mp_sz > value) cout<<"+";
    }
    cout <<" = "<<store-box;;
    
    cout<<endl;
}

// Sir DP apnar video dekhe onek try korci run korate parle o output dekhayte pari ni
void Daynamic()
{
    int Table[type+1][limit+1];

    for(int r=0; r<=type; r++)
    {
        for(int c=0; c<=limit; c++)
        {
            if(c == 0) Table[r][c]= 0;
            else if( r == 0) Table[r][c] == 1e5;
            else
            {
                if(c - coin[r] >= 0)
                {
                    if(Table[r-1][c] <= 1+Table[r][c - coin[r]])
                         Table[r][c] = Table[r-1][c];
                    else
                        Table[r][c] = 1+Table[r][c - coin[r]];
                }
                else
                    Table[r][c] = Table[r-1][c];
            }
        }
    }
cout<<"DP need minimum "<<Table[type][limit]<<" coins: ";


    // Back Treacking

    int i= type;
    int j= limit;
    int cnt=0;
    map<int, int>beg;

    while(Table[i][j] != 0)
    {
        if(Table[i-1][j] == Table[i][j])
            i--;
        else
        {
            cnt++;
            //cout<<coin[i];
            beg[coin[i]]++;
            j = j-coin[i];
        }
    }

    
    int mp_sz=beg.size(), value=0;
    for(auto it: beg)
    {
        value++;
        if(it.second>1)
            cout<<it.first<<"*"<<it.second;
            else cout<<it.first;
        if(mp_sz > value) cout<<"+";

    }

    //cout<<endl;

}


int main()
{
    //Saif;

    cout<<"Coin limit : ";
    cin>>limit;
    box=limit;
    cout<<endl;

    cout<<"Coin type: ";
    cin>>type;

    cout<<endl;

    cout<<"Coins: ";
    for(int i=0; i<type; i++)
        cin>>coin[i];

     greedy();
     Daynamic();
    return 0;
}