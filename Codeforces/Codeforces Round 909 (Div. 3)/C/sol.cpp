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
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
      cin >> x;
    int cur = 0;
    int ans = arr[0];
    auto &&cal = [&](int l, int r) -> int {
      int curv = arr[l];
      int retv = arr[l];
      for (int i = l + 1; i <= r; ++i) {
        if (curv + arr[i] < arr[i]) {
          curv = arr[i];
        } else {
          curv += arr[i];
        }
        retv = max(retv, curv);
      }
      return retv;
    };
    for (int i = 0; i < n - 1; ++i) {
      if ((abs(arr[i]) & 1) == (abs(arr[i + 1]) & 1)) {
        ans = max(ans, cal(cur, i));
        cur = i + 1;
      }
    }
    if (cur < n) {
      ans = max(ans, cal(cur, n - 1));
    }
    cout << ans << endl;
  }
  return 0;
}