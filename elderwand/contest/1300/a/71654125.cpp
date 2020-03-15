#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t; 
    while(t--) {
        int n, sum = 0, zero = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int num; cin >> num;
            sum += num; zero += (num == 0);
        }
        cout << zero + ((sum + zero) == 0) << endl;
    }
    return 0;
}