#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

vector<int>g[N],g1[N];


///disjoint set
// vector<int>parent(N);
// vector<int>siz(N,1);
// int find(int a)
// {
//     if(parent[a]==a)
//     return a;
//     parent[a]=find(parent[a]);
//     return parent[a];
// }

// void uni(int a,int b)
// {
//        int a_rep=find(a);
//        int b_rep=find(b);
//        if(a_rep==b_rep)
//        return ; 
//        if(siz[a_rep]>siz[b_rep])
//        {
//             parent[b_rep]=a_rep;
//           siz[a_rep]=siz[b_rep]+siz[a_rep];
        
//        }
//        else{
//              parent[a_rep]=b_rep;
//           siz[b_rep]=siz[b_rep]+siz[a_rep];
//        }
     
// }
///disjoint set
vector<int>top;
vector<bool>vis(false,N);
vector<int>in(N,0);
vector<int>ans(N);
int c=1;
// void topo(int u)
// {
//     vis[u]=true;
   
//     for(auto v:g[u])
//     {
//         if(vis[v]==false)
//         {
//             topo(v);
//         }
//     }
//     st.push(u);

// }
void dfs(int u)
{
    vis[u]=true;
    ans[u]=c;
    for(auto v:g1[u])
    {
        if(vis[v]==false)
        {
            dfs(v);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
       g[a].push_back(b);
       g1[b].push_back(a);
       in[b]++;
    }
    
    // for(int i=0;i<n;i++)
    // {
    // if(vis[i]==false)
    // topo(i);
    // }
    queue<int>q;
     int x=INT_MAX;
     for(int i=0;i<n;i++)
     {
         x=min(x,in[i]);
     }
     for(int i=0;i<n;i++)
     {
         if(in[i]==x)
         q.push(i);
     }
     while(!q.empty())
     {
         int l=q.size();
         while(l--)
         {
             int u=q.front();
             cout<<u<<" ";
             q.pop();
             
             for(auto v:g[u])
             {
                 
                     in[v]--;
                     if(in[v]==0)
                     q.push(v);
                 
             }
         }
     }
   
    // vis=vector<bool>(false,N);
    // for(int i=0;i<top.size();i++)
    // { 
    //     if(vis[top[i]]==false)
    //     {   
    //     dfs(top[i]);
    //     c++;
    //     }
    // }
    // for(int i=0;i<n;i++)
    // cout<<ans[i]<<" ";

}