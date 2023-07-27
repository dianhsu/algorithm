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

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<tuple<int, int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
      int a, b, d;
      cin >> a >> b >> d;
      g[a].push_back({b, d, 0});
      g[b].push_back({a, -d, 0});
    }
    map<int, ll> mp;
    mp[1] = 0;
    bool ok = true;
    auto&& dfs = [&](auto&& self, int cur) -> bool {
      for(auto& [nex, dis, vis]: g[cur]){
        if(vis) continue;
        vis = true;
        if(mp.count(nex)){
          if(mp[nex] != mp[cur] + dis){
            ok = false;
            return false;
          }else{
            if(!self(self, nex)) return false;
          }
        }else{
          mp[nex] = mp[cur] + dis;
          if(!self(self, nex)) return false;
        }
      }
      return true;
    };
    for(int i = 1; i <= n; ++i){
      dfs(dfs, i);
    }
    if(ok){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
  return 0;
}
