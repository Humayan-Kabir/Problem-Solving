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

struct chat
{
    string name;
    int pos,val;
};

bool compare(chat a,chat b)
{
    return a.val>b.val;
}
int main()
{

    vector<chat> chatlist;
    map<string,int> mymap;
    string str;
    int n,i,j,k,p;
    sf1(n);
    getchar();
    p=0;
    for (i=1; i<=n ; i++ )
    {
        getline(cin,str);
        chat man;
        man.name=str;
        man.val=i;
        if(mymap[str]>=1)
        {
            j=mymap[str]-1;
            chatlist[j].val=i;
        }
        else
        {
            mymap[str]=p+1;
            man.pos=p;
            p++;
            chatlist.push_back(man);
        }

    }
    sort(chatlist.begin(),chatlist.end(),compare);
    k=chatlist.size();
    for (i=0; i<k ; i++ )
    {
        cout<<chatlist[i].name<<endl;
    }
    return 0;
}
