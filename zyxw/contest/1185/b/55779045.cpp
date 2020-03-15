#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        int len1 = a.length(), len2 = b.length();
        int len = max(len1, len2);
        int ara1[len1 + 2], ara2[len2 + 2];
        int str1[len1 + 2], str2[len2 + 2];
        memset(ara1, 0, sizeof ara1);
        memset(ara2, 0, sizeof ara2);
        int pre = 0;
        ara1[pre] = 1;
        str1[pre] = a[0];
        for(int i = 1; i < len1; i++) {
            if(a[i] == a[i - 1]) {
                ara1[pre]++;
            }
            else {
                pre++;
                ara1[pre] = 1;
                str1[pre] = a[i];
            }
        }
        int bre = 0;
        ara2[bre] = 1;
        str2[bre] = b[0];
        for(int i = 1; i < len2; i++) {
            if(b[i] == b[i - 1]) {
                ara2[bre]++;
            }
            else {
                bre++;
                ara2[bre] = 1;
                str2[bre] = b[i];
            }
        }
        if(pre != bre) {
            printf("NO\n");
            continue;
        }
        int flag = 0;
        for(int i = 0; i <= pre; i++ ) {
            if(str1[i] != str2[i]) {
                flag = 1;
            }
            if(ara1[i] > ara2[i]) {
                flag = 1;
            }
        }
        if(flag == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }

    }
    return 0;
}