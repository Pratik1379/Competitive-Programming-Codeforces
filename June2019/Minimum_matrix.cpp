#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v1,v2,v3;
int main() 
{
    vector<pair<int,int>>v4;
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	int maxi=a[0][0];int sc1=0,sc2=0,sc3=0,sc4=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i-1][j-1]>maxi)
				{
					maxi=a[i-1][j-1];sc1++;
				}
				v1.push_back({i,j});
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				if(a[i-1][j-1]>maxi)
				{
					maxi=a[i-1][j-1];sc1++;
				}
				v1.push_back({i,j});
			}
		}
	}
	maxi=a[0][0];
	for(int j=1;j<=m;j++)
	{
		if(j&1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i-1][j-1]>maxi)
				{
					maxi=a[i-1][j-1];sc2++;
				}
				v2.push_back({i,j});
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(a[i-1][j-1]>maxi)
				{
					maxi=a[i-1][j-1];sc2++;
				}
				v2.push_back({i,j});
			}
		}
	}
    int n1=n;
    int x,y;
    maxi=a[0][0];
    int s=0;
    while(n1>1)
    {
        for(int j=s;j+s<m;j++)
        {
            x=s+1;y=j+1;
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc3++;
			}
			v3.push_back({x,y});
        }
        for(int i=s+1;i+s<n && m>s;i++)
        {
        	x=(i+1);y=(m-s);
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc3++;
			}
			v3.push_back({x,y});
        }
        for(int j=m-s-1;j>s;j--)
        {
        	x=n-s;y=j;
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc3++;
			}
			v3.push_back({x,y});
        }
        for(int i=n-s-1;i>s+1;i--)
        {
        	x=i;y=s+1;
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc3++;
			}
			v3.push_back({x,y});
        }
        n1-=2;
        s++;
    }
    if(n1==1)
    {
        for(int j=s;j+s<m;j++)
        {
        	x=s+1;y=j+1;
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc3++;
			}
			v3.push_back({x,y});
        }
    }
    n1=n;
    maxi=a[0][0];
    s=0;
    while(n1>1)
    {
        for(int i=s;i+s<n;i++)
        {
        	x=i+1;y=s+1;
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc4++;
			}
			v4.push_back({x,y});
        }
        for(int j=s+1;j+s<m && n>s;j++)
        {
        	x=n-s;y=j+1;
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc4++;
			}
			v4.push_back({x,y});
        }
        for(int i=n-s-1;i>s;i--)
        {
        	x=i;y=m-s;
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc4++;
			}
			v4.push_back({x,y});
        }
        for(int j=m-s-1;j>s+1;j--)
        {
        	x=s+1;y=j;
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc4++;
			}
			v4.push_back({x,y});
        }
        n1-=2;
        s++;
    }
    if(n1==1)
    {
        for(int j=s;j+s<m;j++)
        {
        	x=s+1;y=j+1;
            if(a[x-1][y-1]>maxi)
			{
				maxi=a[x-1][y-1];sc4++;
			}
			v4.push_back({x,y});
        }
    }
	if(sc1<sc2 && sc1<sc3 && sc1<sc4)
    {
	    for(int i=0;i<(n*m);i++)
		    cout<<v1[i].first<<" "<<v1[i].second<<"\n";
    }
	else if(sc2<sc3 && sc2<sc4)
	{
		for(int i=0;i<(n*m);i++)
			cout<<v2[i].first<<" "<<v2[i].second<<"\n";
	}
	else if(sc3<sc4)
	{
		for(int i=0;i<(n*m);i++)
			cout<<v3[i].first<<" "<<v3[i].second<<"\n";
	}
	else
	{
		for(int i=0;i<(n*m);i++)
			cout<<v4[i].first<<" "<<v4[i].second<<"\n";
	}
     	/*for(int i=0;i<(n*m);i++)
			cout<<v4[i].first<<" "<<v4[i].second<<"\n";*/
}