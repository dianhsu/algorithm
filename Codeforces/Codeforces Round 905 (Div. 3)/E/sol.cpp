#include <bits/stdc++.h>
#include <numeric>

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

int not_lower(int x) {
  int dv = 31 - __builtin_clz(x);
  return (1 << dv) == x ? dv : dv + 1;
}
int not_greater(int x) {
  return 31 - __builtin_clz(x);
}

int main() { 
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr)
      cin >> x;
    vector<ll> cnt(n, 0);
    for (int i = 1; i < n; ++i){
      if (arr[i] >= arr[i - 1]) {
        int dv = not_greater((arr[i])/arr[i - 1]);
        cnt[i] = max(0ll, cnt[i - 1] - dv);
      } else{
        int dv = not_lower((arr[i - 1] + arr[i] - 1)/arr[i]);
        cnt[i] = dv + cnt[i - 1];
      }
    }
    cout << accumulate(itr(cnt), 0ll) << endl;
  }
  return 0; 
}