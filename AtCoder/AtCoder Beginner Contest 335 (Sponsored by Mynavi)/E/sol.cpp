#include <bits/stdc++.h>
#include <atcoder/all>
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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> val(n + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> val[i];
  vector<vector<int>> g(n + 1);
  atcoder::dsu dsu(n + 1);
  vector<PII> edges(m);
  for(int i = 0; i < m; ++i){
    cin >> edges[i].first >> edges[i].second;
    if (val[edges[i].first] == val[edges[i].second]) {
      dsu.merge(edges[i].first, edges[i].second);
    }
  }
  for (auto& it: edges) {
    int ga = dsu.leader(it.first);
    int gb = dsu.leader(it.second);
    if (ga != gb) {
      g[ga].push_back(gb);
      g[gb].push_back(ga);
    }
  }
  vector<int> ans(n + 1, 0);
  vector<PII> vec;
  for (int i = 1; i <= n; ++i){
    if(dsu.leader(i) == i){
      vec.push_back({val[i], i});
    }
  }
  sort(vec.begin(), vec.end());
  ans[dsu.leader(1)] = 1;
  for (auto& it: vec) {
    int u = it.second;
    for (auto& v: g[u]) {
      if (val[v] <= val[u] and ans[v] > 0) {
        ans[u] = max(ans[u], ans[v] + 1);
      }
    }
  }
  cout << ans[dsu.leader(n)] << endl;
  return 0; 
}