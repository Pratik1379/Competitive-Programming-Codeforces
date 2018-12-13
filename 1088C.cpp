#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<pair<int,int>>p;
    int tmp;
    int u=0;
    for(int i=n-1;i>=0;i--)
    {
            a[i]+=u;
	 		      tmp = a[i]%n;
	 		if(tmp <= i)
            {
                p.push_back(make_pair(i,i-tmp));
                u+=i-tmp;
            }
	 		else
            {
                p.push_back(make_pair(i,n+i-tmp));
                u+=n+i-tmp;
            }
    }
    cout<<n+1<<endl;
    for(int i=0;i<n;i++)
        cout<<1<<" "<<p[i].first+1<<" "<<p[i].second<<endl;
    cout<<2<<" "<<n<<" "<<n<<endl;
}
