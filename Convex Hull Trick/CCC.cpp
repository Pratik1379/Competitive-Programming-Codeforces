#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) 	  for(int i=a;i<b;i++)
#define FOR(i,n) 	  for(int i=0;i<n;i++)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

/*Convex hull trick for maximum y at any given x*/ 
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main()
{
	IOS;TIE;
	int t;
	cin>>t;
	while(t--)
	{	
		ll n,z;
		cin>>n>>z;
		ll a[n+1];
		FOR(i,n)
			cin>>a[i+1];
		sort(a+1,a+n+1);
		/*if(n==z)
		{
		    ll sum=0;
		    FOR(i,n)
		        sum+=a[i+1];
		    cout<<sum<<endl;continue;
		}*/
		ll dp[n+1][z+1];
		FOR(i,n)
		{
		    dp[i+1][1] = (n-i)*a[i+1];
		}
		LineContainer m[z+1];
		for(int i=2;i<=z;i++)
		{
		    for(int j=n-i+2;j<=n;j++)
			{
				m[i].add(-j,-dp[j][i-1]);
			}
			for(int j=n-i+1;j>0;j--)
			{
			    //cout<<m.query(a[j])<<"**"<<a[j]<<endl;
				dp[j][i]=-m[i].query(a[j])-j*a[j];
				/*if(i==z)
				    cout<<m.query(a[j])<<" "<<a[j]<<endl;*/
				m[i].add(-j,-dp[j][i-1]);
			}
		}
		ll ans=1e18;
		/*for(int i=1;i<=z;i++)
		{
		    for(int j=1;j<=n-i+1;j++)
		        cout<<dp[j][i]<<" ";
		    cout<<endl;
		}*/
		for(int i=n-z+1;i>=1;i--)
		{
			ans=min(dp[i][z],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}