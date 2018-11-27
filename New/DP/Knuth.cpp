// Original Recurrence:
//   dp[i][j] = min(dp[i][k] + dp[k][j]) + C[i][j]   for k = i+1..j-1
// Necessary & Sufficient Conditions:
//   A[i][j-1] <= A[i][j] <= A[i+1][j]
//   with A[i][j] = smallest k that gives optimal answer
// Also applicable if the following conditions are met:
//   1. C[a][c] + C[b][d] <= C[a][d] + C[b][c] (quadrangle inequality)
//   2. C[b][c] <= C[a][d]                     (monotonicity)
//   for all a <= b <= c <= d

#include <bits/stdc++.h>
using namespace std;

const int MAX=2005;
int n,a[MAX],f[MAX][MAX],Trace[MAX][MAX];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        f[i][i]=0;
        Trace[i][i]=i;
    }
    for(int len=1;len<n;len++)
        for(int i=1;i<=n-len;i++)
        {
            int j=i+len;
            f[i][j]=1e9;
            for(int k=Trace[i][j-1];k<=Trace[i+1][j];k++)
                if(f[i][j]>f[i][k-1]+f[k][j]+a[j]-a[i-1])
                {
                    f[i][j]=f[i][k-1]+f[k][j]+a[j]-a[i-1];
                    Trace[i][j]=k;
                }
        }
    cout<<f[1][n];
}
