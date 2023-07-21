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

ll f(ll s, ll k){
  ll x = (5 * k - s) / 40;
  x = min(x, k / 4);
  ll res = s * k;
  if(x > 0) res = max(res, (s + 20 * x) * (k - 4 * x));
  x = min(x + 1, k / 4);
  if(x > 0) res = max(res, (s + 20 * x) * (k - 4 * x));
  return res;
}
int main() {
  int t;
  cin >> t;
  while(t--){
    ll s, k;
    cin >> s >> k;
    ll ans = s * k;
    if(s % 10 == 5){
      ans = max(ans, (s + 5) * (k - 1));
    }else if(s % 10){
      if(s % 2 == 1){
        s += s % 10;
        --k;
      }
      for(int i = 0; i < 4; ++i){
        if(k > 0){
          ans = max(ans, f(s, k));
        }
        s += s % 10;
        --k;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

