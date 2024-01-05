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
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    int ans = -1;
    for (int i = 0; i < n; ++i){
      bool ok = true;
      for (int j = 0; j < m; ++j) {
        if (x[(i + j) % n] != s[j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        int len = (i + m + n - 1) / n;
        for (int j = 0; j < 20; ++j) {
          if ((1 << j) >= len) {
            ans = j;
            break;
          }
        }
        break;
      }
    }
    cout << ans << endl;
  }
  return 0; 
}