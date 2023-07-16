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
      int n, m, h;
      cin >> n >> m >> h;
      vector<vector<int>> arr(n, vector<int>(m, 0));
      vector<tuple<ll, ll, ll>> ans(n);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          cin >> arr[i][j];
        }
        sort(itr(arr[i]));
        ll cnt = 0;
        ll penalty = 0;
        ll prev = 0;
        for(int j = 0; j < m; ++j){
          if(prev + arr[i][j] <= h){
            ++cnt;
            prev += arr[i][j];
            penalty += prev;
          }
        }
        ans[i] = {-cnt, penalty, i};
      }
      sort(itr(ans));
      for(int i = 0; i < n; ++i){
        if(get<2>(ans[i]) == 0){
          cout << i + 1 << "\n";
          break;
        }
      }
    }

    return 0;
  }

