#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;
vector<pair<int,int>> v[100005];
long long int wt[100005];
long long int cnt[400005]={0};
void dfs(int s,int par,int wei)
{
	wt[s]=wei;
	for(int i=0;i<v[s].size();i++)
	{
		if(v[s][i].first!=par)
		{
			dfs(v[s][i].first,s,(wei^v[s][i].second));
		}
	}
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	long long int n;
	int x,y,z;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	dfs(1,-1,0);
	long long int temp=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int res=wt[i]^wt[j];
			cnt[res]++;
			bitset<24> a1=res;
			if(a1.count()==1 || a1.count()==0)
				temp=(temp+2)%mod;
		}
	}
 
	long long int ans=(n*n)%mod;
	ans=(ans+(2*temp*n)%mod)%mod;
	//cout<<ans<<endl;
	ans=(ans+(2*(n-1)*n)%mod)%mod;
	for(int i=0;i<=300000;i++)
	{
		bitset<20> ab =i;
		long long int tem=cnt[i];
		long long int tem2=0;
		long long int z=1;
		for(int j=0;j<20;j++)
		{
		    if(ab[j]==0 && (z+i)<400000)
		    {
    		    //cout<<i<<"**"<<z+i<<endl;
    			tem2=(tem2+cnt[z+i])%mod;
		    }
		    z=z*2;
		}
		ans=(ans+(tem*(tem-1)*4)%mod)%mod;
		ans=(ans+(((tem*tem2)%mod)*8)%mod)%mod;
	}
	cout<<ans<<endl;
}