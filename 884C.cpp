#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int val[n+1];
    for(int i=1;i<=n;i++)
        cin>>val[i];
    bool vis[100001]={false};
    vector<long int> v;
    long int cycle=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cycle=1;
            int y=val[i];
            while(y!=i)
            {
                vis[y]=true;
                cycle++;
                y=val[y];
            }
            v.push_back(cycle);
        }
    }
    int r1=v.size();
    sort(v.begin(),v.end());
    if(r1==1)
    {
        cout<<v[0];
    }
    else if(r1==2)
    {
        cout<<((v[0]+v[1])*(v[0]+v[1]));
    }
    else
    {
        long int sum1=0;
        for(int i=0;i<r1-2;i++)
        {
            sum1+=(v[i]*v[i]);
        }
        sum1+=((v[r1-1]+v[r1-2])*(v[r1-1]+v[r1-2]));
        cout<<sum1;
    }

    return 0;
}
