#include <bits/stdc++.h>
using namespace std;
vector<long long int> a[100005];
int ind=-1;
int n;
int y;long long int z;
double pro1,pro2;
double eps=0.00000001;
void pre()
{
	if(a[0][0]>a[n-1][0])
	{
		pro1=-1;pro2=(a[n-1][0]*1.0)/(a[0][0]*1.0);
	}
	else
	{
		pro2=-1;pro1=(a[0][0]*1.0)/(a[n-1][0]*1.0);
	}
	int i=0,j=n-1,l=1,k=1;
	while(i+1<j)
	{
	   // cout<<pro1<<" "<<pro2<<endl;
		if(pro1==-1)
		{
			if(l<a[j].size())
			{
				pro2=pro2*(a[j][l]*1.0);
				l++;
			}
			else
			{
				j--;
				pro2=pro2*(a[j][0]*1.0);
				l=1;
			}
			if(pro2>1)
			{
				pro1=1/pro2;
				pro2=-1;
			}
		}
		else
		{	
			if(k<a[i].size())
			{
				pro1=pro1*(a[i][k]*1.0);
				k++;
			}
			else
			{
				i++;
				pro1=pro1*(a[i][0]*1.0);
				k=1;
			}
			if(pro1>1)
			{
				pro2=1/pro1;
				pro1=-1;
			}
		}
	}
	ind=i;
}
void compute()
{
	if(y==ind)
	{
		if(pro1==-1)
		{
			pro2=pro2/z;
		}
		else
		{
			pro1=pro1*z;
			if(pro1>1)
			{
				pro2=1/pro1;
				pro1=-1;
			}
		}
	}
	else if(y==(ind+1))
	{
		if(pro2==-1)
		{
			pro1=pro1/z;
		}
		else
		{
			pro2=pro2*z;
			if(pro2>1)
			{
				pro1=1/pro2;
				pro1=-1;
			}
		}
	}
	else if(abs(pro1-1)<eps || abs(pro2-1)<eps)
	{
	    if(y<ind)
	    {
	        pro2=-1;pro1=z;
	        double temp1=pro1;
			double temp2=1/pro1;
			double last=temp1;
			int j=ind;
			int fl=0;
			while(j>y)
			{	
				for(int u=0;u<a[j].size();u++)
				{
					temp1=(temp1/a[j][u]);
					if(temp1<temp2)
					{
						fl=1;break;
					}
					temp1=temp1/a[j][u];
					if(temp1<temp2)
					{
						fl=1;break;
					}
				}
				if(fl==1)
				{
					ind=j;
					break;
				}
				if(temp1<=1)
				{
					if(abs(temp1-1)<=abs((1/last)-1))
					{
						pro1=temp1;ind=j-1;
					}
					else
					{
						pro1=last;ind=j;
					}
					break;
				}
				j--;
				pro1=temp1;
				last=temp1;
				if(j==y)
				{
					ind=y;
				}
			}
			if(pro1>1)
			{
				pro2=1/pro1;pro1=-1;
			}
	    }
	    else
	    {
	    	pro1=-1;pro2=z;
	   		double temp1=pro2;
			double temp2=1/pro2;
			double last=temp1;
			int i=ind+1;
			int fl=0;
			while(i<y)
			{	
				for(int u=0;u<a[i].size();u++)
				{
					temp1=(temp1/a[i][u]);
					if(temp1<temp2)
					{
						fl=1;break;
					}
					temp1=temp1/a[i][u];
					if(temp1<temp2)
					{
						fl=1;break;
					}
				}
				if(fl==1)
				{
					ind=i-1;
					break;
				}
				if(temp1<=1)
				{
					if(abs(temp1-1)<abs((1/last)-1))
					{
						pro2=temp1;ind=i;
					}
					else
					{
						pro2=last;ind=i-1;
					}
					break;
				}
				i++;
				pro2=temp1;
				last=temp1;
				if(i==y)
				{
					ind=i-1;
				}
			}
			if(pro2>1)
			{
				pro1=1/pro2;pro2=-1;
			}	
	    }
	}
	else if(y<ind)
	{
		if(pro1==-1)
		{
		    //cout<<"**";
			pro2=pro2/z;
			double temp1=pro2;
			double temp2=pro2;
			double last=temp1;
			int j=ind;
			int fl=0;
			while(j>y)
			{
				for(int u=0;u<a[j].size();u++)
					{
						temp1=(temp1*a[j][u]);
						if((1/temp1)<temp2)
						{
							fl=1;break;
						}
						temp1=(temp1*a[j][u]);
						if((1/temp1)<temp2)
						{
							fl=1;break;
						}
					}
					if(fl==1)
					{
					    //cout<<"**"<<temp1<<" "<<temp2<<endl;
						ind=j;	
						break;
					}
					if(temp1>=1)
					{
					    //cout<<"**"<<temp1<<" "<<temp2<<endl;
						if(abs((1/temp1)-1)<=abs(last-1))
						{
							ind=j-1;pro2=temp1;
						}
						else
						{
							pro2=last;ind=j;
						}
						break;
					}
					j--;
					pro2=temp1;
					last=temp1;
					if(j==y)
					{
						ind=y;
					}
			}
			if(pro2>1)
			{
				pro1=1/pro2;pro2=-1;
			}
		}
		else
		{
			pro1=pro1*z;
			if(pro1>1)
			{
				double temp1=pro1;
				double temp2=1/pro1;
				double last=temp1;
				int j=ind;
				int fl=0;
				while(j>y)
				{	
					for(int u=0;u<a[j].size();u++)
					{
						temp1=(temp1/a[j][u]);
						if(temp1<temp2)
						{
							fl=1;break;
						}
						temp1=temp1/a[j][u];
						if(temp1<temp2)
						{
							fl=1;break;
						}
					}
					if(fl==1)
					{
						ind=j;
						break;
					}
					if(temp1<=1)
					{
						if(abs(temp1-1)<=abs((1/last)-1))
						{
							pro1=temp1;ind=j-1;
						}
						else
						{
							pro1=last;ind=j;
						}
						break;
					}
					j--;
					pro1=temp1;
					last=temp1;
					if(j==y)
					{
						ind=y;
					}
				}
				if(pro1>1)
				{
					pro2=1/pro1;pro1=-1;
				}
			}
		}
	}
	else
	{
		if(pro2==-1)
		{
			pro1=pro1/z;
			double temp1=pro1;
			double temp2=pro1;
			double last=temp1;
			int i=ind+1;
			int fl=0;
			while(i<y)
			{
				for(int u=0;u<a[i].size();u++)
					{
						temp1=(temp1*a[i][u]);
						if((1/temp1)<temp2)
						{
							fl=1;break;
						}
						temp1=(temp1*a[i][u]);
						if((1/temp1)<temp2)
						{
							fl=1;break;
						}
					}
					if(fl==1)
					{
						ind=i-1;	
						break;
					}
					if(temp1>=1)
					{
						if(abs((1/temp1)-1)<abs(last-1))
						{
							ind=i;pro1=temp1;
						}
						else
						{
							pro1=last;ind=i-1;
						}
						break;
					}
					i++;
					pro1=temp1;
					last=temp1;
					if(i==y)
					{
						ind=i-1;
					}
			}
			if(pro1>1)
			{
				pro2=1/pro1;pro1=-1;
			}
		}
		else
		{
			pro2=pro2*z;
			if(pro2>1)
			{
				double temp1=pro2;
				double temp2=1/pro2;
				double last=temp1;
				int i=ind+1;
				int fl=0;
				while(i<y)
				{	
					for(int u=0;u<a[i].size();u++)
					{
						temp1=(temp1/a[i][u]);
						if(temp1<temp2)
						{
							fl=1;break;
						}
						temp1=temp1/a[i][u];
						if(temp1<temp2)
						{
							fl=1;break;
						}
					}
					if(fl==1)
					{
						ind=i-1;
						break;
					}
					if(temp1<=1)
					{
						if(abs(temp1-1)<abs((1/last)-1))
						{
							pro2=temp1;ind=i;
						}
						else
						{
							pro2=last;ind=i-1;
						}
						break;
					}
					i++;
					pro2=temp1;
					last=temp1;
					if(i==y)
					{
						ind=i-1;
					}
				}
				if(pro2>1)
				{
					pro1=1/pro2;pro2=-1;
				}
			}
		}
	}
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int m,x;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>z;
		a[i].push_back(z);
	}
	pre();
	long long int m1=m;
	while(m--)
	{
		cin>>x;
		if(x==2)
		{
			cout<<ind+1<<endl;
		}
		else
		{
			cin>>y>>z;
			y--;
			a[y].push_back(z);
			if((m1*n)<=1000000)
			    pre();
			else
			    compute();
		    //cout<<pro1<<" "<<pro2<<endl;
		}
	}
	return 0;
}