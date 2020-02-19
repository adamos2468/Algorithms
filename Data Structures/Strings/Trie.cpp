#include<bits/stdc++.h>

using namespace std;

struct node{
    int child[26];
    bool isWord;
};

void add(vector<node>& trie, string s){
    int trieIdx=0;
    for(auto x:s){
        if(trie[trieIdx].child[x-'a']==0){
            trie[trieIdx].child[x-'a']=trie.size();
            trie.push_back(node());
        }
        trieIdx=trie[trieIdx].child[x-'a'];
    }
    trie[trieIdx].isWord=true;
}

bool find(vector<node>& trie, string s){
    int trieIdx=0;
    for(auto x:s){
        if(trie[trieIdx].child[x-'a']==0)
            return false;
        trieIdx=trie[trieIdx].child[x-'a'];
    }
    return trie[trieIdx].isWord;
}

void remove(vector<node>& trie, string s){
    int trieIdx=0;
    for(auto x:s){
        if(trie[trieIdx].child[x-'a']==0)
            return;
        trieIdx=trie[trieIdx].child[x-'a'];
    }
    trie[trieIdx].isWord=false;
}

int main(){
    vector<node> trie;
    trie.push_back(node());
    add(trie, "anna");
    add(trie, "anne");    
    cout<<find(trie, "anne");
    remove(trie, "anna");
}