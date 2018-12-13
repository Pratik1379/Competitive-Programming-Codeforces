#include<bits/stdc++.h>
using namespace std;
long long int ans=0;
long long int xr;
int n,m;
long long int k;
long long int a[25][25];
vector<long long int> b[25][25];
int main()
{
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    b[n-1][m-1].push_back(a[n-1][m-1]);
    if(k==a[n-1][m-1])
        ans++;
    for(int i=n-2;i>=0;i--)
    {
        long long int temp=b[i+1][m-1][0]^a[i][m-1];
        b[i][m-1].push_back(temp);
        if(temp==k)
            ans++;
    }
    for(int i=m-2;i>=0;i--)
    {
        long long int temp=b[n-1][i+1][0]^a[n-1][i];
        b[n-1][i].push_back(temp);
        if(temp==k)
            ans++;
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            for(unsigned int k=0;k<b[i+1][j].size();k++)
            {
                long long int temp=b[i+1][j][k]^a[i][j];
                b[i][j].push_back(temp);
                if(temp==k)
                    ans++;
            }
            for(unsigned int k=0;k<b[i][j+1].size();k++)
            {
                long long int temp=b[i][j+1][k]^a[i][j];
                b[i][j].push_back(temp);
                if(temp==k)
                    ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
