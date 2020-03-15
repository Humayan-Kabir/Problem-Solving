#include<bits/stdc++.h>
#define mx 300007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    //ios_base::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if((i + j) % 2 == 0) {
                printf("W");
            }
            else {
                printf("B");
            }
        }
        printf("\n");
    }
    return 0;
}
