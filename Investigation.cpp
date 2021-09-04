
// what is the minimum price of such a route?
// how many minimum-price routes are there? (modulo 109+7)
// what is the minimum number of flights in a minimum-price route?
// what is the maximum number of flights in a minimum-price route?
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

vpl g[N];
void solve() {
    int n,m;
    cin>>n>>m;
     vector<vector<int>>v(400,vector<int>(400,INT_MAX));
    while(m--)
    {
        ll a,b,t;
        cin>>a>>b>>t;
        a--,b--;
        
        v[a][b]=t;
    }
    int q;
    cin>>q;

      

       for(int i=0;i<400;i++)
       v[i][i]=0;

       for(int k=0;k<400;k++)
       {
         for(int i=0;i<400;i++)
         {
            for(int j=0;j<400;j++)
            {
              v[i][j]=min(v[i][k]+v[k][j],v[i][j]);
            }
         }
       }
       while(q--)
       {
         int a,b;
         cin>>a>>b;
         a--,b--;
         if(v[a][b]==INT_MAX)
         cout<<-1<<endl;
         else
         cout<<v[a][b]<<endl;
       }

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


