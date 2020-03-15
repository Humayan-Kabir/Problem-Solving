#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
int a[mx+1],ans[mx+1],cnt;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int pos;
        cin>>pos;
        a[pos]=1;
    }
    int p=0;

     for(int i=1;i<=(mx/2);i++) {
            if(a[i]==1 && a[mx-i]==1) {
            cnt++;
        }
    }

    for(int i=1;i<=(mx/2);i++) {

        if(a[i]==1 && a[mx-i]==0) {
            ans[p]=mx-i;
            //cout<<mx-i<<" if i "<<i<<endl;
            p++;
            continue;
        }
        else if(a[mx-i]==1 && a[i]==0) {
            ans[p]=i;
            p++;
           // cout<<mx-i<<" if i "<<i<<endl;
            continue;
        }
        if(cnt && a[i]==0 && a[mx-i]==0) {
            ans[p++]=i;
            ans[p++]=mx-i;
            //cout<<mx-i<<" if i "<<i<<endl;
            cnt--;
        }

    }

    printf("%d\n",p);
    for(int i=0;i<p;i++) {
        if(i==0) printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }

    // second 

    return 0;
}
