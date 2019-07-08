#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> st,en;
int j=0;
int s[300005],e[300005];
int par[300005];
int n;
void dfs(int pr,int in)
{
	int start=st[in].first;
	int end=e[st[in].second];	
	par[st[in].second]=pr;
	int cnt=end-start;
	while(cnt>(j-in))
		dfs(st[in].second,++j);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		st.push_back({s[i],i});
		par[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>e[i];
		e[i]--;
		en.push_back({e[i],i});
	}
	sort(st.begin(),st.end());
	sort(en.begin(),en.end());
	int prev=st[0].second;
	dfs(prev,0);
	par[prev]=-1;
	for(int i=0;i<n;i++)
	{
		cout<<par[i]+1<<" ";
	}
	return 0;
}