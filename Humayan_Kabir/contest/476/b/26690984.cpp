#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL factorial(LL num)
{
	if(num==0) return 1;
	return num*factorial(num-1);
}
int main(int argc, char const *argv[])
{
	string aa,bb;
	cin>>aa>>bb;
	LL target=0,value=0,missing=0;
	for (int i = 0; i < aa.length(); ++i) aa[i]=='+'?target++:target--;

	for(int i=0;i<bb.length();i++)
	{
		if(bb[i]!='+' && bb[i]!='-') missing++;
		else bb[i]=='+'?value++:value--;
	}

	LL tem=missing;	
	if(missing==0) 
	{
		if(value==target)
		cout<<setprecision(12)<<fixed<<1.0<<endl;
	    else cout<<setprecision(12)<<fixed<<0.0<<endl;
		return 0;
	}

    LL need=abs(target-value);
    if(need==0 && missing%2!=0)
    {
        cout<<setprecision(12)<<fixed<<0.0<<endl;
        return 0;
    }	
    if(need>missing) 
    {
    	cout<<setprecision(12)<<fixed<<0.0<<endl;
    	return 0;
    }
    if((tem-need)%2!=0)
    {
    	cout<<setprecision(12)<<fixed<<0.0<<endl;
    	return 0;
    } 
    need=(tem+need)/2;
    double ans;
    ans=(double)factorial(missing)/(double)factorial(need);

    ans/=(double)factorial(missing-need);
    tem=1<<tem;

    ans=ans/(double)tem;
    cout<<setprecision(12)<<fixed<<ans<<endl;

	return 0;
}