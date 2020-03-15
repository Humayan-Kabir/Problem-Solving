#include<bits/stdc++.h>
using namespace std;
#define mx 300007
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) 
    {
        int num;
        cin >> num;
        if(num % 2 == 0) x++;
        else y++;
    }   
    int u = 0, v = 0;
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if(num % 2 == 0) u++;
        else v++; 
    }
    cout << min(x, v) + min(y, u) << endl;
    return 0;
}