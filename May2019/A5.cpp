#include <bits/stdc++.h>
using namespace std; 
vector<pair<int,pair<int,int>>> v;
vector<int> adj[200005];
int ctr[200005]={0};
void dfs(int src,int rem)
{
	int r2=adj[src].size();
	ctr[src]=1;
	for(int i=0;i<r2;i++)
	{
		if(adj[src][i]!=rem)
			dfs(adj[src][i],rem);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int lastAns=0;
	int n,q,c;
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
	    cin>>c;
		adj[c].push_back(i);
	}
	while(q--)
	{
		int pos;
		cin>>pos;
		if(pos==1)
		{
			long long int x,y,z;
			cin>>x>>y>>z;
			x=((x+lastAns-1)%n)+1;y=((y+lastAns-1)%n)+1;
			v.push_back({z,{x,y}});
			//cout<<"1 "<<x<<" "<<y<<endl;
		}
		else
		{
			long long int x,y;
			cin>>x>>y;
			int r1=v.size();
			for(int i=1;i<=n;i++)
			{
				ctr[i]=0;
			}
			x=((x+lastAns-1)%(n-1))+2;
			dfs(1,x);
			long long int sum=0;
			for(int i=0;i<r1;i++)
			{
				long long int w=v[i].first;
				int x1=v[i].second.first;int y1=v[i].second.second;
				if(w%y==0 && ctr[x1]!=ctr[y1])
				{
					sum+=w;
				}
			}
			//cout<<"2 "<<x<<" "<<y<<endl;
			cout<<sum<<"\n";
			lastAns=sum;
		}
	}
	return 0;
}