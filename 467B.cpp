#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    bitset<22> a;
    bitset<22> j;
    int b[m+1];
    for(int i=0;i<=m;i++)
        cin>>b[i];
    a=b[m];
    int l=0;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        j=b[i];
        l=0;
        for(int i=0;i<21;i++)
        {
            if(j[i]^a[i])
            {
                l++;
            }
        }
        if(l<=k)
            ans++;
    }
    cout<<ans;
}
