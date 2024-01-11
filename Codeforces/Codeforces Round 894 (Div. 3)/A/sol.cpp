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
    vector<string> arr(n);
    for (auto& it: arr) cin >> it;
    vector<vector<int>> dp(5, vector<int> (m + 1, 0));
    for (int j = 0; j < m + 1; ++j){
      dp[0][j] = 1;
    }
    for (int j = 0; j < m; ++j){
      for (int i = 0; i < n; ++i){
        char c = arr[i][j];
        if (c == 'v') {
          dp[1][j + 1] = 1;
        } else if(c == 'i') {
          dp[2][j + 1] = dp[1][j];
        } else if(c == 'k') {
          dp[3][j + 1] = dp[2][j];
        } else if(c == 'a'){
          dp[4][j + 1] = dp[3][j];
        }
      }
      for (int i = 0; i < 5; ++i){
        dp[i][j + 1] = dp[i][j] | dp[i][j + 1];
      }
    }
    cout << (dp[4][m] ? "YES" : "NO") << endl;
  }
  return 0; 
}