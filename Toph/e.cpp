#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int getLimit(char ch) {
    return ch == '0' ? INT_MAX : 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    string str, charSet; cin >> str >> charSet;
    unordered_map<char, int> counter;
    int left = 0, len = str.length();
    LL ans = 0;
    for(int right = 0; right < len; right++) {
        counter[str[right]]++;
        while(left < len && counter[str[right]] > getLimit(charSet[str[right] - 'a'])) {
            counter[str[left]]--;
            left++;
        }
        ans += max(0, right - left + 1);
    }
    cout << ans << endl;
    return 0;
}

/*
aabcaabc
110
*/