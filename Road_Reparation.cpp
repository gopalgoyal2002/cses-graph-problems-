#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(int i=0;i<n;i++)

#define ll long long

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()

#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

int mpow(int base, int exp); 
void ipgraph(int n, int m);

void uni(int x,int y,vector<int>&parent,vector<int>&rank);
int find(int x,vector<int>&parent);
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
 const int V=100000;  
//=======================

vpl g[N];
int a[N];
  vector<bool>vis(N,false);
 
void solve() {
  
int n;
cin>>n;

int m;
cin>>m;
while(m--)
{
   ll int a,b,t;
    cin>>a>>b>>t;
    a--,b--;
    g[a].push_back({t,b});
    g[b].push_back({t,a});
}
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
vector<ll>dest(N,1e18);
pq.push({0,0});
vis[0]=true;
ll int c=0;
dest[0]=0;
while(!pq.empty())
{
    int u=pq.top().second;
    ll int t=pq.top().first;
    pq.pop();
    for(auto v:g[u])
    {
        if(dest[v.second]>dest[u]+v.first)
        {
            dest[v.second]=dest[u]+v.first;
            vis[v.second]=true;
            pq.push({dest[v.second],v.second});
            c+=v.first;
        }
    }
   
}
 for(int i=0;i<n;i++)
    cout<<dest[i]<<" ";
    cout<<c<<endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    
    
      solve();
    
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

    int find(int x,vector<int>&parent)
    {
        if(parent[x]==x)
        return x;
      parent[x]= find(parent[x],parent);
        return parent[x];
    }
    
    void uni(int x,int y,vector<int>& parent,vector<int>&rank)
    {   
        int x_rep=find(x,parent);
        int y_rep=find(y,parent);
        if(x_rep==y_rep)
        return ;
       else if(rank[x_rep]<rank[y_rep])
        {
            parent[x_rep]=y_rep;
        }
        else if(rank[x_rep]>rank[y_rep])
        {
            parent[y_rep]=x_rep;
        }
        else
        {
            parent[y_rep]=x_rep;
            rank[x_rep]++;
        }
    }

