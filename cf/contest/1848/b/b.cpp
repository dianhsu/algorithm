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
    int n, k;
    cin >> n >> k;
    vector<int> c(n + 1, 0);
    map<int, PII> mp;
    map<int, int> pr;
    auto&& updateMP = [&](int curv, int curp){
      int tv = 0;
      if(pr.count(curv)){
        tv = curp - pr[curv] - 1;
      }else{
        tv = curp - 1;
      }
      pr[curv] = curp;
      if(mp.count(curv)){
        if(tv >= mp[curv].first){
          mp[curv].second = mp[curv].first;
          mp[curv].first = tv;
        }else if(tv >= mp[curv].second){
          mp[curv].second = tv;
        }
      }else{
        mp[curv] = {tv, 0};
      }
    };
    for(int i = 1; i <= n; ++i){
      cin >> c[i];
      updateMP(c[i], i);
    }
    for(auto& [key, pos]: pr){
      updateMP(key, n + 1);
    }
    int ans = inf;
    for(auto& [key, pos]: pr){
      ans = min(ans, max(mp[key].first / 2, mp[key].second));
    }
    cout << ans << "\n";
  }

  return 0;
}

