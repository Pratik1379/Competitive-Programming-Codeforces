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
	ll n;
	cin>>n;
	ll a[n],b[n];
	FOR(i,n)
		cin>>a[i];
	FOR(i,n)
		cin>>b[i];
	LineContainer line;
	ll dp[n];
	dp[0]=0;
	line.add(-b[0],0);
	REP(i,1,n)
	{
		dp[i]=-line.query(a[i]);
		line.add(-b[i],-dp[i]);
	}
	cout<<dp[n-1];
	return 0;
}