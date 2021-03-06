 
#include<bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
 
const int nax = 1e5+10;
vector<int> g[nax] , vis(nax,0) , par(nax,0);
 
void dfs(int v)
{
    vis[v] = 1;
    for(auto &i : g[v] )
    {
        if( !vis[i] )
        {
            par[v] = i;
            dfs( i );
        }
        else if( vis[i] == 1 )
        {
            vector<int> ans;
            ans.pb( i );
            int j = i;
            par[v] = i;
            while( par[j] != i )
            {
                ans.pb( par[j] );
                j = par[j];
            }
            ans.pb( i );
            cout << ans.size() << "\n";
            for(auto &j : ans )
                cout << j << " " ;
            exit(0);
        }
    }
    vis[v] = 2;
    return ;
}
signed main()
{
    fast;
    int n , m;
    cin >> n >> m;
    for(int i=1 ; i<=m ; i++ )
    {
        int u , v;
        cin >> u >> v;
        if( u == v )
        {
            cout << "2\n";
            cout << u << " " << v << "\n";
        }
        g[u].pb( v );
    }
    for(int i=1 ; i<= n ; i++ )
    {
        if( !vis[i] )
            dfs(i);
    }
    cout << "IMPOSSIBLE";
}