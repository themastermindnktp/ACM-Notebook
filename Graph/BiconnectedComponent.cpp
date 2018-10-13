//Problem: http://vn.spoj.com/problems/SAFENET2
//Tim thanh phan song lien thong O(n+m)
//Truy vet thanh phan song lien thong lon nhat bang cach luu lai S.top().second sau moi lan pop Stack
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int n,m,cnt=0,res=1,Low[30005],Num[30005];
vector<int> g[30005];
stack<ii> S;

void DFS(int u)
{
    Num[u]=++cnt;
    Low[u]=cnt;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(Num[v]==0)
        {
            S.push(ii(u,v));
            DFS(v);
            Low[u]=min(Low[u],Low[v]);
            if(Low[v]>=Num[u])
            {
                ii tmp;
                int Count=1;
                do
                {
                    Count++;
                    tmp=S.top();
                    S.pop();
                }while(tmp.first!=u||tmp.second!=v);
                res=max(res,Count);
            }
        }
        else
            Low[u]=min(Low[u],Num[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("TEST.INP","r",stdin);
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
            DFS(i);
    cout<<res;
}
