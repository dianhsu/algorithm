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
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    int da = xb - xa;
    if (da <= 0) {
      cout << "Draw" << endl;
    } else if (da % 2 == 1) {
      // Alice win or Draw
      if (ya == yb) {
        cout << "Alice" << endl;
      } else if (ya < yb) {
        int rb = yb + da / 2;
        int ra = ya + da / 2;
        if (min(rb, w) > ra + 1) {
          cout << "Draw" << endl;
        } else {
          cout << "Alice" << endl;
        }
      } else {
        int la = ya - da / 2;
        int lb = yb - da / 2;
        if (max(lb, 1) < la - 1) {
          cout << "Draw" << endl;
        } else {
          cout << "Alice" << endl;
        }
      }
    } else {
      // Bob win or Draw
      if (ya == yb) {
        cout << "Bob" << endl;
      } else if (ya < yb) {
        int la = ya - da / 2;
        int lb = yb - da / 2;
        if (max(la, 1) <= lb - 1) {
          cout << "Draw" << endl;
        } else {
          cout << "Bob" << endl;
        }
      } else {
        int rb = yb + da / 2;
        int ra = ya + da / 2;
        if (min(ra, w) >= rb + 1) {
          cout << "Draw" << endl;
        } else {
          cout << "Bob" << endl;
        }
      }
    }
  }
  return 0;
}