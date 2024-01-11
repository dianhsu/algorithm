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
    string s;
    cin >> s;
    if(s[0] == '0'){
      cout << -1 << endl;
      continue;
    }
    int n = s.length();
    bool ok = false;
    for (int i = 1; i < n; ++i){
      if(s[i] != '0'){
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, n - i);
        int v1 = stoi(s1), v2 = stoi(s2);
        if(v1 < v2){
          cout << v1 << " " << v2 << endl;
          ok = true;
          break;
        }
      }
    }
    if (!ok)
      cout << -1 << endl;
  }
  return 0; 
}