#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int n;string s,t;
	cin>>n>>s>>t;
	int fl=n;
	for(int i=0;i<n;i++)
	{
		string s1=s.substr(i,n-i);
		string t1=t.substr(0,n-i);
		if(s1==t1)
		{
			fl=i;break;
		}
	}
	cout<<fl;
	return 0;
}