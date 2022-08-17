#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

#define itr(...) begin(__VA_ARGS__), end(__VA_ARGS__)
#define fastIO() ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define debug(x...) do { cout << "\033[32;1m" << #x <<" -> "; rd_debug(x); } while (0)
void rd_debug() { cout << "\033[39;0m" << endl; }
template<class T, class... Ts> void rd_debug(const T& arg,const Ts&... args) { cout << arg << " "; rd_debug(args...); }
#define pb push_back
#define PF(x) ((x) * (x))
#define LF(x) ((x) * PF(x))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const double eps = 1e-6;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3fll;

int main() {
  fastIO();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<ll> w(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> w[i];
    tree<PLL, null_type, less<PLL>,rb_tree_tag,tree_order_statistics_node_update> tr;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; ++i){
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector<int> ans(n + 1, -1);
    auto&& dfs = [&](auto&& self, int cur, int pre) -> void{
      tr.insert(PLL{w[cur], cur});
      bool leaf = true;
      for(auto& nex: g[cur]){
        if(nex == pre) continue;
        self(self, nex, cur);
        leaf = false;
      }
      if(leaf){
        auto ps = tr.lower_bound({w[cur] + 1, 0});
        if(ps == tr.end()){
          ans[cur] = 0;
        }else{
          ans[cur] = tr.size() - tr.order_of_key(*ps);
        }
      }
      tr.erase(PLL{w[cur], cur});
    };
    dfs(dfs, 1, 0);
    for(auto& it: ans){
      if(it >= 0){
        cout << it << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
