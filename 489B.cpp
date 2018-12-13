#include<bits/stdc++.h>
using namespace std;
int n,m;
bool bpGraph[101][101];
bool seen[101]={false};
int matchR[101];
bool bpm(int u)
{
    for (int v = 0; v < n; v++)
    {
        // If applicant u is interested in
        // job v and v is not visited
        if (bpGraph[u][v]  && !seen[v])
        {
            // Mark v as visited
            seen[v] = true;

            // If job 'v' is not assigned to an
            // applicant OR previously assigned
            // applicant for job v (which is matchR[v])
            // has an alternate job available.
            // Since v is marked as visited in
            // the above line, matchR[v] in the following
            // recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(matchR[v]))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number
// of matching from M to N
int maxBPM()
{
    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < m; u++)
    {
        memset(seen, 0, sizeof(seen));
        if (bpm(u))
            result++;
    }
    return result;
}
int main()
{
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(abs(a[i]-b[j])<=1)
            {
                bpGraph[j][i]=true;
            }
        }
    }
    cout<<maxBPM();
}
