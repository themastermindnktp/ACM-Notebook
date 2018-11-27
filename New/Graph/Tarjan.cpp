#include <bits/stdc++.h>
using namespace std;

const int MAX=10005;
int n,m,cnt=0,Com=0,Num[MAX],Low[MAX];
vector<int> g[MAX];
stack<int> S;

void DFS(int u)
{
    Num[u]=Low[u]=++cnt;
    S.push(u);
    for(auto v:g[u])
        if(Num[v]==0)
        {
            DFS(v);
            Low[u]=min(Low[u],Low[v]);
        }
        else
            Low[u]=min(Low[u],Num[v]);
    if(Num[u]==Low[u])
    {
        Com++;
        int v;
        do
        {
            v=S.top();
            S.pop();
            Num[v]=Low[v]=1e9;
        }while(u!=v);
    }
}

int main()
{
    cin>>n>>m;
    int u,v;
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(Num[i]==0)
            DFS(i);
    cout<<Com;
}
