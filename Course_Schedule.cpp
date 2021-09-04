#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>g[n];
    vector<int>in(n,0);
  while(k--)
  {
      int a,b;
      cin>>a>>b;
      a--,b--;
      g[a].push_back(b);
      in[b]++;
  }
  bool flag=false;
  queue<int>q;
  for(int i=0;i<n;i++)
  {
      if(in[i]==0)
      {
          
           q.push(i);
          
      }
  }
  if(q.empty()==true)
  {
      cout<<"IMPOSSIBLE"<<endl;
      return 0; 
  }
  vector<int>ans;
  while(!q.empty())
  {
      int u=q.front();
      ans.push_back(u+1);
      
      q.pop();
      for(auto v:g[u])
      {
          in[v]--;
          if(in[v]==0)
          q.push(v);
      }
  }
  if(ans.size()!=n)
  cout<<"IMPOSSIBLE"<<endl;
  else{
      for(int i=0;i<n;i++)
      cout<<ans[i]<<" ";
  }


}