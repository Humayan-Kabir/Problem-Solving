#include<bits/stdc++.h>
#define mx 100007
using namespace std;
struct trie
{
    int ara[26], leaf = 0;
    trie() {}
} tree[mx];
void Insert(string &str, int &newNode)
{
    int curNode = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(tree[curNode].ara[str[i] - 'a']) curNode = tree[curNode].ara[str[i] - 'a'];
        else
        {
            tree[curNode].ara[str[i] - 'a'] =  ++newNode;
            curNode = newNode;
        }
    }
    tree[curNode].leaf = 1;
}
multiset<int> Merge(multiset<int> a,multiset<int> b)
{
    if(a.size() < b.size()) swap(a,b);
    for(int x : b) a.insert(x);
    return a;
}
multiset<int> dfs(int curNode,int level)
{
    multiset<int> SET;
    for(int i = 0; i < 26; i++)
    {
        if(tree[curNode].ara[i])
            SET = Merge(SET, dfs(tree[curNode].ara[i], level + 1));

    }
    if(tree[curNode].leaf) SET.insert(level);
    else if(level)
    {
        SET.erase(--SET.end());
        SET.insert(level);
    }
    return SET;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n, node = 0;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        Insert(str, node);
    }
    multiset<int> ans = dfs(0,0);
    cout << accumulate(ans.begin(),ans.end(), 0) << endl;
    return 0;
}
