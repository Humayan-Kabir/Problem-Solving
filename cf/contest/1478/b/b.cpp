#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int q, d;
        cin >> q >> d;
        auto check = [=] (int num) -> bool{
            while(num) {
                int rem = num % 10;
                if(rem == d) return 1;
                num /= 10;
            }
            return 0;
        };
        while(q--) {
            int num;
            cin >> num;
            int found = check(num);
            int repeat = num / d;
            if(repeat >= 10) {
                found = found | true;
            } else {
                for(int i = 0; i * d <= num; i++) {
                    int rem = num - i * d;
                    found = found | check(rem);
                }
            }
            found ? cout << "YES" << endl : cout << "NO" << endl;
        }
    }
}