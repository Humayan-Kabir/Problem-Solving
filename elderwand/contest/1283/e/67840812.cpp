#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
struct node {
    LL dist, origin, limit, direction;
    node(LL a, LL b, LL c, LL d) {
        dist = a; origin = b; limit = c; direction = d;
    }
    bool operator < (const node &a) const {
        return dist > a.dist;
    } 
};
priority_queue<node> pq;
vector<int> vt;
vector<LL> res;
map<int,int> maping;
int flag[300000];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n; 
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        maping[num]++;
    }
    for(auto it : maping) {
        int x = it.first;
        if(flag[x - 1] == 0) {
             flag[x - 1] = 1;
             maping[x]--;
        }
        if(flag[x] == 0 && maping[x] > 0) {
            flag[x] = 1; maping[x]--;
        }
        if(flag[x + 1] == 0 && maping[x] > 0) {
            flag[x + 1] = 1; maping[x]--;
        } 
    }
    int ans = 0, ans2 = 0;
    for(int i = 0; i <= 200007; i++) {
        ans += flag[i];
    }
	memset(flag, 0, sizeof flag);
	for(auto v : maping) {
		if(flag[v.first - 1] || flag[v.first] || flag[v.first + 1] ) continue;
		flag[v.first + 1] = 1;
		ans2++;
	}
	cout << ans2 << " " << ans << endl;
    return 0;
}