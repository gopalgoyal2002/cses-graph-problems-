
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
// vector<int>top;
// vector<bool>vis(false,N);

// vector<int>ans(N);
// int c=1;
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

// int main(){
   
    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     cout<<endl;
    //     st.pop();
    // }
   
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


const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================
vi g[N],g1[N];
int a[N];
vector<bool>vis(N,false);
void solve() {
  int i, j, n, m;
}

void dfs(int u, stack<int>&st){
     vis[u]=true;
	for(int v:g[u]){
		if (vis[v]==true) continue;
		dfs(v, st);
	}
    st.push(u);
    
}
 vector<int>ans(N);
 int c=0;
void dfs1(int u){
     vis[u]=true;
     ans[u]=c;
	for(int v:g1[u]){
		if (vis[v]==true) continue;
		dfs1(v);
	}
    
    
}



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
   int n,m;
    cin>>n>>m;

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
       g[a].push_back(b);
      g1[b].push_back(a);
      
    }
    stack<int>st;
    for(int i=0;i<n;i++)
    {
    if(vis[i]==false)
        dfs(i,st);
    }
   vis=vector<bool>(N,false);
    while(!st.empty())
    { 
        if(vis[st.top()]==true)
        {
            st.pop();
            continue;
        }
        c++;
        dfs1(st.top());
        st.pop();
        


    }
    cout<<c<<endl;
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";

    return 0;
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

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}


