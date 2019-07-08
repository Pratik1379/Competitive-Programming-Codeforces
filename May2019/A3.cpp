#include<bits/stdc++.h>
using namespace std;
vector< pair<long long int,int> > a,b;
int main()
{
    int n,k;long long int x;
    cin>>n>>k;
    for(int i=0;i<n;i++)
      {
          cin>>x;
          a.push_back({x,i});
      }
    sort(a.begin(),a.end());
    long long int dif[n];
    for(int i=0;i<n-1;i++)
    {
        dif[i]=a[i+1].first-a[i].first;
    }
    long long int sum=0,ctr=n-1;
    for(int i=0;i<n-1;i++,ctr--)
        sum+=ctr*dif[i];
    ctr=1;
    for(int i=0;i<n;i++)
    {
        b.push_back({sum,a[i].second});
        sum=sum+dif[i]*ctr-dif[i]*(n-ctr);
        ctr++;
    }
    int ind=b[0].second;long long int ans=b[0].first-k;
    if(ans<0)
        {
        	if(abs(ans)&1)
        		ans=1;
        	else
        		ans=0;
        }
    for(int i=1;i<n;i++)
    {
        long long int res=b[i].first-k;
        if(res<0)
        {
        	if(abs(res)&1)
        		res=1;
        	else
        		res=0;
        }
        if(res<ans)
        {
            ans=res;ind=b[i].second;
        }
        else if(res==ans && ind>b[i].second)
        {
            ind=b[i].second;
        }
    }
    cout<<ind+1<<" "<<ans;
    return 0;
}