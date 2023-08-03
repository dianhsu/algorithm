#include <algorithm>
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
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(auto& it: arr) cin >> it;
    ll cur = 5e10;
    auto&& check = [&](ll x) -> ll{
      ll cnt = max(0ll, x - arr.back()) / n;
      ll tx = x;
      if(k <= cnt){
        tx -= k * n;
      }else{
        tx -= cnt * n;
        ll deltaK = k - cnt;
        for(int i = 0; i < deltaK; ++i){
          ll tCnt = upper_bound(itr(arr), tx) - arr.begin();
          if(!tCnt) break;
          tx -= tCnt;
        }
      }
      return tx;
    };
    for(ll i = 1ll << 40; i; i >>= 1){
      if(cur - i > 0 and check(cur - i) > 0){
        cur -= i;
      }
    }
    cout << cur << "\n";
  }
  return 0;
}

