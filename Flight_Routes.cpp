

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<ll,ll>>g[n];
    vector<ll>ans(n,0);
    while(m--)
    {
        ll a,b,t;
        cin>>a>>b>>t;
        a--,b--;
        g[a].push_back({t,b});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    pq.push({0,0});
    ll count=0;
    while(!pq.empty())
    {
           ll u=pq.top().second;
           ll t=pq.top().first;
           
           pq.pop();
           ans[u]++;
           if(ans[u]>k)
           continue;
           if(u==n-1)
           {
               cout<<t<<" ";
               count++;
              
           }
           if(count==k)
           {
               exit(0);
           }
           for(auto v:g[u])
           {
               pq.push({t+v.first,v.second});
           }
    }
    return 0;
}