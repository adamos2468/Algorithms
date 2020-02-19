#include<bits/stdc++.h>

using namespace std;

struct node{
    int child[26]={};
    bool isWord=false;
    int papa=-1, suffix=-1;
    char ch;
    string word;
    node(int papa=-1, char ch='#'){
        this->papa=papa;
        this->ch=ch;
        memset(child, -1, sizeof child);
    }
};

void add(vector<node>& trie, string s){
    int trieIdx=0;
    for(auto x:s){
        if(trie[trieIdx].child[x-'a']==-1){
            trie[trieIdx].child[x-'a']=trie.size();
            trie.push_back(node(trieIdx, x));
        }
        trieIdx=trie[trieIdx].child[x-'a'];
    }
    trie[trieIdx].isWord=true;
    trie[trieIdx].word=s;
}

int go(vector<node>& trie, int v, char c);

int get_link(vector<node>& trie, int v){
    if (trie[v].suffix == -1) {
        if (v == 0 || trie[v].papa == 0)
            trie[v].suffix = 0;
        else
            trie[v].suffix = go(trie, get_link(trie, trie[v].papa), trie[v].ch);
    }
    return trie[v].suffix;
}

int go(vector<node>& trie, int v, char c){
    if (trie[v].child[c-'a'] == -1) 
        trie[v].child[c-'a'] = (v == 0 ? 0 : go(trie, get_link(trie, v), c));
    return trie[v].child[c-'a'];
}

set<int> vis;
set<string> found;
void addSolution(vector<node>& trie, int v){
    vis.insert(v);
    if(trie[v].isWord)
        found.insert(trie[v].word);
    int q=get_link(trie, v);
    if(!vis.count(q))
        addSolution(trie, q);
}

int main(){
    vector<node>trie(1);
    vector<string> seira;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        add(trie, s);
        seira.push_back(s);
    }
    string hay;
    int u=0;
    cin>>hay;
    for(auto x:hay){
        u=go(trie, u, x);
        addSolution(trie, u);
    }
    for(auto x:seira){
        if(found.count(x))
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }
}