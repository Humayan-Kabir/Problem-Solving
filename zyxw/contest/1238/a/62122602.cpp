#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    int t;
    cin >> t;
    while(t--) {
        LL a, b;
        cin >> a >> b;
        LL rem = a - b;
        if(rem == 1) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}