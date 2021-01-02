#include<bits/stdc++.h>
using namespace std;
map<string,int> maping;
string str = "identiti";
int vis[10];
void rec(int pos, string result) {
    if(pos == 8) {
        maping[result] = 1;
        return;
    }
    for(int i = 0; i < str.length(); i++) {
        if(!vis[i]) {
            if(pos == 0) {
                if(str[i] == 'i') {
                    vis[i] = 1;
                    rec(pos + 1, result + 'i');
                    vis[i] = 0;
                }
                continue;
            } 
            if(pos == 7) {
                if(str[i] == 't') {
                    vis[i] = 1;
                    rec(pos + 1, result + 't');
                    vis[i] = 0;
                }
                continue;
            } 
            
            vis[i] = 1;
            rec(pos + 1, result + str[i]);
            vis[i] = 0;
            
        }     
    }
    return;
}
int main() {
    // rec(0, "");
    int ans = 0;
    for(int i = 30000; i <= 60000; i++) {
        int num = i, found = 1;
        map<int,int> maping;
        while(num > 0) {
            int rem = num % 10;
            if(rem > 6) {
                found = 0;
            }
            maping[rem]++;
            num = num / 10;
        }
        for(auto it : maping) {
            if(it.second >= 2) found = 0;
        }
        ans += found;
    }
    cout << ans << endl;
    // cout << maping.size() << endl;
}