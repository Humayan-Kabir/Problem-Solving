#include <bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
map< pair<int,int>, int> maping;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    LL n, k;
    cin >> n >> k;
    LL total = k * (k - 1);
    if(total < n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= k; i++) {
        for(int j = i + 1; j <= k; j++) {
            if(n == 0) break;
            if(maping.find(make_pair(i,j)) == maping.end()) {
                cout << i <<" " <<j << endl;
                n--;
                if(n > 0) {
                    cout << j << " " << i << endl;
                    n--;
                    maping[make_pair(j,i)] = 1;
                }
                maping[make_pair(i,j)] = 1;
            }
        }
        if(n == 0) break;
    }
    return 0;
}