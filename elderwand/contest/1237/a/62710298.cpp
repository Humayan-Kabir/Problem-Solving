#include<bits/stdc++.h>
#define mx 100007
using namespace std;
int ara[mx], counter1 = 0, counter2 = 0;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        if(abs(ara[i]) % 2) counter1++;
    }
    counter1 /= 2;
    for(int i = 1; i <= n; i++) {
        if(abs(ara[i]) % 2) {
            if(counter1 > 0) {
                cout << (ara[i] - 1) / 2 << endl;
                counter1--;
            }
            else {
                cout << (ara[i] + 1) / 2 << endl;
            }
        }
        else {
            cout << ara[i] / 2 << endl;
        }
    }
    return 0;
}