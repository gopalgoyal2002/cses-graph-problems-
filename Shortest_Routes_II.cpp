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

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

int a[N];
vector<vector<ll>>v(500,vector<ll>(500,1e9));


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

       int n,m,q;
    cin>>n>>m;
    
    while(m--)
    {
        int a,b;
       ll t;
       cin>>a>>b;
       cin>>t;
       a--,b--;
       v[a][b]=t;
       
    }
    cin>>q;
    for(int i=0;i<n;i++)
    {
        v[i][i]=0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
            }
        }
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(v[a][b]<1e9)
        cout<<v[a][b]<<endl;
        else 
        cout<<-1<<endl;
    }


    return 0;
}




