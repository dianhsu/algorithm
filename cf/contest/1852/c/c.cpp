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
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    vector<PII> vec;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      if (vec.empty()) {
        vec.push_back({i, i});
      } else {
        if (arr[vec.back().second] == k and arr[i] == k) {
          vec.back().second = i;
        } else if (arr[vec.back().second] < k and arr[i] < k) {
          vec.back().second = i;
        } else {
          vec.push_back({i, i});
        }
      }
    }
    vector<tuple<ll, ll, ll>> cnt(vec.size(), {0, 0, 0});
    for (int i = 0; i < vec.size(); ++i) {
      auto [l, r] = vec[i];
      ll cur = 0;
      ll mid = 0;
      for (int j = l; j <= r; ++j) {
        mid += max(0ll, arr[j] - cur);
        cur = arr[j];
      }
      cnt[i] = {arr[l], mid, arr[r]};
    }
    vector<vector<ll>> dp(vec.size() + 1, vector<ll>(3, infl));
    for (int i = 0; i < vec.size(); ++i) {
      auto [cl, cm, cr] = cnt[i];
      if (i == 0) {
        if (arr[vec[i].first] == k) {
          dp[i][0] = k;
          dp[i][1] = 0;
          dp[i][2] = k * 2;
        } else {
          dp[i][1] = cm;
          dp[i][2] = cm + k;
        }
      } else {
        auto [pl, pm, pr] = cnt[i - 1];
        if (arr[vec[i].first] >= k) {
          dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        }
        dp[i][1] = min(dp[i - 1][1] + cm - cl + max(0ll, cl - pr),
                       dp[i - 1][2] + cm - cl + max(0ll, cl - pr - k));
        dp[i][2] = min(dp[i - 1][1] + cm - cl + max(0ll, cl + k - pr),
                       dp[i - 1][2] + cm - cl + max(0ll, cl + k - pr - k));
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + cm - cl + max(0ll, cl - pr + k));
        dp[i][2] =
            min(dp[i - 1][0] + cm - cl + max(0ll, cl + k - pr + k), dp[i][2]);
      }
     // debug(i, vec[i].first, vec[i].second, dp[i][0], dp[i][1], dp[i][2]);
    }
    cout << min({dp[vec.size() - 1][0], dp[vec.size() - 1][1],
                 dp[vec.size() - 1][2]})
         << endl;
  }

  return 0;
}
