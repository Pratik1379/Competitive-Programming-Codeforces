#include <bits/stdc++.h>
using namespace std;
long long int mod=1e9+7;
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y); 

// Function to find modulo inverse of a 
long long modInverse(long long int a, long long int m) 
{ 
	long long int x, y; 
	long long int g = gcdExtended(a, m, &x, &y); 
	long long int res = (x%m + m) % m; 
	return res; 
} 

// C function for extended Euclidean Algorithm 
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y) 
{ 
	// Base Case 
	if (a == 0) 
	{ 
		*x = 0, *y = 1; 
		return b; 
	} 

	long long int x1, y1; // To store results of recursive call 
	long long int gcd = gcdExtended(b%a, a, &x1, &y1); 

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b/a) * x1; 
	*y = x1; 

	return gcd; 
}
int main() 
{
	long long int n,a,b,c,h1,h2;
	cin>>n>>h1>>h2>>a>>b>>c;
	long long int dif = h2-h1;
	long long int fact=1;
	for(long long int i=2;i<=n;i++)
		fact=(fact*i)%mod;
	long long int ifact[n+1];
	ifact[n]=modInverse(fact,mod);
	for(long long int i=n-1;i>=0;i--)
	{
		ifact[i]=(ifact[i+1]*(i+1))%mod;
	}
	long long int ans=0;
	if(a==b && b==c)
	{
	    if(a==0)
	    {
	        if(dif==0)
	            cout<<1<<endl;
	        else
	            cout<<0<<endl;
	    }
	    else if(dif%a==0)
	        cout<<1<<endl;
	    else 
	        cout<<0<<endl;
	    return 0;
	}
	else if(a==b)
	{
		for(long long int i=0;i<=n;i++)
		{
			long long int k=(n-i);
			long long int tem=i*a+k*c;
    		if(tem==dif)
    		{
				ans=(ans+((((fact*ifact[i])%mod)*ifact[k])%mod))%mod;
			}
		}
		cout<<ans<<endl;return 0;
	}
	else if(b==c)
	{
		for(long long int i=0;i<=n;i++)
		{
			long long int k=(n-i);
			long long int tem=i*a+k*b;
    		if(tem==dif)
    		{
				ans=(ans+((((fact*ifact[i])%mod)*ifact[k])%mod))%mod;
			}
		}
		cout<<ans<<endl;return 0;
	}
	else if(a==c)
	{
		for(long long int i=0;i<=n;i++)
		{
			long long int k=(n-i);
			long long int tem=i*a+k*b;
    		if(tem==dif)
    		{
				ans=(ans+((((fact*ifact[i])%mod)*ifact[k])%mod))%mod;
			}
		}
		cout<<ans<<endl;return 0;
	}
	for(long long int i=0;i<=n;i++)
	{
		for(long long int j=0;j<=n;j++)
		{
			long long int k=(n-i-j);
			if(k>=0)
			{
			    //cout<<i<<" "<<j<<" "<<k<<endl;
    			long long int tem=i*a+j*b+k*c;
    			if(tem==dif)
    			{
    			    if(a==b && i<=j)
    			        ans=(ans+((((fact*ifact[i+j])%mod)*ifact[k])%mod))%mod;
    			    else if(b==c && j<=k)
    			        ans=(ans+((((fact*ifact[j+k])%mod)*ifact[i])%mod))%mod;
    			    else if(a==c && i<=k)
    			        ans=(ans+((((fact*ifact[i+k])%mod)*ifact[j])%mod))%mod;
    			    else if(a!=b && b!=c)
    			        ans=(ans+((((fact*ifact[i])%mod)*((ifact[j]*ifact[k])%mod))%mod))%mod;
    			   // cout<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;
    			}
			}
			else
			    break;
		}
	}
	cout<<ans<<endl;
}