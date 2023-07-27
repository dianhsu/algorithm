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

int main() {
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> arr(n), lrr(n), rrr(n);
    int ans = 1;
    for(int i = 0; i < n; ++i){
      cin >> arr[i];
      if(i == 0) lrr[i] = arr[i];
      else lrr[i] = lrr[i - 1] & arr[i];
    }
    for(int i = n - 1; i >= 0; --i){
      if(i == n - 1) rrr[i] = arr[i];
      else rrr[i] = rrr[i + 1] & arr[i];
    }
    int sum = lrr[n - 1];
    if(sum == 0){
      int p = 0;
      int cur = INT_MAX;
      while(p < n - 1){
        cur &= arr[p];
        if(cur == 0 and rrr[p + 1] == 0){
          ++ans;
          cur = INT_MAX;
        }
        ++p;
      }
    }
    cout << ans << endl;
  }

  return 0;
}

