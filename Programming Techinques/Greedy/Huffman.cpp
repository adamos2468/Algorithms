#include<iostream>
#include<string>
#include<vector>
#include<queue>
#define L 26
using namespace std;
struct huffNode{
    int val;
    char c;
    int left, right, id;
    bool operator<(const huffNode x) const
    {
        return (val>x.val);
    }
};
priority_queue<huffNode> huffQueue;
vector<huffNode> huffTree;
int pin[L];
string huffCode[L];
string cal;
huffNode merge(huffNode a, huffNode b, int id)
{
    huffNode temp;
    temp.c=0;
    temp.val=a.val+b.val;
    temp.left=a.id; temp.right=b.id;
    temp.id=id;
    return temp;
}
void getHuffCode(huffNode c)
{
    if(c.c!=0)
    {
        huffCode[c.c-'a']=cal;
        return;
    }
    cal.push_back('0');
    getHuffCode(huffTree[c.left]);
    cal.pop_back();
    cal.push_back('1');
    getHuffCode(huffTree[c.right]);
    cal.pop_back();
}
int main()
{
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++)
        pin[s[i]-'a']++;
    for(int i=0; i<L; i++)
    {
        huffNode temp;
        temp.val=pin[i];
        temp.c='a'+i;
        temp.left=temp.right=-1;
        if(pin[i]!=0){
            temp.id=huffTree.size();
            huffQueue.push(temp);
            huffTree.push_back(temp);
        }
    }
    while(huffQueue.size()>1)
    {
        huffNode a=huffQueue.top(); huffQueue.pop();
        huffNode b=huffQueue.top(); huffQueue.pop();
        huffNode temp=merge(a, b, huffTree.size());
        huffTree.push_back(temp);
        huffQueue.push(temp);
    }
    getHuffCode(huffTree[huffTree.size()-1]);
    for(int i=0; i<L; i++)
        if(!huffCode[i].empty())
           cout<<char(i+'a')<<": "<<huffCode[i]<<endl;
}