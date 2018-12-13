#include<bits/stdc++.h>
using namespace std;
vector<int> a[200001];
int parent[200001];
bool vis[200001]={false};
bool vis2[200001]={false};
int main()
{
    int n;
    cin>>n;
    int x,y;
    int b[n];

    for(int i=1;i<n;i++)
    {
      cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    queue<int> Q;
    Q.push(1);
    vis[1]=true;
    parent[1]=0;
    while(!Q.empty())
    {
        int y=Q.front();
        Q.pop();
        for(unsigned int i=0;i<a[y].size();i++)
        {
            if(!vis[a[y][i]])
            {
                vis[a[y][i]]=true;
                parent[a[y][i]]=y;
                Q.push(a[y][i]);
            }
        }
    }
    while(!Q.empty())
        Q.pop();
    Q.push(1);
    int p=0;
    int fl=0;
    vis2[0]=true;
    for(int i=1;i<n;i++)
    {
        if(p==parent[b[i]])
            Q.push(b[i]);
        else
        {
            if(!vis2[parent[b[i]]])
            {
                while(parent[b[i]]!=Q.front() &&  !Q.empty())
                {
                    int r=Q.front();
                    vis2[r]=true;
                    Q.pop();
                }
                if(Q.empty())
                {
                    fl=1;break;
                }
                p=parent[b[i]];
                Q.pop();
                Q.push(b[i]);
                vis2[p]=true;
            }
            else
            {
                fl=1;break;
            }
        }
    }
    if(b[0]!=1)
    {
        fl=1;
    }
    if(fl==0)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
