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
    int n, m, sz;
    cin >> n >> m >> sz;
    vector<string> arr(n);
    for (auto& it: arr) cin >> it;
    vector<vector<int>> gsum(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> lsum(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> rsum(n + 2, vector<int>(m + 2, 0));
    auto &&get_linex = [&](int x1, int x2, int y) {
      return gsum[x2][y] - gsum[x1][y];
    };
    auto &&get_liney = [&](int x, int y1, int y2) {
      return gsum[x][y2] - gsum[x][y1];
    };
    auto &&get_lineur = [&](int x1, int y1, int x2, int y2) {
      return rsum[x2][y2] - rsum[x1 - 1][y1 - 1];
    };
    auto &&get_linelr = [&](int x1, int y1, int x2, int y2) {
      return lsum[x2][y2] - lsum[x1][y1];
    };
    auto &&handlex = [&](int lx, int rx, int y) -> int {
      if (y < 1 or y > m) return 0;
      lx = max(lx, 1);
      rx = min(rx, n);
      if (lx > rx) return 0;
      return get_linex(lx, rx, y);
    };
    auto &&handley = [&](int dy, int uy, int x) -> int {
      if (x < 1 or x > n) return 0;
      dy = max(dy, 1);
      uy = min(uy, m);
      if (dy > uy) return 0;
      return get_liney(x, dy, uy);
    };

    auto&& handleur = [&](int lx, int rx, int b) -> int {
      lx = max(lx, 1);
      rx = min(rx, n);
      if (lx > rx) return 0;
      lx = max(lx, 1 - b);
      rx = min(rx, m - b);
      if (lx > rx) return 0;
      return get_lineur(lx, lx + b, rx, rx + b);
    };
    auto&& handleld = [&](int lx, int rx, int b) -> int {
      lx = max(lx, 1);
      rx = min(rx, n);
      if (lx > rx) return 0;
      lx = min(b - 1, lx);
      rx = max(rx, b - m);
      if (lx > rx) return 0;
      return get_linelr(lx, b - lx, rx, b - rx);
    };
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int v = (arr[i - 1][j - 1] == '#');
        gsum[i][j] = gsum[i - 1][j] + gsum[i][j - 1] - gsum[i - 1][j - 1] + v;
        lsum[i][j] += lsum[i - 1][j + 1] + v;
        rsum[i][j] += rsum[i - 1][j - 1] + v;
      }
    }
    vector ans(n + 2, vector(m + 2, vector<int>(4, 0)));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (i == 1 and j == 1) {
          for (int l = 0; l < sz; ++l) {
            ans[i][j][0] += handley(j, j + sz - l - 1, i + l);
            ans[i][j][1] += handley(j, j + sz - l - 1, i - l);
            ans[i][j][2] += handley(j - (sz - l - 1), j, i - l);
            ans[i][j][3] += handley(j - (sz - l - 1), j, i + l);
          }
        }
      }
    }
    cout << ans[1][1][0] << endl;
  }
  return 0;
}