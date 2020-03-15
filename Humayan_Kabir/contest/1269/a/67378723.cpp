#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
string str;
int res[mx], vis[mx];
char st[mx];
int main() {
    int n;
    cin >> n;
    if(n % 2 == 0) {
        cout << 4 + n << " " << 4 << endl;
    } else {
        cout << 9 + n << " " << 9 << endl;
    }
    return 0;
}
