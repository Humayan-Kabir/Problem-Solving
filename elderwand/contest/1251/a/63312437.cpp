#include<bits/stdc++.h>
#define mod 1000000007
#define mx 300007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
int ara[27], mark[27];
int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        memset(mark, 0, sizeof mark);
        memset(ara, 0, sizeof ara);
        char ch = str[0];
        int cnt = 0;
        for(int i = 0; i < str.length(); i++) {
            int id = ch - 'a';
            mark[id] = 1;
            if(str[i] == ch) {
                cnt++;
            }
            else {
                if(cnt % 2 == 1) {
                    ara[id] = 1;
                }
                ch = str[i];
                cnt = 1;
            }
        }
        if(cnt % 2 == 1) {
            mark[ch - 'a'] = 1;
            ara[ch - 'a'] = 1;
        }
        for(int i = 0; i < 26; i++) {
            if(mark[i] && ara[i]) {
            char ch = 'a' + i;
            cout << ch;
            }
        }
        cout << endl;
    }    
    return 0;
}