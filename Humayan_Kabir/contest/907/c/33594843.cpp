/*input
7
! ababahalamaha
? a
? b
? a
? b
? a
? h
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int bad[30], shock[30],flag = 0;
string str;
void add()
{
    for(int i = 2; i<str.length(); i++)
        bad[(str[i] - 'a')] = 1;
}
int check_bad()
{
    int sum = 0;
    for(int i = 0; i<26; i++) sum +=bad[i];
    return (sum == 25);    
}
void propagate()
{
    for(int i = 0; i<26; i++)
    {
        if(shock[i] && bad[i]) shock[i] = 0;
    }
}
int check_good()
{
    int sum = 0;
    for(int i = 0; i<26; i++) sum+=shock[i];
    return (sum == 1);    
}
void fun1()
{
    for(int i = 2; i<str.length(); i++)
        if(bad[(str[i] - 'a')] == 0) shock[(str[i] - 'a')] = 1;
}
void fun2()
{   
    for(int i = 2; i<str.size(); i++)
        if(bad[(str[i] - 'a')] == 0 && shock[(str[i] - 'a')] == 1) 
        shock[(str[i] - 'a')]++;
    for(int i = 0; i<26; i++) 
    {
        if(shock[i] > 1) shock[i] = 1;
        else bad[i] = 1;
    } 
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string null;
    getline(cin,null);
    int ans = 0, foo = 0;
    for(int i = 1; i<=n; i++) 
    {
        getline(cin,str);
        if((str[0] == '!' || str[0] == '?') && foo) ans++;
        if(str[0] == '.') 
        {
            add(); propagate();
            if(check_bad() || check_good()) foo = 1;
        }
        if(str[0] == '!')
        {
            if(flag) fun2();
            else fun1();
            propagate();
            if(check_good() || check_bad()) foo = 1;
            flag = 1;
        }
        if(str[0] == '?') 
        {
            add();
            propagate();
            if(check_bad() || check_good()) foo = 1;
        }
    }
    cout << max(0,ans - 1) << endl;
    return 0;
}