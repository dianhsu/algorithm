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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
  int n;
  cin >> n;
  vector<vector<int>> vec(n, vector<int>(n, 0));
  PII cur{0, 0};
  int dr = 0;
  int val = 1;
  vec[cur.first][cur.second] = val++;
  auto &&check = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && vec[x][y] == 0;
  };
  while (cur != PII{n / 2, n / 2}) {
    for (int i = 0; i < 4; ++i) {
      if (check(cur.first + dx[dr], cur.second + dy[dr])) {
        cur.first += dx[dr];
        cur.second += dy[dr];
        vec[cur.first][cur.second] = val++;
        break;
      }
      dr = (dr + 1) % 4;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (vec[i][j] == n * n) {
        cout << "T ";
      } else {
        cout << vec[i][j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}