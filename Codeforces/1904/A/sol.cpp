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
    int a, b;
    cin >> a >> b;
    int xk, yk, xq, yq;
    cin >> xk >> yk >> xq >> yq;
    int ans = 0;
    for (int i = -1; i < 2; i += 2) {
      for (int j = -1; j < 2; j += 2) {
        int x = xk + i * a;
        int y = yk + j * b;
        if ((abs(x - xq) == a and abs(y - yq) == b) or (abs(x - xq) == b and abs(y - yq) == a)) {
          ans++;
        }
        if (a != b){
          x = xk + i * b;
          y = yk + j * a;
          if ((abs(x - xq) == a and abs(y - yq) == b) or (abs(x - xq) == b and abs(y - yq) == a)) {
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0; 
}