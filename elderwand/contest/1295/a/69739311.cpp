#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string str = "";
        if(n & 1) {
            n -= 3;
            str += "7";
        }
        for(int i = 2; i <= n; i+=2) {
            str += '1';
        }
        cout << str << endl;
    }
    return 0;
}