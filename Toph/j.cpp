#include<bits/stdc++.h>
using namespace std;

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
        vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
     vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
unordered_map<char, int> counter;
const int N = 1000007;
bool vis[N];

bool checkPallindrome(int k) {
    int oddCnt = 0;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        if (counter[ch] & 1) oddCnt++;
    }
    oddCnt -= (k & 1);
    return oddCnt == 0;
}

int main() {
    int n, k; cin >> n >> k;
    string str; cin >> str;
    vector<int> position = suffix_array_construction(str);
    for(int i = 0; i < n; i++) {
        counter[str[i]]++;
        if (i >= k - 1) {
            if (checkPallindrome(k)) {
                vis[i - k + 1] = 1;
            }
            counter[str[i - k + 1]]--;
        }
    }
    int flag = 0;
    for(int p : position) {
        if (vis[p]) {
            flag = 1;
            cout << str.substr(p, k) << endl;
            break;
        }
    }
    if (!flag) {
        cout << "No Passcode Found" << endl;
    }
}