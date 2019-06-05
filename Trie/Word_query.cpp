#include<bits/stdc++.h>
using namespace std;
struct TrieNode { 
    struct TrieNode* children[26];  
    bool isEnd;
    int cnt;
}; 
struct TrieNode* getNode() 
{ 
    struct TrieNode* pNode = new TrieNode; 
    pNode->isEnd = false; 
    pNode->cnt=0;
    for (int i = 0; i < 26; i++) 
        {
            pNode->children[i] = NULL; 
        }
    return pNode; 
} 
void insert(struct TrieNode* root, string key) 
{ 
    struct TrieNode* pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
        if (i == key.length() - 1) 
            {
                pCrawl->children[index]->isEnd = true;
                pCrawl->children[index]->cnt++;
            } 
        pCrawl = pCrawl->children[index]; 
    }
}
int search(struct TrieNode* root, string key) 
{ 
    struct TrieNode* pCrawl = root; 
    int ans = -1; 
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            break;  
        pCrawl = pCrawl->children[index];
        if(i==key.length()-1)
        {
                ans=pCrawl->cnt;
        } 
    } 
    return ans; 
} 
int dfs(struct TrieNode* node)
{
	for(int i=0;i<26;i++)
    {
        if(node->children[i])
            node->cnt = node->cnt + dfs(node->children[i]);
    }
    return node->cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct TrieNode* root = getNode(); 
	int n,q;string s;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s;insert(root,s);
	}
	dfs(root);
	while(q--)
	{
		cin>>s;
		int rez=search(root,s);
		if(rez==-1)
		    rez=0;
		cout<<rez<<"\n";
	}
	return 0;
}
