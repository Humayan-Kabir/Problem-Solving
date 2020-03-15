#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

int main()
{

    int i,j,k,n,m,flag,flag2;
    map<string,int> word;
    string str;
    queue<string> Q1;
    queue<string> Q2;
    sf2(n,m);
    getchar();
    flag=0;
    flag2=0;
    j=n;
    k=m;
    while (n--)
    {
        getline(cin,str);
        word[str]=1;
        Q1.push(str);
    }
    while (m--)
    {
        getline(cin,str);
        if(word[str]==1) flag++;
        Q2.push(str);
    }
    if(flag%2!=0){
        j=j-flag+1;
        k=k-flag;
    }
    if(j>k){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
//    while (!Q1.empty())
//    {
//        if(Q2.empty()) break;
//        string ss;
//        ss=Q1.front();
//        Q1.pop();
//        //cout<<ss<<".............. ";
//        if(word[ss]!=1)
//        {
//            word[ss]=1;
//            while (!Q2.empty())
//            {
//                string s;
//                s=Q2.front();
//                Q2.pop();
//                //cout<<s<<">>>>>>>>"<<endl;
//                if(word[s]!=1)
//                {
//                    word[s]=1;
//                    break;
//                }
//                word[s]=1;
//            }
//        }
//        word[ss]=1;
//    }

    //cout<<Q1.size()<<" "<<Q2.size()<<endl;
//        if(Q2.empty() && !Q1.empty())
//        printf("YES\n");
//    else{
//        printf("NO\n");
//    }

    return 0;
}
