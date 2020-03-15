#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    LL a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c) / 2LL << endl;
  }
  return 0;
}
