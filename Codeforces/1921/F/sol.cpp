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
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    vector<tuple<ll, ll, ll>> query(q);
    for (auto &[s, d, k] : query) {
      cin >> s >> d >> k;
      --s;
    }
    int sz = floor(sqrt(n));
    vector dp(n, vector<ll>(sz + 1, 0));
    vector sum(n, vector<ll>(sz + 1, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= sz; ++j) {
        int extra = i % j;
        if (i >= j) {
          dp[i][j] = arr[i] * (i / j + 1) + dp[i - j][j];
          sum[i][j] = sum[i - j][j] + arr[i];
        }else{
          sum[i][j] = arr[i];
          dp[i][j] = arr[i];
        }
      }
    }
    for (auto &[s, d, k] : query) {
      if (d <= sz) {
        ll r = s + (k - 1) * d;
        ll ans = dp[r][d];
        if (s >= d) {
          ll dv = s / d;
          ans -= dp[s - d][d];
          ans -= (sum[r][d] - sum[s - d][d]) * dv;
        }
        cout << ans << " ";
      }else{
        ll ans = 0;
        for (int i = 0; i < k; ++i) {
          ans += arr[s + i * d] * (i + 1);
        }
        cout << ans << " ";
      }
    }
    cout << endl;
  }
  return 0;
}