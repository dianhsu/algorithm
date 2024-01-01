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
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }
    sort(itr(arr));
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + arr[i];
    }
    auto &&check = [&](ll v) -> bool {
      auto idx = distance(arr.begin(), upper_bound(itr(arr), v));
      ll cnt = v * (idx - 1) - sum[idx - 1];
      return cnt <= x;
    };
    ll cur = 0;
    for (ll i = (1ll << 30); i >= 1; i >>= 1) {
      if (check(cur + i)) {
        cur += i;
      }
    }
    cout << cur << endl;
  }
  return 0;
}