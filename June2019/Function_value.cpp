#include <bits/stdc++.h>
using namespace std;
long long int dp[62],dp2[62];
long long int mod;
long long int power(long long int x, long long int y, long long int p) 
{ 
    long long int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
long long int find(long long int ser)
{
	if(ser==0)
		return 0;
	if(ser==1)
		return 1;
	long long int y1=log2(ser);
	long long int y2=dp[y1-1];
	long long int y3=pow(2LL,y1);
	long long int y4=power(9LL,y3,mod);
	y2=(y2+(y4*find(ser-y3))%mod)%mod;
	return y2;
}
long long int find2(long long int ser)
{
	if(ser==0)
		return 0;
	if(ser==1)
		return 1;
	long long int y1=log2(ser);
	long long int y2=dp2[y1-1];
	long long int y3=pow(2LL,y1);
	long long int y4=power(3LL,y3,mod);
	y2=(y2+(y4*find2(ser-y3))%mod)%mod;
	return y2;
}
long long int compute(long long int a)
{
	long long int nev=a/2;
	long long int nod=a-nev;
	//cout<<inv2<<"##"<<inv4<<endl;
	long long int sod=find2(nod);
	long long int sev=0;
	long long int tem=(nev/2);
//	cout<<nod<<endl;
    long long int tem3=1;
    long long int ans1=0;
    ans1=find(tem);
	if(nev&1)
	{
		sev=(((1+2*tem)%mod)+(((18*ans1)%mod)%mod))%mod;
	}
	else
	{
		sev=(((2*tem)%mod)+(((6*ans1)%mod)%mod))%mod;
	}
	//cout<<sev<<" "<<sod<<"**\n";
	long long int res=(sod+sev)%mod;
	return res;
}
void pre()
{
	long long int tem=81;
	dp[0]=10;
	for(int i=1;i<62;i++)
	{
		dp[i]=((1+tem)*dp[i-1])%mod;
		tem=(tem*tem)%mod;
		//cout<<dp[i]<<" ";
	}
	tem=9;
	dp2[0]=4;
	for(int i=1;i<62;i++)
	{
		dp2[i]=((1+tem)*dp2[i-1])%mod;
		tem=(tem*tem)%mod;
		//cout<<dp[i]<<" ";
	}
}
int main()
{
	long long int t;
	cin>>t>>mod;
	pre();
	while(t--)
	{
		long long int l,r;
		cin>>l>>r;
		if(mod==1)
		 {
		     cout<<0<<endl;continue;
		 }
		long long int an1=0,an2=0,ans;
		if(l!=1)
			an1=compute(l-1);
		an2=compute(r);
		//cout<<an1<<" "<<an2<<" ";
		ans=(an2-an1+mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}