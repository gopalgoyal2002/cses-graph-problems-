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
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
 const int V=100000;  
//=======================

vpl g[N];
int a[N];
  vector<bool>vis(N,false);
  vector<int>parent(N);
  vector<vector<ll>>v(N,vector<ll>(3));
int mpow(int base, int exp); 
void ipgraph(int n, int m);

// ------------------------------union and find>

  int find(int x)
    {
        if(parent[x]==x)
        return x;
      parent[x]= find(parent[x]);
        return parent[x];
    }
    
    void uni(int x,int y)
    {   
        int x_rep=find(x);
        int y_rep=find(y);
       
        if(x_rep==y_rep)
        return ;
        parent[y_rep]=x_rep;
        return ;
    }
// ------------------------------union and find>
int c=0;
int x=0;
 ll kruskal_algo()
 {
      sort(v.begin(),v.end());
      ll res=0;
     for(int i=0;i<v.size();i++){
       int a=v[i][1];
       int b=v[i][2];
       int t=v[i][0];
     int  x_rep=find(a);
     int  y_rep=find(b);
       if(x_rep!=y_rep)
       {   x++;
           res+=t;
           uni(x_rep,y_rep);
       }
     }
     if(x!=c-1)
     return -1;
          return res;
 }
void solve() {
  
int n;
cin>>n;
c=n;
for(int i=0;i<n;i++)
{
    parent[i]=i;
}
int m;
cin>>m;
while(m--)
{
   ll int a,b,t;
    cin>>a>>b>>t;
    a--,b--;
   v.push_back({t,a,b});
}
ll int ans=kruskal_algo();
if(ans==-1)
cout<<"IMPOSSIBLE";
else
cout<<ans;
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

  

