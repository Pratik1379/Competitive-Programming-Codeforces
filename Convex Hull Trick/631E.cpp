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
	int n;
	cin>>n;
	ll a[n+1];
	LineContainer line1,line2;
	ll s[n+1];
	s[0]=0;
	ll res=0;
	FOR(i,n)
	{
		cin>>a[i+1];
		s[i+1]=s[i]+a[i+1];
		res+=a[i+1]*(i+1);
	}
	ll ans=res;
	//cout<<ans<<endl;
	line1.add(1,-s[0]);
	for(int i=2;i<=n;i++)
	{
		ll res1=line1.query(a[i]);
		ll res2=s[i-1]-i*a[i]+res+res1;
		ans=max(ans,res2);
		line1.add(i,-s[i-1]);
		//cout<<ans<<endl;
	}
	line2.add(n,-s[n]);
	for(int i=n-1;i>=1;i--)
	{
		ll res1=line2.query(a[i]);
		ll res2=s[i]-i*a[i]+res+res1;
		ans=max(ans,res2);
		line2.add(i,-s[i]);
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}