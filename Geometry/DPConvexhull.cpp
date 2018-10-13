//f[i]=min(f[j]+a[j+1].second*a[i].first)

#include <bits/stdc++.h>
using namespace std;

typedef pair<int64_t,int64_t> ii;
int64_t nn,n=0,p=1,top=0,f[50005];
ii a[50005],b[50005],S[50005];

bool Check(ii x1,ii x2,ii x3)
{
    //Intersection(x1,x2)=(x1.second-x2.second)/(x2.first-x1.first)
    //Intersection(x1,x3)=(x1.second-x3.second)/(x3.first-x1.first)
    return (x1.second-x3.second)*(x2.first-x1.first)<(x1.second-x2.second)*(x3.first-x1.first);
}

void Update(int64_t a,int64_t b)
{
    while(top>=2&&Check(S[top-1],S[top],ii(a,b))==true)
        top--;
    S[++top]=ii(a,b);
}

int64_t Query(int64_t x)
{
    p=min(p,top);
    while(p<top&&S[p+1].first*x+S[p+1].second<=S[p].first*x+S[p].second)
        p++;
    return S[p].first*x+S[p].second;
}

int main()
{
    cin>>nn;
    for(int64_t i=1;i<=nn;i++)
        cin>>b[i].first>>b[i].second;
    sort(b+1,b+nn+1);
    int64_t maxn=0;
    for(int64_t i=nn;i>=1;i--)
        if(maxn<b[i].second)
        {
            maxn=b[i].second;
            a[++n]=b[i];
        }
    reverse(a+1,a+n+1);
    Update(a[1].second,0);
    for(int64_t i=1;i<=n;i++)
    {
        f[i]=Query(a[i].first);
        Update(a[i+1].second,f[i]);
    }
    cout<<f[n];
}
