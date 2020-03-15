    #include <bits/stdc++.h>
    #define mx 200007
    using namespace std;
    typedef long long int LL;
    LL maxPOwer(LL p, LL n)
    {
        LL cnt = 0;
        while (n / p)
        {
            cnt += (n / p);
            n /= p;
        }
        return cnt;
    }
    LL findPower(LL p, LL q, LL n)
    {
        return maxPOwer(p, n) / q;
    }
    int main(int argc, char const *argv[])
    {
        LL n, b;
        cin >> n >> b;
        LL counter = 0, res = 1000000000000000000;
        LL temp = n;
        while (b % 2 == 0)
        {
            counter++;
            b /= 2;
        }
        if (counter)
        {
            res = min(res, findPower(2, counter, temp));
        }
        for (LL i = 3; i * i <= b; i += 2)
        {
            counter = 0;
            while (b % i == 0)
            {
                counter++;
                b /= i;
            }
            if (counter)
            {
                res = min(res, findPower(i, counter, temp));
            }
        }
        if (b > 2)
        {
            res = min(res, findPower(b, 1, temp));
        }
        cout << res << endl;
        return 0;
    }