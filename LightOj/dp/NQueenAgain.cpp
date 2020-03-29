/* بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 * Author: Humayan Kabir
 * Time: 2020-03-29 22:06:04
 * SUST-15
**/
#include<bits/stdc++.h>
#define mod 1000000007
#define mx 200007
using namespace std;
typedef long long int LL;
class Board {
    public: int y[8];
}; 
class ValidBoard {
    public:
    Board board[92]; int counter = 0;
    bool isPossible(Board &tmp, int r, int c) {
        for(int i = 0; i < r; i++) {
            if(tmp.y[i] == c || abs(i - r) == abs(tmp.y[i] - c)) return 0;
        }
        return 1;
     }
    void generateComb(int r, Board &tmp) {
        if(r == 8) {
            board[counter++] = tmp;
            return;
        }
        for(int c = 0; c < 8; c++) {
            if(isPossible(tmp, r, c)) {
                tmp.y[r] = c;
                generateComb(r + 1, tmp);
            }
        }
    }
};
int dp[8][1 << 8];
int findMoves(int x1, int y1, int x2, int y2) {
    if(x1 == x2 && y1 == y2) return 0;
    else if( (x1==x2) || y1==y2 || abs(x1-x2)==abs(y1-y2) ) return 1;
    else return 2; 
}
int rec(int r,int mask, int idx, vector<pair<int,int>> &positions, ValidBoard &cur) {
    if(r == 8) {
        return 0;
    }
    int &ret = dp[r][mask];
    if(ret != -1) return ret;
    int now = INT_MAX;
    for(int i = 0; i < 8; i++) {
        if(mask & (1 << i)) continue;
        now = min(now, findMoves(r, cur.board[idx].y[r], positions[i].first, positions[i].second) + rec(r + 1, mask | (1 << i), idx, positions, cur));
    }
    return ret = now;
}
int solve(vector<pair<int,int>> &positions, ValidBoard &cur) {
    int ans = INT_MAX;
    for(int i = 0; i < 92; i++) {
        memset(dp, -1, sizeof dp);
        ans = min(ans, rec(0, 0, i, positions, cur));
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ValidBoard cur; Board tmp;
    cur.generateComb(0, tmp);
    int t, cas = 1;
    cin >> t;
    while(t--) {
        vector<pair<int,int>> positions;
        for(int i = 0; i < 8; i++) {
            string str;
            cin >> str;
            for(int j = 0; j < 8; j++) {
                if(str[j] == 'q') {
                    positions.push_back({i,j});
                }
            }
        }
        cout << "Case " << cas++ << ": " << solve(positions, cur) << endl;
    }
    return 0;
}