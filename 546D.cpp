#include<bits/stdc++.h>
using namespace std;
int s[5000001];
int a[5000001];
long int dp[5000001];
void sieve()
{
    vector <bool> prime(5000001, false);
    for (int i=2; i<=5000000; i+=2)
        s[i] = 2;
    for (int i=3; i<=5000000; i+=2)
    {
        if (prime[i] == false)
        {
            s[i] = i;
            for (int j=i; j*i<=5000000; j+=2)
            {
                if (prime[i*j] == false)
                {
                    prime[i*j] = true;
                    s[i*j] = i;
                }
            }
        }
    }
}
void generat(int N)
{
    int curr = s[N];
    int cnt = 1;
    a[N]=0;
    while (N > 1)
    {
        N /= s[N];
        if (curr == s[N])
        {
            cnt++;
            continue;
        }
        a[N]+=cnt;
        curr = s[N];
        cnt = 1;
    }
}
int main()
{
    sieve();
    for(int i=2;i<=5000000;i++)
    {
        generat(i);
    }
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=5000000;i++)
    {
        dp[i]+=dp[i-1]+a[i];
    }
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        cout<<dp[x]-dp[y];
    }
    return 0;
}
