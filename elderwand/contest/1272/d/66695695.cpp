#include<bits/stdc++.h>
#define mod 1000000007
#define mx 300007
using namespace std;
typedef long long int LL;
int arr[mx], prefix[mx], suffix[mx];
int main() { 
    ios_base::sync_with_stdio(false);
    int n, ans = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            prefix[i] = 1;
            continue;
        }
        if(arr[i] > arr[i - 1]) {
            prefix[i] = prefix[i - 1];
        } else {
            prefix[i] = i;
        }
        ans = max(ans, i - prefix[i] + 1);
    }

     for(int i = n; i >= 1; i--) {
        if(i == n) {
            suffix[i] = n;
            continue;
        }
        if(arr[i] < arr[i + 1]) {
            suffix[i] = suffix[i + 1];
        } else {
            suffix[i] = i;
        }
        ans = max(ans, suffix[i] - i + 1);
    }

    for(int i = 2; i <= n - 1; i++) {
        if(arr[i - 1] < arr[i + 1]) ans = max(ans, suffix[i + 1] - i + i - prefix[i - 1]);
    }
    cout << ans << endl;
    return 0;
}