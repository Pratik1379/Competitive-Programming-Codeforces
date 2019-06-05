#include<bits/stdc++.h>
using namespace std;
struct TrieNode { 
    struct TrieNode* children[36];  
    bool isEnd;
}; 
struct TrieNode* getNode(void) 
{ 
    struct TrieNode* pNode = new TrieNode; 
    pNode->isEnd = false; 
    for (int i = 0; i < 26; i++) 
        {
            pNode->children[i] = NULL; pNode->cnt=-2;
        }
    return pNode; 
} 
int insert(struct TrieNode* root, string key, int w) 
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
    return pCrawl->count;
}
int main()
{

	return 0;
}
