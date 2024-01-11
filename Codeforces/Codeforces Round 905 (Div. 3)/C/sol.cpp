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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr)
      cin >> x;
    if (k == 4) {
      int cnt = 0;
      for (auto &it : arr) {
        if (it % 4 == 0)
          cnt += 2;
        else if (it % 2 == 0)
          ++cnt;
      }
      if (cnt >= 2) {
        cout << 0 << endl;
      } else if (cnt == 1) {
        cout << 1 << endl;
      } else {
        int ans = 2;
        for (auto &it : arr) {
          if ((it + 1) % 4 == 0) {
            ans = min(ans, 1);
          }
        }
        cout << ans << endl;
      }
    } else {
      int ans = inf;
      for (auto &it : arr) {
        ans = min(ans, (k - it % k) % k);
      }
      cout << ans << endl;
    }
  }
  return 0;
}