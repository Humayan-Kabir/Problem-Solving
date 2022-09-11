#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_function(vector<int> &s) {
    int n = s.size();
    vector<int> lps(n);
    for (int i = 1; i < n; i++) {
        int j = lps[i-1];
        while (j > 0 && s[i] != s[j])
            j = lps[j-1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

int getMatchCnt(vector<int> &s, vector<int> &p) {
    vector<int> lps = prefix_function(p);
    int n = (int)s.size();
    int m = (int)p.size();
    int i = 0, j = 0, cnt = 0;
    while(i < n && j < m) {
        if(s[i] == p[j]){
            i++; 
            j++;
        }
        else{
            if(j!=0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
        if (j == m) {
            j = lps[j - 1];
            cnt++;
        }
    }
    return cnt;   
}
int main() {
   freopen("consecutive_cuts_chapter_1_input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
    int t; scanf("%d", &t);
    for(int test = 1; test <= t; test++) {
        int n, k; scanf("%d %d", &n, &k);
        vector<int> s(2 * n - 1);
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            if (i != n - 1) {
                s[n + i] = s[i];
            }
        }
        bool isAlreadyMatched = true;
        for(int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            if (s[i] != p[i]) {
                isAlreadyMatched = false;
            }
        }
        int cnt = getMatchCnt(s, p);
        bool isPossible = true;
        if (k == 0) {
            isPossible = isAlreadyMatched;
        } else if(cnt == 0) {
            isPossible = false;
        } else if (cnt >= 2) {
            isPossible = true;
        } else if(k == 1) {
             isPossible = isAlreadyMatched ^ 1;
        } else { // cnt == 1 and k > 1
            int nonMatch = n - cnt;
            if (nonMatch == 1) {
                isPossible = isAlreadyMatched ^ (k & 1);
            } else {
                isPossible = true;
            }
        }
        if (isPossible) {
            printf("Case #%d: YES\n", test);
        } else {
            printf("Case #%d: NO\n", test);            
        }
    }
    return 0;
}                                                             