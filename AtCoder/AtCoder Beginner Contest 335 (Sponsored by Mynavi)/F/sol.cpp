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
  int n;
  cin >> n;
  vector<int> val(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    cin >> val[i];
  int m = sqrt(n);
  vector<vector<ll>> mp(n + 1, vector<ll>(m + 1, 0));
  vector<ll> dp(n + 1, 0);
  for (int i = n; i >= 1; --i) {
    if (val[i] <= m) {
      dp[i] = 1;
      if (i + val[i] <= n) {
        dp[i] = (dp[i] + mp[i + val[i]][val[i]]) % MOD9;
      }
    } else {
      dp[i] = 1;
      for (int j = i + val[i]; j <= n; j += val[i])
        dp[i] = (dp[i] + dp[j]) % MOD9;
    }
    for (int j = 1; j <= m; ++j) {
      if (i + j <= n) {
        mp[i][j] = (dp[i] + mp[i + j][j]) % MOD9;
      }else {
        mp[i][j] = dp[i];
      }
    }
  }
  cout << dp[1] << endl;
  return 0;
}