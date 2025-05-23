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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<pair<char, int>> v;
  for(auto &c: s) {
    if(v.empty() || v.back().first != c) {
      v.push_back({c, 1});
    } else {
      v.back().second++;
    }
  }
  if (v.begin()->first == '0') {
    swap(v[k * 2 - 2], v[k * 2 - 1]);
  } else{
    swap(v[k * 2 - 3], v[k * 2 - 2]);
  }
  for(auto &p: v) {
    cout << string(p.second, p.first);
  }
  cout << endl;
  return 0; 
}