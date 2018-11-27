#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int MAX=1005;
int m,n,k,res=0,fx[MAX],fy[MAX],which[MAX],d[MAX],Match[MAX],c[MAX][MAX];
bool Free[MAX];
vector<ii> rs;

int main()
{
    cin>>m>>n>>k;
    n=max(n,m);
    int u,v,w;
    while(k--)
    {
        cin>>u>>v>>w;
        c[u][v]=w;
    }
    for(int i=1;i<=n;i++)
    {
        int j0=0;
        Match[0]=i;
        for(int j=0;j<=n;j++)
        {
            d[j]=-1;
            Free[j]=false;
        }
        do
        {
            Free[j0]=true;
            int i0=Match[j0],delta=-1,j1;
            for(int j=1;j<=n;j++)
                if(Free[j]==false)
                {
                    int tmp=c[i0][j]-fx[i0]-fy[j];
                    if(d[j]<tmp)
                    {
                        d[j]=tmp;
                        which[j]=j0;
                    }
                    if(d[j]>delta)
                    {
                        delta=d[j];
                        j1=j;
                    }
                }
            for(int j=0;j<=n;j++)
                if(Free[j]==true)
                {
                    fx[Match[j]]+=delta;
                    fy[j]-=delta;
                }
                else
                    d[j]-=delta;
            j0=j1;
        }while(Match[j0]!=0);
        do
        {
            int j1=which[j0];
            Match[j0]=Match[j1];
            j0=j1;
        }while(j0!=0);
    }
    for(int i=1;i<=n;i++)
        if(c[Match[i]][i]>0)
        {
            res+=c[Match[i]][i];
            rs.push_back(ii(Match[i],i));
        }
    cout<<res<<"\n"<<rs.size()<<"\n";
    for(auto tmp:rs)
        cout<<tmp.first<<' '<<tmp.second<<"\n";
}
