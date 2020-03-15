#include <bits/stdc++.h>
#define mx 500007
using namespace std;
int lps[mx];
void computeTemporaryArray(string pattern)
{
    int index = 0;
    for (int i = 1; i < pattern.length();)
    {
        if (pattern[i] == pattern[index])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }
        else
        {
            if (index != 0)
            {
                index = lps[index - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    string stA, stB;
    cin >> stA >> stB;
    int len = stB.length();
    if(len == 1) {
        cout << stA << endl;
        return 0;
    }
    int tz = 0, to = 0, cnt1 = 0, cnt2 = 0, l = stA.length();
    for(int i = 0; i < l; i++) {
        if(stA[i] == '0') tz++;
        if(stA[i] == '1') to++;
    }
    for(int i = 0; i < len; i++) {
        if(stB[i] == '0') cnt1++;
        if(stB[i] == '1') cnt2++;
    }
    computeTemporaryArray(stB);
    int same = lps[len - 1], needx = 0, needy = 0;
    for(int i = same; i < len; i++) {
        if(stB[i] == '0') needx++;
        else needy++;
    }
    if(cnt1 <= tz && cnt2 <= to) {
        cout << stB;
        tz -= cnt1; to -= cnt2;
        while(tz >= needx && to >= needy) {
            for(int i = same; i < len; i++) {
                cout << stB[i];
            }
            tz -= needx; to -= needy;
        }
        while(tz--) {
            cout << '0';
        }
        while(to--) {
            cout << '1';
        }
        cout << endl;
    }
    else {
        cout << stA << endl;
        return 0;   
    }
    return 0;
}
