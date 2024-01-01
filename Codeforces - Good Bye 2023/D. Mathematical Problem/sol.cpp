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
  vector<vector<string>> dp(100);
  dp[3].push_back("169");
  dp[3].push_back("961");
  dp[3].push_back("196");
  for (int i = 5; i < 100; i += 2) {
    for (auto &it : dp[i - 2]) {
      dp[i].push_back(it + "00");
    }
    int zero = (i - 3) / 2;
    dp[i].push_back("1" + string(zero, '0') + "6" + string(zero, '0') + "9");
    dp[i].push_back("9" + string(zero, '0') + "6" + string(zero, '0') + "1");
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
      continue;
    } else {
      for (auto &it : dp[n]) {
        cout << it << endl;
      }
    }
  }
  return 0;
}