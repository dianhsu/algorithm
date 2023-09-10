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
bool check(vector<string> &chess, int n, int m) {
  vector<int> row(n, 0), col(m, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (chess[i][j] != '.') {
        row[i] += 1;
        col[j] += 1;
      }
    }
  }
  for (auto &x : row) {
    if (x & 1) {
      return false;
    }
  }
  for (auto &x : col) {
    if (x & 1) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> chess(n);
    for (auto &s : chess) {
      cin >> s;
    }
    if (!check(chess, n, m)) {
      cout << "-1\n";
      continue;
    }
    vector<string> ans(n, string(m, '.'));
    vector<int> row(n, inf), col(m, inf);
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        if(chess[i][j] == 'L'){
          if(col[j] == inf){
            col[j] = i;
          }else{
            ans[i][j] = 'W'; ans[i][j + 1] = 'B';
            ans[col[j]][j] = 'B'; ans[col[j]][j + 1] = 'W';
            col[j] = inf;
          }
        }
        if(chess[i][j] == 'U'){
          if(row[i] == inf){
            row[i] = j;
          }else{
            ans[i][j] = 'W'; ans[i + 1][j] = 'B';
            ans[i][row[i]] = 'B'; ans[i + 1][row[i]] = 'W';
            row[i] = inf;
          }
        }
      }
    }
    for (auto &s : ans) {
      cout << s << "\n";
    }
  }

  return 0;
}
