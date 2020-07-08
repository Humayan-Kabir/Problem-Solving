/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: ElderWand
 * Time: 2020-05-17 03:50:40
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
struct node {
    node *next[26];
    node() {
        for(int i = 0; i < 26; i++) next[i] = NULL;
    }
};
void insert(node *root, string &str) {
    node *current = root;
    for(char ch : str) {
        if(current->next[ch - 'a'] == NULL) {
            current->next[ch - 'a'] = new node();
        }
        current = current->next[ch - 'a'];
    }
}
int canLose(node *root) {
    int was = 1, leaf = 0;
    for(int i = 0; i < 26; i++) {
        if(root->next[i]) {
            was = min(was, 1 ^ canLose(root->next[i]));
            leaf = 1;
        }
    }
    return was & leaf;
}

int canWin(node *root) {
    int was = 0;
    for(int i = 0; i < 26; i++) {
        if(root->next[i]) {
            was = max(was, 1 ^ canWin(root->next[i]));
        }
    }
    return was;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    node *root = new node();
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        insert(root, str);
    }
    if(canWin(root) && !canLose(root)) {
        cout << "First" << endl;
    } else if(canWin(root)) {
        if(k & 1) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    } else {
        cout << "Second" << endl;
    }
    return 0;
}