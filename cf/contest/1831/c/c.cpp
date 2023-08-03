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

template <class T, class... Ts> void rd_debug(const T& arg, const Ts &...args) {
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

int __INIT_IO__ = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);
  return 0;
}();

int main() {
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<vector<PII>> g(n + 1);
    for(int i = 1; i < n; ++i){
      int a, b;
      cin >> a >> b;
      g[a].push_back({b, i});
      g[b].push_back({a, i});
    }
    vector<int> pos(n + 1, 0);
    vector<int> ans(n + 1, 0);
    ans[1] = 1;
    int res = 0;
    auto&& dfs = [&](auto&& self, int cur, int pre) -> void{
      res = max(res, ans[cur]);
      for(auto& [nexp, next]: g[cur]){
        if(nexp == pre) continue;
        pos[nexp] = next;
        if(pos[nexp] >= pos[cur]){
          ans[nexp] = ans[cur];
        }else{
          ans[nexp] = ans[cur] + 1;
        }
        self(self, nexp, cur);
      }
    };
    dfs(dfs, 1, 0);
    cout << res << "\n";
  }
  return 0;
}

