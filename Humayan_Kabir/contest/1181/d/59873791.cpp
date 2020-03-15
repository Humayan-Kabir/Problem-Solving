#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define mx 500007
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
LL preSum = 0, preCnt = 0;
int ans[mx], cnt[mx];
pair<int,int> ara[mx];
ordered_set X; 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i <= m; i++) {
        ara[i].first = cnt[i];
        ara[i].second = i;
    }
    sort(ara + 1, ara + m + 1);
    vector< pair<LL,int> > queries;
    for(int i = 0; i < q; i++) {
        LL x;
        cin >> x;
        queries.emplace_back(x, i + 1);
    }
    int curpos = 1;
    LL curMax = 0;
    sort(queries.begin(), queries.end());
    for(auto x : queries) {
        LL need = x.first - 1LL*n;
        while(curpos <= m && curMax < need) {
            int cnt = ara[curpos].first, actual = ara[curpos].second;
            if(cnt == 0) {
                X.insert(actual);
                curpos++; preCnt++;
                continue;
            }
            LL val = preCnt * 1LL * cnt - preSum;
            if(val >= need) {
                break;
            }
            else {
                curMax = max(curMax, val);
                X.insert(actual);
                preCnt++;
                preSum += cnt;
                curpos++;
            }
        }
        LL now = (need - curMax) % preCnt;
        int kth = now;
        if(kth == 0) kth = preCnt;
        //cout << *X.find_by_order(kth - 1) << endl;
        ans[x.second] = *X.find_by_order(kth - 1);
    }
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}