#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[10],b[10],d[100005],c[100005];
	int n=0;
	int i1=-1,i2=-1;
	int temp;
	for(int i=0;i<4;i++)
	{
		a[i]=0;b[i]=0;
		cin>>a[i];
		n+=a[i];
		b[i]=a[i];
		if(a[i]>0 && i1==-1)
			i1=i;
	}
	i2=i1+1;
	temp=i1;
	for(int j=0;j<n;j++)
	{
		if(j%2==0)
		{
			if(a[i1]==0)
			{
				while(i1<4 && (a[i1]==0 || i1==i2) )
					i1++;
			}
			d[j]=i1;
			a[i1]--;
		}
		else
		{
			if(a[i2]==0)
			{
				while(i2<4 && (a[i2]==0 || i1==i2) )
					i2++;
			}
			d[j]=i2;
			a[i2]--;
		}
		//cout<<j<<"**"<<d[j]<<endl;
	}
	
	//cout<<d[0]<<"**\n";

	i1=temp+1;
	i2=temp;
	for(int j=0;j<n;j++)
	{
		if(j%2==0)
		{
			if(b[i1]==0)
			{
				while(i1<4 && (b[i1]==0 || i1==i2) )
					i1++;
			}
			c[j]=i1;
			b[i1]--;
		}
		else
		{
			if(b[i2]==0)
			{
				while(i2<4 && (b[i2]==0 || i1==i2) )
					i2++;
			}
			c[j]=i2;
			b[i2]--;
		}
		/*for(int j=0;j<n;j++)
			cout<<j<<"**"<<c[j]<<"**"<<d[j]<<endl;
		cout<<"\n\n";*/
		
	}
	/*for(int j=0;j<n;j++)
		cout<<j<<"**"<<c[j]<<"**"<<d[j]<<endl;
	
	cout<<d[0]<<"##\n";*/
	
	int fl=0;
	for(int j=1;j<n;j++)
	{
		if(c[j]>=4 || abs(c[j]-c[j-1])!=1)
		{
			fl=1;break;
		}
	}
	if(fl==0 && c[0]<4)
	{
		cout<<"YES\n";
		for(int j=0;j<n;j++)
			cout<<c[j]<<" ";
		return 0;
	}
	fl=0;
	for(int j=1;j<n;j++)
	{
		if(d[j]>=4 || abs(d[j]-d[j-1])!=1)
		{
			fl=1;break;
		}
	}
	if(fl==0 && d[0]<4)
	{
		cout<<"YES\n";
		for(int j=0;j<n;j++)
			cout<<d[j]<<" ";
		return 0;
	}
	else
	{
		cout<<"NO\n";
		/*for(int j=0;j<n;j++)
			cout<<c[j]<<" ";
		cout<<endl;
		for(int j=0;j<n;j++)
			cout<<d[j]<<" ";*/
	}
	return 0;
}