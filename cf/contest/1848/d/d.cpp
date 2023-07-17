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
ll getCur(ll cur, ll tk){
  cur += tk / 4 * 10;
  tk %= 4;
  while(tk > 0){
    cur += cur % 10;
    --tk;
  }
  return cur;
}
ll getTv(ll cur, ll k, ll tk){
  ll res = getCur(cur, tk) * (k - tk);
  debug(cur, k, tk, res, getCur(cur, tk), k - tk);
  return res;
}
ll solve2468(ll cur, ll k){
  ll lv = cur * k, lp = 0;
  ll hv = 0, hp = k;
  ll ans = max(lv, hv);
  while(lp < hp){
    auto mp = (lp + hp) / 2;
    auto mmp = (mp + lp) / 2;
    auto mpv = getTv(cur, k, mp);
    auto mmpv = getTv(cur, k, mmp);
    ans = max({ans, mmpv, mpv});
    if(mpv <= mmpv){
      hp = mp - 1;
      ans = max(ans, getTv(cur, k, hp));
    }else{
      lp = mmp + 1;
      ans = max(ans, getTv(cur, k, lp));
    }
  }
  debug(cur, k, ans);
  return ans;
}
int main() {
  int t;
  cin >> t;
  while(t--){
    ll s, k;
    cin >> s >> k;
    if(s % 10 == 0){
      cout << s * k << "\n";
    }else if(s % 10 == 5){
      cout << max(s * k, (s + 5) * (k - 1)) << "\n";
    }else if(s % 10 == 1 || s % 10 == 3 || s % 10 == 9 || s % 10 == 7){
      cout << max(s * k, solve2468(s + s % 10, k - 1)) << "\n";
    }else{
      cout << max(s * k, solve2468(s, k)) << "\n";
    }
  }
  return 0;
}

