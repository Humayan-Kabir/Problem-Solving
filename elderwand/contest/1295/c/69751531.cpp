#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        vector<int> vt[30];
        int len1 = a.length(), len2 = b.length();
        for(int i = 0; i < len1; i++) {
            vt[a[i] - 'a'].push_back(i);
        }
        int pre = 0, start = 1, flag = 1, ans = 0;
        for(int i = 0; i < len2 && flag; i++) {
            if(vt[b[i] - 'a'].size() == 0) {
                flag = 0;
                break;
            }
            if(start) {
                start = 0; ans++;
                pre = vt[b[i] - 'a'][0];
            } else {
                int sz = vt[b[i] - 'a'].size();
                if(vt[b[i] - 'a'][sz - 1] <= pre) {
                    ans++;
                    pre = vt[b[i] - 'a'][0];
                } else {
                    int low = 0, high = sz, to = pre;
                    while(low <= high) {
                        int mid = (low + high) / 2;
                        if(vt[b[i] - 'a'][mid] > pre) {
                            to = vt[b[i] - 'a'][mid];
                            high = mid - 1;
                        } else {
                            low = mid + 1;
                        }
                    }
                    pre = to;
                }
            }
        }
        if(!flag) ans = -1;
        cout << ans << endl;
    }
    return 0;
}