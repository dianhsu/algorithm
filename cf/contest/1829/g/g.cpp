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
  int maxn = 1e6;
  vector<vector<int>> pos(2e3 + 1, vector<int>(2e3 + 1, 0));
  int cur = 0;
  for(int i = 1; i <= 2e3; ++i){
    for(int j = 1; j <= i; ++j){
      ++cur;
      pos[i][j] = cur;
    }
  }
  vector<vector<ll>> dp(2e3 + 1, vector<ll>(2e3 + 1, 0));
  vector<ll> ans(3e6, 0);
  for(int i = 1; i <= 2e3; ++i){
    for(int j = 1; j <= i; ++j){
      dp[i][j] = sx(1ll * pos[i][j]);
      if(i > 1){
        dp[i][j] = dp[i][j] + dp[i - 1][j - 1] + dp[i - 1][j] - dp[i - 2][j - 1];
      }
      ans[pos[i][j]] = dp[i][j];
    }
  }
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << ans[n] << endl;
  }
  return 0;
}

