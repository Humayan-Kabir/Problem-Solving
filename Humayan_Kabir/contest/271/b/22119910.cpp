#include<bits/stdc++.h>
#define mx 100002
using namespace std;
int state[(mx/32)+5],sz,num,next_prime[100002];
bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
void bit_seive()
{
    int i,j,root;
    root=sqrt(mx);
    for (i=4; i<=mx ; i+=2 )
    state[i>>5]=Set(state[i>>5],i&31);
    state[1>>5]=Set(state[1>>5],1&31);

    state[1>>5]=Set(state[1>>5],1&31);
    for (i=3; i<=root ; i+=2 )
    {
        if(Check(state[i>>5],i&31)==0)
        {
            for (j=i*i; j<=mx ; j+=(2*i))
            {
                int m=i*j;
                state[j>>5]=Set(state[j>>5],j&31);
            }
        }
    }

}
int main()
{
    bit_seive();
    long long  int m,n,i,j,k,low,flag1,flag2,column[510];
    sz=100003;
    for (i=100000;i>=1 ;i--)
    {

      if(Check(state[i>>5],i&31)!=0){
        next_prime[i]=sz;
      }
      else{
        next_prime[i]=i;
        sz=i;
      }
    }
    while (scanf("%lld%lld",&n,&m)!=EOF)
    {
        low=INT_MAX;
        memset(column,0,sizeof column);
        for (i=0; i<n ; i++ )
        {
            flag1=0;
            for (j=0; j<m ; j++ )
            {
                scanf("%d",&num);
                if(Check(state[num>>5],num&31)!=0){
                  flag1+=(next_prime[num]-num);
                  column[j]+=(next_prime[num]-num);
                }
            }
            low=min(low,flag1);
        }
        for (i=0;i<m ;i++ )
        {
           low=min(low,column[i]);
        }

        printf("%lld\n",low);


}
    return 0;



}
