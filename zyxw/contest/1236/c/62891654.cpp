#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
    int n;
    scanf("%d", &n);
    int grid[n + 1][n + 1];
    for(int i = 1;  i <= n; i++) {
        int st = (i - 1) * n + 1, en = i * n;
        for(int j = 1; j <= n; j++) {
            if(i & 1) grid[j][i] = st++;
            else grid[j][i] = en--;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", grid[i][j]);
        }
        puts("");
    }
    return 0;
}