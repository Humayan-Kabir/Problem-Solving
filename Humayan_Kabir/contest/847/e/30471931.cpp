#include <bits/stdc++.h>

using namespace std;

inline bool can_visit(long long s, long long a, long long b, long long t)
{
    if (a > s) a = s;
    if (b < s) b = s;
    long long x = s - a;
    long long y = b - s;
    long long z;
    if (x < y) z = 2 * x + y;
    else z = x + 2 * y;
    return (z <= t);
}

long long h[1234567], p[1234567];

int main()
{
    int q;
    cin>>q;
    string st;
    cin>>st;
    int n=0, m=0;
    for(int i=0;i<st.size();i++)
    {
        if(st[i]=='P')
        {
            h[n]=i+1;
            n++;
        }
        else if(st[i]=='*')
        {
            p[m]=i+1;
            m++;
        }
    }
    long long ll = 0, rr = (long long)1e11;
    while (ll < rr)
    {
        long long mid = (ll + rr) >> 1;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            int low = last, high = m;
            while (low < high)
            {
                int center = (low + high + 1) >> 1;
                if (can_visit(h[i], p[last], p[center - 1], mid)) low = center;
                else high = center - 1;
            }
            last = low;
        }
        if (last == m) rr = mid;
        else ll = mid + 1;
    }
    cout << ll << endl;
    return 0;
}
