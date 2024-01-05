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

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(k);
    for (auto &it : arr)
      cin >> it;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    if (k == 1) {
      cout << 0 << endl;
      continue;
    }
    auto &&dfs = [&](auto &&self, int cur, int pre, vector<int> &dis) -> void {
      for (auto &nex : g[cur]) {
        if (nex == pre)
          continue;
        dis[nex] = dis[cur] + 1;
        self(self, nex, cur, dis);
      }
    };
    vector<int> dis(n + 1, 0);
    dfs(dfs, arr[0], -1, dis);
    int cur = 0;
    for (int i = 0; i < k; ++i) {
      if (dis[arr[i]] > dis[arr[cur]]) {
        cur = i;
      }
    }
    vector<int> dis2(n + 1, 0);
    dfs(dfs, arr[cur], -1, dis2);
    int nex = 0;
    for (int i = 0; i < k; ++i) {
      if (dis2[arr[i]] > dis2[arr[nex]]) {
        nex = i;
      }
    }
    cout << (1 + dis2[arr[nex]]) / 2 << endl;
  }
  return 0;
}