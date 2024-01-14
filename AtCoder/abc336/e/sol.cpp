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
  ll n;
  cin >> n;
  // length, sum of digits, target sum, extra number
  vector dp(15, vector(120, vector(120, vector(120, 0))));
  for (int i = 0; i < 120; ++i) {
    dp[0][0][i][0] = 1;
  }
  ll base = 1;
  for (int i = 0; i < 14; ++i){
    for (int j = 0; j <= 9; ++j){
      ll tv = base * j;
      for (int k = 1; k < 120; ++k) {
        if (j + k >= 120) break;
        for (int l = 0; l < k; ++l) {
          int nl = (tv % k + l) % k;
          dp[i + 1][j + k][k][nl] += dp[i][j][k][l];
        }
      }
    }
    base *= 10;
  }
  string ns = to_string(n);
  ll ans = 0;
  auto&& dfs = [&](auto&& dfs, int p) {
    for (int i = 0; i < ns[p] - '0'; ++i) {
      for (int j = 1; j < 120; ++j){
        ans += dp[ns.size() - p - 1][j][0][i];
      }
    }
    dfs(p + 1);
  };
  cout << base << endl;
  return 0; 
}