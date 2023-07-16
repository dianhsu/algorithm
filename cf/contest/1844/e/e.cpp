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
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr((n + m) * 2);
    iota(itr(arr), 0);
    function<int(int)> find = [&](int x) -> int {
      return arr[x] == x ? x : arr[x] = find(arr[x]);
    };
    auto &&merge = [&](int x, int y) {
      int fx = find(x), fy = find(y);
      if(fx != fy){
        arr[fx] = fy;
      }
    };
    bool ok = true;
    for (int i = 0; i < k; ++i) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      --x1, --y1, --x2, --y2;
      int dx = x1, dy = min(y1, y2) + n;
      int nx = dx + n + m, ny = dy + n + m;
      if (y2 == y1 + 1) {
        if(find(dx) == find(dy)){
          ok = false;
        }else{
          merge(dx, ny);
          merge(nx, dy);
        }
      } else {
        if(find(dx) == find(ny)){
          ok = false;
        }else{
          merge(dx, dy);
          merge(nx, ny);
        }
      }
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}
