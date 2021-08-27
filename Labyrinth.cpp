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


 
 int dx[4]={0,1,-1,0};
 int dy[4]={1,0,0,-1};
 char c[4]={'R','D','U','L'};
  vector<vector<bool>>vis(1000,vector<bool>(1000,false));
  
  vector<string>v(1000);
  vector<string>path(1000);

int a,b;
  void dfs(int i,int j)
  {
     
      if(v[i][j]=='B')
      {
           cout<<"YES"<<endl;
           vector<char>vec;
        //    fo(x,a)
        //    {
               
        //            cout<<path[x]<<endl;
               
        //    }
           while(v[i][j]!='A')
           {
               vec.push_back(path[i][j]);
               fo(k,4)
               {
                   if(path[i][j]==c[k])
                   {
                       i=i-dx[k];
                       j=j-dy[k];
                       break;
                   }
               }
           }
           string s;
           if(v[i][j]=='A')
           {
              
              fo(x,vec.size())
              {
               s+=vec[x];

              }
           }
           reverse(s.begin(),s.end());
           cout<<s.size()<<endl;
           cout<<s<<endl;
           exit(0);
           }

           
      
      
          for(int k=0;k<4;k++)
          {
              int x=i+dx[k];
              int y=j+dy[k];
              if(x>=0&&y>=0&&x<a&&y<b&&vis[x][y]==false&&v[x][y]!='#')
              {
                  vis[x][y]=true;
                  path[x][y]=c[k];
                  dfs(x,y);
              }
              
          }
          
      
  }

void solve() {
 
 int n,m;
 cin>>n>>m;
 a=n;
 b=m;
path=vector<string>(n);
 fo(i,n)
 {
cin>>v[i];
path[i]=v[i];
 }

 for(int i=0;i<n;i++)
 {
     fo(j,m)
     {
         if(v[i][j]=='A')
         {    vis[i][j]=true;
             dfs(i,j);
            //  cout<<i<<j;
             break;
         }
     }
 }
 cout<<"NO"<<endl;


   
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    
      solve();
    

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
// void ipgraph(int n, int m){
// 	int i, u, v;
// 	while(m--){
// 		cin>>u>>v;
//     u--, v--;
// 		g[u].pb(v);
// 		g[v].pb(u);
// 	}
// }

