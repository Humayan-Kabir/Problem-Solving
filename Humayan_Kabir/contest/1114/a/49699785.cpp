#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
    int x, y, z;
    int a, b, c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if(a >= x && (a - x + b) >= y && (a + b + c) >= (x + y + z)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
