    #include<bits/stdc++.h>
    #define mx 300007
    using namespace std;
    typedef long long int LL;
    pair<LL,int> ara[mx];
    map<LL,int> maping;
    int main() {
        ios_base::sync_with_stdio(false);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            LL num;
            cin >> num;
            ara[i] = make_pair(num, i);
        }
        if(n <= 3) {
            cout << 1 << endl;
            return 0;
        }
        sort(ara + 1, ara + n + 1);
        for(int i = 2; i <= n; i++) {
            LL d = ara[i].first - ara[i - 1].first;
            maping[d]++;
        }
        int flag = 0, ans;
        for(int i = 2; i < n; i++) {
            LL d1 = ara[i].first - ara[i - 1].first, d2 = ara[i + 1].first - ara[i].first;
            maping[d1]--;
            maping[d2]--;
            LL d3 = ara[i + 1].first - ara[i - 1].first;
            maping[d3]++;
            if(maping[d3] == n - 2) {
                flag = 1; ans = ara[i].second;
                break;
            }
            maping[d3]--;
            maping[d1]++;
            maping[d2]++;
        }
        if(flag) {
            cout << ans << endl;
            return 0;
        }
        LL d1 = ara[3].first - ara[2].first, d2 = ara[2].first - ara[1].first;
        int foo = 0, boo = 0;
        for(int i = 3; i <= n; i++) {
            LL dx = ara[i].first - ara[i - 1].first;
            if(dx != d1) {
                foo = 1;
            }
        }
        if(foo == 0) {
            cout << ara[1].second << endl;
            return 0;
        }
        for(int i = 2; i < n; i++) {
            LL dx = ara[i].first - ara[i - 1].first;
            if(dx != d2) {
                boo = 1;
            }
        }
        if(boo == 0) {
            cout << ara[n].second << endl;
            return 0;
        }
        cout  << -1 << endl;
        return 0;
    }