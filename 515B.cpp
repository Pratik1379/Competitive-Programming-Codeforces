#include<bits/stdc++.h>
using namespace std;
bool boy[101]={false};
bool girl[101]={false};
int main()
{
    int n,m;
    cin>>n>>m;
    int g,h,x;
    cin>>g;
    for(int i=0;i<g;i++)
    {
        cin>>x;boy[x]=true;
    }
    cin>>h;
    for(int i=0;i<h;i++)
    {
        cin>>x;girl[x]=true;
    }
    int j=0;
    int fl=0;
    while(1)
    {
        fl=0;
        for(int i=1;i<=n;i++)
        {
            if(boy[i] && !girl[j])
            {
                girl[j]=true;fl=1;
            }
            else if(girl[j] && !boy[i])
            {
                boy[i]=true;fl=1;
            }
            j=(j+1)%m;
        }
        if(fl==0)
            break;
    }
    int found=0;
    for(int i=1;i<=n;i++)
    {
        if(!boy[i])
        {
            found=1;break;
        }
    }
    if(found)
        cout<<"NO";
    else
    {
        for(int i=1;i<=m;i++)
        {
        if(!girl[i])
        {
            found=1;break;
        }
        }
        if(found)
        cout<<"NO";
        else
        cout<<"YES";
    }
    return 0;
}
