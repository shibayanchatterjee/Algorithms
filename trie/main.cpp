#include <iostream>
#include <cstdlib>
#include <string>
#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

struct TrieNode{
    bool isleaf;
    TrieNode *children[ALPHABET_SIZE];
};
TrieNode* getNode(void){
    TrieNode *pNode = new TrieNode;
    if (pNode){
        pNode -> isleaf = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            pNode -> children[i] = NULL;
    }
    return pNode;
}
void insert(TrieNode *node, string key){
    int length = key.length ();
    int level, index;
    TrieNode *pCrawl = node;
    for(level = 0; level < length; ++level){
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl -> children[index])
            pCrawl -> children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isleaf = false;
}
bool search(TrieNode *node, string key){
    int level, index;
    int length = key.length ();
    TrieNode *pCrawl = node;
    for(int level = 0; level < length; ++level){
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl -> children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL and pCrawl -> isleaf);
}
int main ( int argc, char** argv ) {
    bool cond;
    TrieNode *root = getNode();
    string word = "APPLE";
    insert(root, word);
    string key = "APPLE";
    cond = search(root, key);
    cout<<cond;
    return 0;
}

