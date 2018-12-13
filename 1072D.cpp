#include<bits/stdc++.h>
using namespace std;
string h="";
string s[2001];
int n;
void dfs(int x,int y)
{
  //cout<<h<<endl;
    h=h+s[x][y];
    string temp1=h;
    if(x+1<n)
        dfs(x+1,y);
    string temp2=h;

    if(y+1<n)
     {
       h=temp1;
        dfs(x,y+1);
      if(temp2<h && h.length()==temp2.length())
        h=temp2;
     }

}
int main()
{
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>s[i];
    int dp[n][n];
    if(s[0][0]=='a')
        dp[0][0]=0;
    else
        dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        if(s[i][0]=='a')
            dp[i][0]=dp[i-1][0];
        else
            dp[i][0]=dp[i-1][0]+1;
    }
    for(int i=1;i<n;i++)
    {
        if(s[0][i]=='a')
            dp[0][i]=dp[0][i-1];
        else
            dp[0][i]=dp[0][i-1]+1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(s[i][j]=='a')
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
        }
    }
    int x=0,y=0,maxi=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[i][j]<=k && maxi<=(i+j))
            {
                maxi=i+j;
                x=i;
                y=j;
            }
        }
    }
    int l=maxi+1;
    //cout<<l<<endl;
    while(l>0)
    {
        h=h+"a";
        l--;
    }
    string temp1=h;
    if(x+1<n)
        dfs(x+1,y);
    string temp2=h;
    if(y+1<n)
      {

         h=temp1;
         dfs(x,y+1);
        if(temp2<h && h.length()==temp2.length())
        h=temp2;
      }
    /*while(x<n && y<n)
    {
        if((x+1)>n && (y+1)>n)
            break;
        if(x+1<n && y+1<n)
        {
            if(s[x+1][y]<s[x][y+1])
                {
                    h=h+s[x+1][y];
                    x++;
                }
            else
                {
                    h=h+s[x][y+1];
                    y++;
                }
        }
        else if(x+1<n)
        {
            h=h+s[x+1][y];
            x++;
        }
        else
        {
            h=h+s[x][y+1];
            y++;
        }
    }*/
    cout<<h<<endl;
}
