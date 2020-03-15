#include<bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int grid[1007][1007], grid2[1007][1007], x[mx], y[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    for(int i = 1; i <= h; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= w; i++) {
        cin >> y[i];
    }
    for(int i = 1; i <= 1001; i++) {
        for(int j = 1; j <= 1001; j++) {
            grid[i][j] = INT_MAX;
        }
    }
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(j <= x[i]) {
                grid[i][j] = 1;
            }
            else if(j == (x[i] + 1)) {
                grid[i][j] = 2;
            }
            else {
                grid[i][j] = 3;
            }
        }
    }
    int flag = 0;
    for(int j = 1; j <= w; j++) {
        for(int i = 1; i <= h; i++) {
            if(i <= y[j]) {
                grid2[i][j] = 1;
            }
            else if(i == (y[j] + 1)) {
                grid2[i][j] = 2;
            }
            else {
                grid2[i][j] = 3;
            }
        }
    }
    long long int ans = 1;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(grid[i][j] * grid2[i][j] == 2) {
                ans = 0;
            }
            int x = min(grid[i][j], grid2[i][j]);
            if(x == 3) {
                ans = (ans * 2) % mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
