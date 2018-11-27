#include <bits/stdc++.h>
using namespace std;

const int MAX=105;
int m,n,Match[MAX],Free[MAX];
vector<int> g[MAX];

bool DFS(int u,int kk)
{
    if(Free[u]==kk)
        return false;
    Free[u]=kk;
    for(auto v:g[u])
        if(Match[v]==0||DFS(Match[v],kk)==true)
        {
            Match[v]=u;
            return true;
        }
    return false;
}

int main()
{
    cin>>m>>n;
    int u,v;
    while(cin>>u>>v)
        g[u].push_back(v);
    int res=0,cnt=0;
    for(int i=1;i<=m;i++)
        res+=DFS(i,++cnt);
    cout<<res<<"\n";
    for(int i=1;i<=n;i++)
        if(Match[i]!=0)
            cout<<Match[i]<<' '<<i<<"\n";
}
