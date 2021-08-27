#include<bits/stdc++.h>
using namespace std;



int main()
{
    
    int n,m;
    cin>>n>>m;
    vector<string>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<vector<char>>path(n,vector<char>(m));
    int dx[4]={0,-1,1,0};
    int dy[4]={1,0,0,-1};
    char xx[4]={'R','U','D','L'};
    queue<pair<int,int>>q,q1;
    vector<vector<int>>mtime(n,vector<int>(m,INT_MAX));
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<bool>>vis1(n,vector<bool>(m,false));
  vector<vector<int>>atime(n,vector<int>(m,-1));
    vector<vector<char>>p(n,vector<char>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

             if(v[i][j]=='M')
             {
                 q.push({i,j});
                 mtime[i][j]=0;
                 vis[i][j]=true;
             }
             if(v[i][j]=='A')
             {
             q1.push({i,j});
             atime[i][j]=0;
                 vis1[i][j]=true;

             }
        }
    }
    while(!q.empty())
    {
        int l=q.size();
        while(l--)
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0&&y>=0&&x<n&&y<m&&vis[x][y]==false&&v[x][y]!='#')
                {
                    vis[x][y]=true;
                    q.push({x,y});
                    mtime[x][y]=mtime[i][j]+1;
                }
            }
        }

    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<mtime[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
  
    while(!q1.empty())
    {
        int l=q1.size();
        while(l--)
        {
            int i=q1.front().first;
            int j=q1.front().second;
            q1.pop();
              if(mtime[i][j]<=atime[i][j])
            continue;
            if(i==0||j==0||i==n-1||j==m-1)
            {
                  cout<<"YES"<<endl;
                  string s;
                   
                  while(v[i][j]!='A')
                  {  
                    //   for(int i=0;i<n;i++)
                    //   {
                    //       for(int j=0;j<m;j++)
                    //       {
                    //           cout<<path[i][j]<<" ";

                    //       }
                    //       cout<<endl;
                    //   }
                      s+=path[i][j];
                      for(int k=0;k<4;k++)
                      {
                          if(path[i][j]==xx[k])
                          {
                              i=i-dx[k];
                              j=j-dy[k];
                                                            break;
                          }
                      }
                      
                     
                  }
                  reverse(s.begin(),s.end());
                   cout<<s.length()<<endl;
                   cout<<s<<endl;
                 exit(0);
            }
          
            
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0&&y>=0&&x<n&&y<m&&vis1[x][y]==false&&v[x][y]!='#'&&v[x][y]!='M')
                {
                    path[x][y]=xx[k];
                    vis1[x][y]=true;
                    q1.push({x,y});
                    atime[x][y]=atime[i][j]+1;
                }
            }
        }
       
    }
 cout<<"NO"<<endl;
        return 0;


}