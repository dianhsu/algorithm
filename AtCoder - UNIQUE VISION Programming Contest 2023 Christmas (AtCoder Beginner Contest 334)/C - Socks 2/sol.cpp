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
  int n, k;
  cin >> n >> k;
  vector<int> arr(k + 1, 0);
  for (int i = 1; i <= k; i++) {
    cin >> arr[i];
  }
  vector<PII> dp(k + 1, {inf, inf});
  dp[0].first = 0;
  for (int i = 1; i <= k; ++i) {
    if (i > 1) {
      dp[i].first = min(dp[i].first, dp[i - 2].first + arr[i] - arr[i - 1]);
      dp[i].second = min(dp[i].second, dp[i - 2].second + arr[i] - arr[i - 1]);
    }
    dp[i].second = min(dp[i].second, dp[i - 1].first);
  }
  cout << min(dp[k].first, dp[k].second) << endl;
  return 0;
}