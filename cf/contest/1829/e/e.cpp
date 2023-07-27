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

int __INIT_IO__ = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);
  return 0;
}();
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    vector vis(n, vector(m, 0));
    auto&& check = [&](int curx, int cury){
      return curx >= 0 and curx < n and cury >= 0 and cury < m;
    };
    auto&& dfs = [&](auto&& self, int curx, int cury) -> int{
      if(arr[curx][cury] == 0) return 0;
      if(vis[curx][cury] == 1){
        return 0;
      }
      vis[curx][cury] = 1;
      int ret = arr[curx][cury];
      for(int i = 0; i < 4; ++i){
        int tx = curx + dx[i], ty = cury + dy[i];
        if(check(tx, ty)){
          ret += self(self, tx, ty);
        }
      }
      return ret;
    };
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        cin >> arr[i][j];
      }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        ans = max(ans, dfs(dfs, i, j));
      }
    }
    cout << ans << endl;
  }
  return 0;
}

