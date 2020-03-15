#include<bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL fibo[mx];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(__gcd(a, b) == 1) {
            cout << "finite" << endl;
        }
        else {
            cout << "infinite" << endl;
        }
    }
    return 0;
}