#include <bits/stdc++.h>
using namespace std;
long long int mod=1000000007;
long long int c1=166666668; //inverse of 6
long long int c2=41666667; //inverse of 24
bool prime[100001];vector<int> v;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          v.push_back(p); 
} 
int main() 
{
	int t;
	cin>>t;
	SieveOfEratosthenes(100000); 
	while(t--)
	{
		long long int n;
		cin>>n;
		if(n<4)
		{
		    cout<<0<<endl;continue;
		}
		long long int cnt1=(((((n*(n-1))%mod)*(n-2))%mod)*(n-3))%mod;
		long long int ans=0;
		cnt1 = (cnt1*c2)%mod;
		long long int cnt2=0;
		long long int cnt[n+1];
		for(int i=0;i<=n;i++)
			cnt[i]=0;
		for(int j=2;j<=n;j++)
		{
			long long int u = n/j;
			if(u<4)
				break;
			long long int y = (((((u*(u-1))%mod)*(u-2))%mod)*(u-3))%mod;
			y=(y*c2)%mod;
			cnt[j]=y;
			//cout<<cnt[j]<<" ";
		}
	//	cout<<endl;
		int r1=v.size();
		for(int i=n;i>=2;i--)
		{
			for(int j=0;j<r1 && ((i*v[j])<=n);j++)
			{
				cnt[i]=(cnt[i]-cnt[(i*v[j])]+mod)%mod;
				if(cnt[i*v[j]]==0)
				    break;
				/*if(i==2)
				    cout<<(i*v[j])<<"**";*/
			}
		}
		for(long long int j=2;j<=n;j++)
		{
			long long int tem = (((j*j)%mod)*((j*j)%mod))%mod;
			tem = (tem*cnt[j])%mod; 
			ans = (ans+tem)%mod;
			cnt2=(cnt2+cnt[j])%mod;
			//cout<<cnt[j]<<" ";
		}
		//cout<<endl;
		ans = (ans+cnt1-cnt2+mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}