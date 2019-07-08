#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m;cin>>n>>m;
	int a[n],l[n],r[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		l[i]=r[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{			
			int j=i-1;
			while(j>=0 && a[j]==0)
			{
			    if(r[j]==-1)
				    r[j]=i;
			    else 
			        r[j]=min(r[j],i);
				j--;
			}
			if(j>=0 && r[j]==-1)
			    r[j]=i;
			else if(j>=0)
			    r[j]=min(r[j],i);
			j=i+1;
			while(j<n && a[j]==0)
			{
				if(l[j]==-1)
				    l[j]=i;
				else
				    l[j]=min(i,l[j]);
				j++;
			}
			if(j<n && l[j]==-1)
			    l[j]=i;
			else if(j<n)
			    l[j]=min(l[j],i);
		}
	}
	/*for(int i=0;i<n;i++)
	    cout<<l[i]<<"**"<<r[i]<<endl;*/
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		//y--;
		if(x==0)
		{
			cout<<l[y]<<" "<<r[y]<<endl;
		}
		else
		{
			a[y]=1;
			int j=y-1;
			while(j>=0 && a[j]==0)
			{
			    if(r[j]==-1)
				    r[j]=y;
				else
				    r[j]=min(y,r[j]);
				j--;
			}
			if(j>=0 && r[j]==-1)
			    r[j]=y;
			else if(j>=0)
			    r[j]=min(r[j],y);
			j=y+1;
			while(j<n && a[j]==0)
			{
			    if(l[j]==-1)
				    l[j]=y;
				else
				    l[j]=min(y,l[j]);
				j++;
			}
			if(j<n && l[j]==-1)
			    l[j]=y;
			else if(j<n)
			    l[j]=min(l[j],y);
		}
	}
	return 0;
}