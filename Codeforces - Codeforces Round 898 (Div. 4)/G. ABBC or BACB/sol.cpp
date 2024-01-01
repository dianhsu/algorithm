#include <bits/stdc++.h>
#include <climits>

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
    string s;
    cin >> s;
    int ans = 0;
    for(auto& it: s) ans += it == 'A';
    bool flag = false;
    for (int i = 1;  i < s.length(); ++i) {
      if (s[i] == 'B' and s[i - 1] == 'B') {
        flag = true;
        break;
      }
    }
    if (s.front() == 'B' or s.back() == 'B' or flag){
      cout << ans << endl;
    }else{
      int dv = INT_MAX;
      int cnt = 0;
      for (auto& c: s) {
        if (c == 'A') {
          ++cnt;
        } else {
          if (cnt > 0) {
            dv = min(dv, cnt);
            cnt = 0;
          }
        }
      }
      if (cnt > 0) {
        dv = min(dv, cnt);
      }
      cout << ans - dv << endl;
    }
  }
  return 0;
}