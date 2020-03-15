#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
char str[mx];
int n, x, y, dp[mx][10][10], vis[mx][10][10], Timer = 0;
int rec(int pos, int pre1, int pre2) {
  if(pos >= n) {
    return 1;
  }
  int &ret = dp[pos][pre1][pre2];
  int &mark = vis[pos][pre1][pre2];
  if(mark == Timer) return ret;
  mark = Timer;
  int now = 0, v = str[pos] - '0';
  if(v <= x && v >= pre1) {
    now = now | rec(pos + 1, v, pre2);
  }
  if(v >= y && v >= pre2) {
    now = now | rec(pos + 1, pre1, v);
  }
  return ret = now; 
}
void fun(int pos, int pre1, int pre2) {
  if(pos >= n) {
    return;
  }
  int now = 0, v = str[pos] - '0';
  int flag = 0;
  if(v <= x && v >= pre1) {
    if(rec(pos + 1, v, pre2)) {
      printf("1");
      fun(pos + 1, v, pre2);
      flag = 1;
    }
  }
  if(v >= y && v >= pre2) {
    if(!flag && rec(pos + 1, pre1, v)) {
      printf("2");
      fun(pos + 1, pre1, v);
      flag = 1;
    }
  }
  return; 
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    scanf(" %s", &str);
    int flag = 0;
    for(int i = 0; i <= 9; i++) {
      Timer++;
      x = i; y = i;
      if(rec(0, 0, 0)) {
        fun(0,0,0);
        printf("\n");
        flag = 1;
        break;
      }
    }
    if(flag == 0) {
      printf("-\n");
    }
  }
  return 0;
}