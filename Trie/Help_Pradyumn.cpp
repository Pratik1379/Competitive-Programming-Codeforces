#include<bits/stdc++.h>
using namespace std;
struct TrieNode { 
    struct TrieNode* children[26];  
    bool isEnd; 
}; 
struct TrieNode* getNode(void) 
{ 
    struct TrieNode* pNode = new TrieNode; 
    pNode->isEnd = false; 
    for (int i = 0; i < 26; i++) 
        {
            pNode->children[i] = NULL; 
        }
    return pNode; 
} 
void print(struct TrieNode* node, string s)
{
    if(node->isEnd)
        cout<<s<<"\n";
    for(int i=0;i<26;i++)
    {
        if(node->children[i])
        {
            string temp = s + (char)(i+'a');
            print(node->children[i], temp);
        }
    }
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
            } 
        pCrawl = pCrawl->children[index]; 
    } 
} 
void search(struct TrieNode* root, string key) 
{ 
    struct TrieNode* pCrawl = root;  
  
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            {
                cout<<"No suggestions\n";
                insert(root,key);
                return;
            }
        pCrawl = pCrawl->children[index]; 
        if(i==key.length()-1)
        {
            print(pCrawl,key);
        }
    } 
}  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct TrieNode* root = getNode(); 
    int n,q;string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        insert(root,s);
    }
    cin>>q;
    while(q--)
    {
        cin>>s;
        search(root,s);
    }
    return 0;
}
