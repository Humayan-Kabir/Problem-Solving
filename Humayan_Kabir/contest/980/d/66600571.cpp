#include<bits/stdc++.h>
using namespace std;
namespace perfectGroups {
	const int mx = 5001;
	int arr[mx], ans[mx], previous[mx], dp[5001][5001], zero[mx];
	int transNumber(int num) {
		int temp = abs(num), rt = sqrt(temp), ret = 1;
		for(int i = 2; i <= rt; i++) {
			int cnt = 0;
			while(temp > 1 && temp % i == 0) {
				cnt++; temp = temp / i;
			}
			if(cnt & 1) ret = ret * i; 
		}
		if(temp > 1 || temp == 0) ret = ret * temp;
		return ret * (num > 0 ? 1: -1);
	}
	void mapTheArray(int *n) {
		for(int i = 1; i <= *n; i++) {
			zero[i] = zero[i - 1] + (arr[i] == 0);
		}
		map<int,int> maping;
		for(int i = 1, idx = 0; i <= *n; i++) {
			if(maping.find(arr[i]) == maping.end()) {
				arr[i] = maping[arr[i]] = ++idx;
			} else {
				arr[i] = maping[arr[i]];
			}
		}
		for(int i = 1; i <= *n; i++) {
			int pre = previous[arr[i]];
			previous[arr[i]] = i;
			arr[i] = pre;
		}
	}
	void dpTable(int *n) {
		for(int i = 1; i <= *n; i++) {
			for(int j = 1; j + i - 1 <= *n; j++) {
				int l = i, r = i + j - 1;
				if(arr[r] < l) dp[l][r] = dp[l][r - 1] + 1;
				else dp[l][r] = dp[l][r - 1];
			}
		}
		for(int i = 1; i <= *n; i++) {
			for(int j = i; j <= *n; j++) {
				int id = zero[j] - zero[i - 1];
				if(id >= 1 && dp[i][j] > 1) dp[i][j]--;
				ans[dp[i][j]]++;		
			}
		}
	}
	void solve() {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			arr[i] = transNumber(arr[i]);
		}
		mapTheArray(&n);
		dpTable(&n);
		for(int i = 1; i <= n; i++) {
			printf("%d ", ans[i]); 
			if(i == n) puts(""); 
		}
	}
}
int main() {
	perfectGroups::solve();
	return 0;
}