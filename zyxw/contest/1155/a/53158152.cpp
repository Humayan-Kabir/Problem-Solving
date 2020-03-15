#include<bits/stdc++.h>
using namespace std;
#define mx 300007
typedef long long int LL;
int ara[200];
int main(int argc, char const *argv[])
{
    string str;
    int n;
    cin >> n;
    cin >> str;
    int f = 0;
    for(int i = 1; i <= n; i++) {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(ch <= str[i - 1]) continue;
            int x = (int) ch;
            if(ara[x] > 0) {
                puts("YES");
                cout << ara[x] << " "<< i << endl;
                return 0;
            }
        }
        int y = (int) str[i - 1];
        ara[y] = i;
    }
    puts("NO");
    return 0;
}
