#include<bits/stdc++.h>
using namespace std;
#define mx 200002
typedef long long int LL;
namespace Trie {
    struct node {
        int child[2], childCounter;
        node() {}
    };
    node trie[32 * mx];
    int nodeCounter = 0;
    void insert(int val, int add, int root = 0) {
        for(int i = 31; i >= 0; i--) {
            bool b = val & (1 << i);
            if(!trie[root].child[b]) trie[root].child[b] = ++nodeCounter;
            root = trie[root].child[b];
            trie[root].childCounter += add;
        }
    }
    int query(int val, int root = 0, int ans = 0) {
        for(int i = 31; i >= 0; i--) {
            bool b = val & (1 << i);
            if(trie[trie[root].child[!b]].childCounter) {
                ans = ans | (1 << i);
                root = trie[root].child[!b];
            }
            else {
                root = trie[root].child[b];
            }
        }
        return ans;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    Trie::insert(0, 1);
    int q;
    cin >> q;
    while(q--) {
        char ch;
        int num;
        cin >> ch >> num;
        if(ch == '+') {
            Trie::insert(num, 1);
        }
        else if(ch == '-') {
            Trie::insert(num, -1);
        }
        else {
            cout << Trie::query(num) << endl;
        }
    }
    return 0;
}