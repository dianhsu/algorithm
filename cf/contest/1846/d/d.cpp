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

template <class T, class... Ts> void rd_debug(const T& arg, const Ts &...args) {
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
      double d, h;
      cin >> d >> h;
      vector<double> y(n);
      for (auto& it : y) cin >> it;
      sort(y.begin(), y.end());
      double ans = d * h / 2.0;
      for(int i = 1; i < n; ++i){
        if(y[i] - y[i - 1] <= h){
          ans -= sx(h - (y[i] - y[i - 1])) * (d / h) / 2.0;
        }
        ans += d * h / 2.0;
      }
      cout << ans << endl;
    }

    return 0;
  }

