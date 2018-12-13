#include<bits/stdc++.h>
using namespace std;
int deg[200001]={0};
int main()
{
    int n,m,k,x,y;
    cin>>n>>m>>k;
    int c1=0;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        if((deg[x]+1)==k)
        {
            c1++;
        }
        deg[x]++;
        if((deg[y]+1)==k)
        {
            c1++;
        }
        deg[y]++;
        cout<<c1<<endl;
    }
    return 0;
}
