#include<bits/stdc++.h>
#define mod 1000000007
#define pii pair<int,int>
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--) {
        string a;
        string b;
        cin >> a >> b;
        int mask = 0, rask = 0;
        for(char ch : a) {
            int id = ch - 'a';
            mask |= (1 << id);
        }
        for(char ch : b) {
            int id = ch - 'a';
            rask |= (1 << id);
        }
        if(mask & rask) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}