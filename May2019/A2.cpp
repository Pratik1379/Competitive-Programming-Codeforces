#include <bits/stdc++.h>
using namespace std; 
long long int mod = 987654319;
int par[300005];long long int cnt[300005];
long long int expo(long long int x, long long int y) 
{ 
    long long int res = 1LL; 
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x)%mod; 
        y = y>>1;
        x = (x*x)%mod;  
    } 
    res = res%mod;
    return res; 
}
int findpar(int src)
{
	if(par[src]==src)
		return src;
	int res = findpar(par[src]);
	par[src]=res;
	return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,x,y;long long int z,m;
	cin>>n>>m;
	multiset<pair<long long int,pair<int,int>>> v;
	for(int i=1;i<n;i++)
	{
		par[i]=i;cnt[i]=1LL;
		cin>>x>>y>>z;
		if(x>y)
			swap(x,y);
		v.insert({z,{x,y}});
	}
	par[n]=n;cnt[n]=1LL;
	long long int ans = 1LL;
	for(int i=1;i<n;i++)
	{
		pair<long long int,pair<int,int>> p = *v.begin();
		v.erase(v.begin());
		long long int w=p.first;
		int x1=p.second.first;int x2=p.second.second;
		int par1 = findpar(x1);
		int par2 = findpar(x2);
		long long int ways = (cnt[par1]*cnt[par2]-1);
		long long int temp = (m-w+2);
		/*cout<<temp<<" "<<ways<<endl;
		for(int l=1;l<=n;l++)
		    cout<<cnt[l]<<" ";
		cout<<endl;*/
		//cout<<x1<<" "<<x2<<" "<<par1<<" "<<par2<<endl;
		long long int rez = expo(temp,ways);
		ans=(ans*rez)%mod;
		if(par1<par2)
		{
		    par[par2]=par1;
		    cnt[par1]+=cnt[par2];
		}
		else
		{
		    par[par1]=par2;
		    cnt[par2]+=cnt[par1];
		}
	}
	cout<<ans;  
	return 0;
}