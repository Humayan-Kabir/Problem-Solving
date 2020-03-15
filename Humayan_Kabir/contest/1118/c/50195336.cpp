#include <bits/stdc++.h>
#define mx 300007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int n, ara[mx], cnt[mx], grid[21][21];
priority_queue < pair<int,int> > PQ;
bool check(int i, int j) {
    if(n % 2 == 0) return 1;
    int cur = (n+1) / 2;
    if(cur == i || cur == j) return 0;
    return 1;
} 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n * n; i++) {
        cin >> ara[i];
        cnt[ara[i]]++;
    }
    for(int i = 1; i <= 1000; i++) {
        if(cnt[i] > 0) PQ.push(make_pair(cnt[i], i));
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(grid[i][j] == 0 && check(i,j)) {
                int counter = PQ.top().first, val = PQ.top().second;
                PQ.pop();
                if(counter >= 4) {
                    counter -= 4;
                    grid[i][j] = grid[n - i + 1][j] = grid[i][n - j + 1] = grid[n - i + 1][n - j + 1] = val;
                }
                if(counter > 0) PQ.push(make_pair(counter, val));
            }
        }
    } 
    if(n & 1) {
        int x = (n + 1) / 2, y = (n + 1) / 2;
        for(int i = 1; i < y; i++) {
            int counter = PQ.top().first, val = PQ.top().second;
            PQ.pop();
            if(counter >= 2) {
                counter -= 2;
                grid[x][i] = grid[x][n - i + 1] = val;
            }
            if (counter > 0) PQ.push(make_pair(counter, val));
        }
        for(int i = 1; i < x ; i++) {
            int counter = PQ.top().first, val = PQ.top().second;
            PQ.pop();
            if(counter >= 2) {
                counter -= 2;
                grid[i][x] = grid[n - i + 1][x] = val;
            }
            if (counter > 0) PQ.push(make_pair(counter, val));
        }
        grid[x][x] = PQ.top().second;
    }
    int flag = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(grid[i][j] == 0) flag = 0;
        }
    }
    if(flag == 0) {
        cout << "NO" <<endl;
        return 0;
    }
    cout << "YES" << endl; 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j == 1) cout << grid[i][j];
            else cout << " " << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}