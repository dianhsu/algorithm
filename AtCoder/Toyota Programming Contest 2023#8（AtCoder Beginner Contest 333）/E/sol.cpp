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
  int n;
  cin >> n;
  vector<PII> vec(n);
  for (auto &it : vec)
    cin >> it.first >> it.second;
  vector<int> need(n, 0);
  multiset<int> ms;
  for (int i = n - 1; i >= 0; --i) {
    if (vec[i].first == 2) {
      ms.insert(vec[i].second);
      need[i] = 1;
    } else if (ms.count(vec[i].second) > 0) {
      ms.extract(vec[i].second);
      need[i] = 1;
    }
  }
  if (ms.size() > 0) {
    cout << -1 << endl;
    return 0;
  }
  int sz = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (need[i] > 0) {
      if (vec[i].first == 1) {
        ++sz;
      } else {
        --sz;
      }
    }
    ans = max(ans, sz);
  }
  cout << ans << endl;
  for (int i = 0; i < n; ++i) {
    if (vec[i].first == 1) {
      cout << need[i] << " ";
    }
  }
  cout << endl;
  return 0;
}