#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n;
		map<int,int> m;
		set< int,greater<int> > se;
		int req=n/2;
		for(int i=0;i<n;i++)
		{	
			cin>>x;
			if(m.count(x)==0)
			{
				m.insert({x,1});
				se.insert(x);
			}
			else
				m[x]++;
		}
		if(se.size()<=2)
		{
			cout<<0<<" "<<0<<" "<<0<<endl;
			continue;
		}	
		int i=0;
		int g=0,s=0,b=0;
		int cnt=0;
		set< int,greater<int> >::iterator it;
		for(it=se.begin();it!=se.end();it++)
		{
			int y=*it;
			if(i==0)
			{
				cnt+=m[y];
				g=m[y];
			}
			else if(s<g)
			{
				cnt+=m[y];
				s+=m[y];
			}
			else if(cnt+m[y]<=req)
			{
				b+=m[y];
				cnt+=m[y];
			}
			else
				break;
			i++;
		}
		if(cnt>req || g==0 || s==0 || b==0 || s<g || b<g)
		{
			cout<<0<<" "<<0<<" "<<0<<endl;
			continue;
		}
		cout<<g<<" "<<s<<" "<<b<<endl;

	}
	return 0;
}