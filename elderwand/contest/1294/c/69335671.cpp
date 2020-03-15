#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int finddivisors(int num, int minimum) {
    int root = sqrt(num);
    for(int i = minimum; i <= root; i++) {
        if(num % i == 0) return i;
    }
    return 1e9 + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int num;
        cin >> num;
        int a, b, c;
        a = finddivisors(num, 2);
        num /= a;
        b = finddivisors(num, a + 1);
        num /= b;
        c = num;
        if(num == 0 || c == a || c == b || a == b) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}