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
struct Node {
  int cu, cs;
  ll ct;
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> g(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(1001, infl));
    dp[1][s[1]] = 0;
    queue<Node> q;
    q.push(Node{1, s[1], 0});
    while (!q.empty()) {
      auto [cu, cs, ct] = q.front();
      q.pop();
      if (dp[cu][cs] < ct)
        continue;
      for (auto [nv, nw] : g[cu]) {
        ll nt = ct + nw * 1ll * cs;
        int ns = min(s[nv], cs);
        if(nt < dp[nv][ns]){
          dp[nv][ns] = nt;
          q.push(Node{nv, ns, nt});
        }
      }
    }
    ll ans = infl;
    for (int i = 1; i <= 1000; ++i) {
      ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
  }
  return 0;
}
