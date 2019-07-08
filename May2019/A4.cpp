#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int g[n][2],je[m][2];
	vector<int> v[n];
	for(int i=0;i<n;i++)
		cin>>g[i][0]>>g[i][1];
	for(int i=0;i<m;i++)
		cin>>je[i][0]>>je[i][1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(abs(je[j][1]-g[i][1])<=(je[j][0]-g[i][0]))
			{
				v[i].push_back(j);
			}
		}
	}
	int po = pow(2,n);
	int mini =1000;
	for(int i=1;i<po;i++)
	{
		bitset<30> a =i;
		int cnt=a.count();
		int ctr=0;
		for(int k=0;k<30;k++)
		{
			bool check[100000]={false};
			if(a[k]==1)
			{
				int r1 = v[k].size();
				for(int l=0;l<r1;l++)
				{
					if(!check[v[k][l]])
					{
						check[v[k][l]]=true;ctr++;
					}
				}
			}
		}
		if(ctr==m)
			mini=min(mini,cnt);
	}
	cout<<(n-mini);
	return 0;
}