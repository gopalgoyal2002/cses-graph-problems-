#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>g[n];
    vector<int>in(n,0);
    int mod=1e9+7;
  while(k--)
  {
      int a,b;
      cin>>a>>b;
      a--,b--;
      g[a].push_back(b);
      in[b]++;
  
  }
  vector<ll>dp(n,0);
  queue<int>q;
  for(int i=0;i<n;i++)
  {
    if(in[i]==0)
    {
      q.push(i);
     
    }

  }
   dp[0]=1;
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    for(auto v:g[u])
    {
      in[v]--;
      dp[v]=dp[u]%mod+dp[v]%mod;
      if(in[v]==0)
      {
        q.push(v);
      }
    }
  }
  cout<<dp[n-1]%mod<<endl;
  return 0;
 


}