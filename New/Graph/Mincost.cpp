#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int MAX=105;
int n,m,S,T,C,Edge=0,res=0,d[MAX],cost[2*MAX*MAX],c[2*MAX*MAX],f[2*MAX*MAX];
ii Trace[MAX];
bool Inqueue[MAX];
vector<ii> g[MAX];
queue<int> Q;

void AddEdge(int u,int v,int w,int d)
{
    g[u].push_back(ii(v,++Edge));
    cost[Edge]=w;
    c[Edge]=d;
    g[v].push_back(ii(u,++Edge));
    cost[Edge]=w;
    c[Edge]=d;
}

bool SPFA()
{
    for(int i=1;i<=n;i++)
        d[i]=1e9;
    d[S]=0;
    Q.push(S);
    Inqueue[S]=true;
    while(Q.size()>0)
    {
        int u=Q.front();
        Q.pop();
        Inqueue[u]=false;
        for(auto tmp:g[u])
        {
            int v=tmp.first;
            int id=tmp.second;
            if(f[id]<c[id]&&d[v]>d[u]+(f[id]>=0?cost[id]:-cost[id]))
            {
                d[v]=d[u]+(f[id]>=0?cost[id]:-cost[id]);
                Trace[v]=ii(u,id);
                if(Inqueue[v]==false)
                {
                    Inqueue[v]=true;
                    Q.push(v);
                }
            }
        }
    }
    return (d[T]!=1e9);
}

int Enlarge(int delta)
{
    int u=T;
    while(u!=S)
    {
        int id=Trace[u].second;
        delta=min(delta,(f[id]>=0?c[id]-f[id]:-f[id]));
        u=Trace[u].first;
    }
    u=T;
    while(u!=S)
    {
        int id=Trace[u].second;
        f[id]+=delta;
        id=(id%2==0?id-1:id+1);
        f[id]-=delta;
        u=Trace[u].first;
    }
    res+=delta*d[T];
    return delta;
}

int Exist[MAX][MAX];

int main()
{
    cin>>n>>m>>C>>S>>T;
    int u,v,w,d;
    while(m--)
    {
        cin>>u>>v>>w>>d;
        AddEdge(u,v,w,d);
    }
    int cnt=0;
    while(SPFA()==true)
    {
        if(C==0)
            break;
        C-=Enlarge(C);
    }
    if(C>0)
    {
        cout<<-1;
        return 0;
    }
    cout<<res<<"\n";
    for(int u=1;u<=n;u++)
        for(auto tmp:g[u])
        {
            int v=tmp.first;
            int id=tmp.second;
            if(f[id]>0)
                cout<<u<<' '<<v<<' '<<f[id]<<"\n";
        }
    cout<<"0 0 0";
}
