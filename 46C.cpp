#include<bits/stdc++.h>
using namespace std;
vector<long long int> v;
map<long long int,int> m;
int main()
{
    int n;
    scanf("%d",&n);
    long long int x,y;
    long long int cont[200005]={0};
    for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&x,&y);
            y++;
            if(m.count(x))
                m[x]++;
            else
                m.insert(make_pair(x,1));
            if(m.count(y))
                m[y]--;
            else
                m.insert(make_pair(y,-1));
        }
        for(map<long long int ,int>::iterator it=m.begin();it!=m.end();++it)
            {
                v.push_back(it->first);
            }
        sort(v.begin(),v.end());
        int r1=v.size();
        long long int s=0;
        for(int i=0;i<r1;i++)
        {
            s+=m.at(v[i]);
            cont[s]+=(v[i+1]-v[i]);
        }
        for(int i=1;i<=n;i++)
            cout<<cont[i]<<" ";
    return 0;
}
