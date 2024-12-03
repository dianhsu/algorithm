#include <bits/stdc++.h>

using namespace std;
#define PF(x) ((x) * (x))
#define LF(x) (PF(x) * (x))
#define itr(x) begin(x), end(x)
#define debug(x...)                                                            \
  do {                                                                         \
    cout << "\033[32;1m" << #x << " -> ";                                      \
    rd_debug(x);                                                               \
  } while (0)

void rd_debug() { cout << "\033[39;0m" << endl; }

template <class T, class... Ts> void rd_debug(const T &arg, const Ts &...args) {
  cout << arg << " ";
  rd_debug(args...);
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const double eps = 1e-7;
const int MOD1 = 1e9 + 7;
const int MOD9 = 998244353;
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3fll;

int __INIT_IO__ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);
  return 0;
}();
class DSU {
public:
  vector<int> fa;
  vector<int> sz;
  DSU(int n): fa(n), sz(n, 1) {
    iota(fa.begin(), fa.end(), 0);
  }
  int tf(int x) {
    if (fa[x] == x) {
       return x;
    }
    return fa[x] = tf(fa[x]);
  }
  void mg(int x, int y) {
    int a = tf(x);
    int b = tf(y);
    if (a == b) {
      return;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    fa[b] = a;
    sz[a] += sz[b];
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> color(n + 1, 0);
  for(int i = 1; i <= n; ++i) {
    color[i] = i;
  }
  vector<int> color_cnt(n + 1, 1);
  DSU dsu(n + 1);
  for (int i = 0; i < m; ++i){
    int tp;
    cin >> tp;
    if (tp == 1){
      int p, c;
      cin >> p >> c;
      int tp = dsu.tf(p);
      if (color[tp] != c) {
        color_cnt[color[tp]] -= dsu.sz[tp];
      }
    }
  }
  return 0; 
}