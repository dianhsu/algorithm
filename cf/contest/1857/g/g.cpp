#include <bits/stdc++.h>

using namespace std;
#define sx(x) ((x) * (x))
#define vx(x) (sx(x) * (x))
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
ll qPow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a % MOD9;
    a = a * a % MOD9;
    b >>= 1;
  }
  return ans;
}
class DSU {
public:
  vector<int> fa;
  vector<int> size;
  DSU(int n) : fa(n), size(n, 1) { iota(fa.begin(), fa.end(), 0); }
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
    if (size[a] < size[b]) {
      swap(a, b);
    }
    fa[b] = a;
    size[a] += size[b];
  }
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, S;
    cin >> n >> S;
    vector<tuple<int, int, int>> vec(n - 1);
    for (int i = 0; i < n - 1; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      vec[i] = {w, x, y};
    }
    sort(vec.begin(), vec.end());
    DSU dsu(n + 1);
    ll ans = 1;
    for (auto &[w, x, y] : vec) {
      if (w == S)
        break;
      int tx = dsu.tf(x);
      int ty = dsu.tf(y);
      ans = 1ll * qPow(S - w + 1, dsu.size[tx] * dsu.size[ty] - 1) * ans % MOD9;
      dsu.fa[ty] = tx;
      dsu.size[tx] += dsu.size[ty];
    }
    cout << ans << '\n';
  }

  return 0;
}
