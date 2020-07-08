/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: zyxw
 * Time: 2020-06-20 21:18:24
 * SUST-15
**/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
void fun1() {
    cout << "Ashishgup" << endl;
} 
void fun2() {
    cout << "FastestFinger" << endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) {
            fun2(); continue;
        } 
        if(n == 2) {
            fun1(); continue;
        }
        if(n & 1) {
            fun1(); continue;
        }
        int odd = 0, even = 0, root = sqrt(n);
        for(int i = 2; i <= root; i++) {
            while(n % i == 0) {
                if(i & 1) odd++;
                else even++;
                n = n / i;
            }
        }
        if(n > 1) {
            if(n & 1) odd++;
            else even++;
        }
        if(odd == 0) {
            fun2();
        } else {
            if(even >= 2) {
                fun1();
            } else {
                if(odd <= 1) {
                    fun2();
                } else {
                    fun1();
                }
            }
        }
    }
    return 0;
}