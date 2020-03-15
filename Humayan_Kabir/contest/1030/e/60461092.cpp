#include<bits/stdc++.h>
#define mx 300007
#define inf 1e16
typedef long long int LL;
using namespace std;
namespace solve {
	LL ar[mx], sum[mx], odd = 0, even = 0;
	void takeInput() {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &ar[i]);
			ar[i] = __builtin_popcountll(ar[i]);
			sum[i] = sum[i - 1] + ar[i];
			sum[i] & 1 ? odd++ : even++;
		}
		LL res = 0;
		for(int i = 1; i <= n; i++) {
			sum[i] & 1 ? odd-- : even--;
			LL curmax = ar[i], tempOdd = odd, tempEven = even; 
			int j = 1;
			while(j <= 60 && i + j <= n) {
				curmax = max(curmax, ar[i + j]);
				if((sum[i + j] - sum[i - 1]) % 2 == 0 && (sum[i + j] - sum[i - 1]) >= 2 * curmax) {
					res++;
				}
				if(sum[i + j] & 1) tempOdd--;
				else tempEven--; 
				j++;
			}
			if(sum[i - 1] & 1) res += tempOdd;
			else res += tempEven;
		}
		printf("%lld\n", res);
	}
}
int main() {
	//ios_base::sync_with_stdio(false);
	solve::takeInput();
	return 0;
}
