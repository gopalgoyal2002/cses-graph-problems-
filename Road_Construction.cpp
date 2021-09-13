#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

vector<int>g[N];
vector<int>parent(N);
vector<int>siz(N,1);

///disjoint set

int find(int a)
{
    if(parent[a]==a)
    return a;
    parent[a]=find(parent[a]);
    return parent[a];
}

void uni(int a,int b)
{
       int a_rep=find(a);
       int b_rep=find(b);
       if(a_rep==b_rep)
       return ; 
       if(siz[a_rep]>siz[b_rep])
       {
            parent[b_rep]=a_rep;
          siz[a_rep]=siz[b_rep]+siz[a_rep];
        
       }
       else{
             parent[a_rep]=b_rep;
          siz[b_rep]=siz[b_rep]+siz[a_rep];
       }
     
}
///disjoint set


int c=0;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    parent[i]=i;
    c=n;
    int s=1;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        int a_rep=find(a);
        int b_rep=find(b);
        if(a_rep!=b_rep)
        {
         c--;
         uni(a,b);
         s=max(s,max(siz[b_rep],siz[a_rep]));
        }
        
         cout<<c<<" "<<s<<endl;
    }
}