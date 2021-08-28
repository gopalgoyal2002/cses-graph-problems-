#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long


#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>             vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================


int a[N];

void solve() {
  int i, j, n, m;
}

vector<pair<ll,ll>>g[N];
vector<ll>dist(N,1e18);


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 ll n,k;
   cin>>n>>k;
   while(k--)
   {
       ll a,b,t;
       cin>>a>>b>>t;
       a--,b--;
       g[a].push_back({t,b});
     

   }
   dist[0]=0;
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

   pq.push({0,0});
  
   while(!pq.empty())
   {
       pair<ll,ll>p=pq.top();
       pq.pop();
       ll u=p.second;
       ll t=p.first;
       if(dist[u]<t)
       continue;
       
       for(auto v:g[u])
       {   if(v.second!=u)
         {
           if(dist[v.second]>t+v.first)
           {
               dist[v.second]=t+v.first;
              
               pq.push({dist[v.second],v.second});
           }
         }
       }
   }
   for(int i=0;i<n;i++)
   {
       cout<<dist[i]<<" ";
   }
  
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


