#include<bits/stdc++.h>
using namespace std;
struct TrieNode { 
    struct TrieNode* children[26];  
    bool isEnd; 
    int weight[26];
}; 
struct TrieNode* getNode(void) 
{ 
    struct TrieNode* pNode = new TrieNode; 
    pNode->isEnd = false; 
    for (int i = 0; i < 26; i++) 
        {
            pNode->children[i] = NULL; pNode->weight[i]=-1;
        }
    return pNode; 
} 
void insert(struct TrieNode* root, string key, int w) 
{ 
    struct TrieNode* pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
        if (i == key.length() - 1) 
            {
                pCrawl->children[index]->isEnd = true;
                pCrawl->weight[index] = w;
            } 
  
        pCrawl = pCrawl->children[index]; 
    } 
} 
int dfs(struct TrieNode* node)
{
    /*if(!node)
        return -1;*/
    
    for(int i=0;i<26;i++)
    {
        if(node->children[i])
            node->weight[i] = max(node->weight[i] ,dfs(node->children[i]));
    }
    int ret=-1;
    for(int i=0;i<26;i++)
        ret=max(ret,node->weight[i]);
    /*for(int i=0;i<26;i++)
        cout<<node->weight[i]<<" ";
    cout<<endl;*/
    return ret;
}
int search(struct TrieNode* root, string key) 
{ 
    struct TrieNode* pCrawl = root; 
  
    // Prefix of the string 
    int ans = -1; 
  
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            break;  
        pCrawl = pCrawl->children[index]; 
        if(i==key.length()-1)
        {
            for(int j=0;j<26;j++)
                ans=max(ans,pCrawl->weight[j]);
        }
    } 
    return ans; 
}  
void print(struct TrieNode* root)
{
    struct TrieNode* pCrawl = root; 
    for(int i=0;i<26;i++)
        if(root->weight[i]!=-1)
            cout<<root->weight[i]<<" "<<(char)(i+'a')<<"\t";
    cout<<endl;
    for(int i=0;i<26;i++)
    {
        if(root->children[i])
            print(root->children[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct TrieNode* root = getNode(); 
    int n,q,wy;string s;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>s>>wy;
        insert(root,s,wy);
    }
    dfs(root);
    //print(root);
    while(q--)
    {
        cin>>s;
        int pr=search(root,s);
        cout<<pr<<"\n";
    }
    return 0;
}
