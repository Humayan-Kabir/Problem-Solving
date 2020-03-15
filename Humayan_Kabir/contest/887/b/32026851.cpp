/*input
3
0 1 3 5 6 8
1 2 4 5 7 8
2 3 4 6 7 9
*/
#include <bits/stdc++.h>
#include <random>
typedef long long int ll;
using namespace std;
map<int,int> mymap[5];
bool fun(int a, int b,int c)
{
    if(mymap[1].find(a)!=mymap[1].end() && mymap[2].find(b)!=mymap[2].end() && mymap[3].find(c)!=mymap[3].end()) return 1;   
    if(mymap[1].find(a)!=mymap[1].end() && mymap[2].find(c)!=mymap[2].end() && mymap[3].find(b)!=mymap[3].end()) return 1;
    if(mymap[1].find(b)!=mymap[1].end() && mymap[2].find(a)!=mymap[2].end() && mymap[3].find(c)!=mymap[3].end()) return 1;
    if(mymap[1].find(b)!=mymap[1].end() && mymap[2].find(c)!=mymap[2].end() && mymap[3].find(a)!=mymap[3].end()) return 1;
    if(mymap[1].find(c)!=mymap[1].end() && mymap[2].find(a)!=mymap[2].end() && mymap[3].find(b)!=mymap[3].end()) return 1;
    if(mymap[1].find(c)!=mymap[1].end() && mymap[2].find(b)!=mymap[2].end() && mymap[3].find(a)!=mymap[3].end()) return 1;
    return 0;
}   

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    mymap[1][-1] = 1;
    mymap[2][-1] = 1;
    mymap[3][-1] = 1;
    for(int i = 1; i<=6; i++)
    {
        int num;
        cin>> num;
        mymap[1][num] = 1;
    }
    for(int i = 1; i<=6; i++)
    {
        int num;
        cin>> num;
        mymap[2][num] = 1;
    }
    for(int i = 1; i<=6; i++)
    {
        int num;
        cin>> num;
        mymap[3][num] = 1;
    }
    int last = 0;
    for(int i = 1; i<=999; i++)
    {
        int pos = 1, a = -1, b = -1, c = -1;
        int tem = i;
        while(tem)
        {
           if(pos==1) a = tem%10;
           if(pos==2) b = tem%10;
           if(pos==3) c = tem%10;
           tem/=10;
           pos++; 
        }
        if(fun(a,b,c)) last = i;
        else break;
    }

    cout<<last<<endl;

    return 0;
}
