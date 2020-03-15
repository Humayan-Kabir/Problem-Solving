#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    //ios_base::sync_with_stdio(false);
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int n;
        scanf("%d", &n);
        multiset<int> mset;
        for(int i = 1; i <= n; i++) {
            int val;
            scanf("%d", &val);
            mset.insert(val);
        }
        int flag = 0;
        while(mset.size() > 0) {
            int v, u = *mset.begin();
            if(u == 2048) flag = 1;
            if(u > 2048) break; 
            mset.erase(mset.find(u));
            if(mset.size() > 0) {
                v = *mset.begin();
                mset.erase(mset.find(v));
                if(u == v) {
                    mset.insert(u + u);
                }
                else {
                    mset.insert(v);
                }
            }   
        }
        if(flag) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
