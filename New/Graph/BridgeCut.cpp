#include <bits/stdc++.h>
using namespace std;

const int MAX=10005;
int n,m,cnt=0,Bridge=0,Cut=0,Num[MAX],Low[MAX];
vector<int> g[MAX];

void DFS(int u,int par)
{
    Num[u]=Low[u]=++cnt;
    int Child=0;
    bool check=false;
    for(auto v:g[u])
        if(Num[v]==0)
        {
            Child++;
            DFS(v,u);
            Low[u]=min(Low[u],Low[v]);
            if(Low[v]>=Num[v])
                Bridge++;
            check|=((u!=par&&Low[v]>=Num[u])||(u==par&&Child>=2));
        }
        else
        if(v!=par)
            Low[u]=min(Low[u],Num[v]);
    Cut+=check;
}

int main()
{
    cin>>n>>m;
    int u,v;
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(Num[i]==0)
            DFS(i,i);
    cout<<Cut<<' '<<Bridge;
}
