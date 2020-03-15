#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    LL n;
    cin >> n;
    LL root = sqrt(n);
    if(n == 1) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    vector<LL> vt;
    for(LL i = 2; i <= root; i++) {
        if(n % i != 0) continue;
        LL cnt = 0, p = 1;
        while(n > 0 && n % i == 0) {
            n = n / i;
            p = p * i;
        }
        vt.push_back(p);
    }
    if(n >= 2) {
        vt.push_back(n);
    }
    int sz = vt.size();
    LL res = 1e17, a = 1, b = 1;
    for(int i = 0; i < (1 << sz); i++) {
        LL num1 = 1, num2 = 1;
        for(int j = 0; j < sz; j++) {
            if(i & (1 << j)) {
                num1 *= vt[j];
            } else {
                num2 *= vt[j];
            }
        }

        if(max(num2, num1) < res) {
            res = max(num1, num2);
            a = num1; b = num2;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}