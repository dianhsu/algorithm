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
  vector<int> sum(251, 0);
  for (int i = 1; i <= 250; ++i)
    sum[i] = sum[i - 1] + i * i;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = n; i >= 1; --i) {
      int curs = sum[i - 1];
      int ts = 0;
      int l = i, r = n;
      while (l <= r) {
        int tv = l * r;
        if (ts <= tv) {
          curs += ts;
          ts = tv;
        } else {
          curs += tv;
        }
        if (l != r) {
          if (ts <= tv) {
            curs += ts;
            ts = tv;
          } else {
            curs += tv;
          }
        }
        ++l, --r;
      }
      ans = max(ans, curs);
    }
    cout << ans << "\n";
  }
  return 0;
}
