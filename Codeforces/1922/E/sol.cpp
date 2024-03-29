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
    ll x;
    cin >> x;
    vector<int> arr;
    while(x) {
      arr.push_back(x % 2);
      x /= 2;
    }
    int h = 1, l = 0;
    reverse(itr(arr));
    vector<int> ans;
    for (int i = 1; i < arr.size(); ++i) {
      ans.push_back(h);
      ++h;
      if (arr[i] & 1) {
        ans.push_back(l);
        --l;
      }
    }
    cout << ans.size() << endl;
    for (auto& it: ans) cout << it << " "; cout << endl;
  }
  return 0; 
}