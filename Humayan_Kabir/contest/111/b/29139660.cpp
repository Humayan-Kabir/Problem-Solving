#include<bits/stdc++.h>
#define input(a) scanf("%d",&a)
using namespace std;
vector<int> divisors;
void Find(int n)
{
    int sq=sqrt(n);
    for(int i=1; i<=sq; i++)
    {
        if(n%i==0)
        {
            if((i*i)==n) divisors.push_back(i);
            else
            {
                divisors.push_back(i);
                divisors.push_back((n/i));
            }
        }
    }
}
int main()
{
    int n;
    input(n);
    int pos[100007];
    memset(pos,-1,sizeof pos);
    for(int i=1; i<=n; i++)
    {
        int num,k;
        input(num);
        input(k);
        divisors.clear();
        Find(num);
        int cnt=0;
        for(int j=0; j<divisors.size(); j++)
        {
            if(pos[divisors[j]]<(i-k))
            {
                cnt++;
            }
            pos[divisors[j]]=i;
        }

        printf("%d\n",cnt);
    }

    return 0;
}
