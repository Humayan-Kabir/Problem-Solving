#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef long double ld;

/*author :: humayan kabir,sust*/

int const MAX = 1000000 + 7;
int const MAXM = 10000 + 7;
int const LOGN = 20;

namespace Lca {
  int lca[MAX][LOGN];
  ll h[MAX];
  int Timer;

  void addedge(int u, int p) {
    lca[u][0] = p;
    h[u] = 1 + h[p];
    for(int i = 1; i<LOGN; i++) {
      int pp = lca[u][i - 1];
      if(pp == -1) continue;
      lca[u][i] = lca[pp][i - 1];
    }
  }

  void build() {
    h[1] = 0;
    memset(lca, -1, sizeof lca);
  }

  int getlca(int p,int q) {
    if(h[p] < h[q]) swap(p, q);
    for(int i = LOGN - 1; i >= 0; i--) {
      if(h[p] - (1 << i) >= h[q]) {
        p = lca[p][i];
      }
    }
    if(p == q) return p;
    for(int i = LOGN - 1; i >= 0; i--) {
      if(lca[p][i] != -1 && lca[p][i] != lca[q][i]) {
        p = lca[p][i];
        q = lca[q][i];
      }
    }
    return lca[p][0];
  }

  ll getdist(int a,int b) {
    return h[a] + h[b] - 2 * h[getlca(a,b)];
  }
};

namespace Dsu {
  int par[MAX];
  ll diameter[MAX];
  int furthestA[MAX];
  int furthestB[MAX]; //here furthestA & B represent
  int sizeT[MAX];    //diameter two point of tree root at varible x

  void init(int u) {
    par[u] = u;
    diameter[u] = 0;
    furthestA[u] = u;
    furthestB[u] = u;
    sizeT[u] = 1;
  }

  int find(int u)
  {
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
  }

  ll unionTree(int a,int b)
  {
    a = find(a);
    b = find(b);
    if(sizeT[a] < sizeT[b]) swap(a,b);
    sizeT[a] += sizeT[b];
    int a1 = Dsu::furthestA[a];
    int a2 = Dsu::furthestB[a];
    int b1 = Dsu::furthestA[b];
    int b2 = Dsu::furthestB[b];
    if(diameter[a] < Lca::getdist(a1,b1)) {
      Dsu::diameter[a] = Lca::getdist(a1,b1);
      furthestA[a] = a1;
      furthestB[a] = b1;
    }
    if(diameter[a] < Lca::getdist(a1,b2)) {
      Dsu::diameter[a] = Lca::getdist(a1,b2);
      furthestA[a] = a1;
      furthestB[a] = b2;
    }
    if(diameter[a] < Lca::getdist(a2,b1)) {
      Dsu::diameter[a] = Lca::getdist(a2,b1);
      furthestA[a] = a2;
      furthestB[a] = b1;
    }
    if(diameter[a] < Lca::getdist(a2,b2)) {
      Dsu::diameter[a] = Lca::getdist(a2,b2);
      furthestA[a] = a2;
      furthestB[a] = b2;
    }
    if(diameter[a] < Lca::getdist(b1,b2)) {
      Dsu::diameter[a] = Lca::getdist(b1,b2);
      furthestA[a] = b1;
      furthestB[a] = b2;
    }
    par[b] = a;
    return diameter[a];
  }

}

int main(int argc, char const *argv[]) {
  int q, Timer = 4;
  scanf("%d", &q);
  for(int i = 1; i - 4 <= 2 * q; i++) {
    Dsu::init(i);
  }
  Lca::build();
  for(int i = 2; i <= 4; i++) {
    Lca::addedge(i, 1);
    Dsu::unionTree(i, 1);
  }
  while(q--) {
    int p;
    scanf("%d", &p);
    Lca::addedge(++Timer, p);
    Dsu::unionTree(Timer, p);
    Lca::addedge(++Timer, p);
    int res = Dsu::unionTree(Timer, p);
    printf("%d\n", res);
  }
  return 0;
}
