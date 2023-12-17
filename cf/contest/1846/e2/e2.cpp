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
  set<ll> st;
  for(ll i = 2; i <= 1e6; ++i){
    ll cur = i;
    ll sum = i + 1;
    while(1e18 / cur >= i and 1e18 - cur * i >= sum){
      cur *= i;
      sum += cur;
      st.insert(sum);
    }
  }
  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    if(st.count(n)) cout << "YES\n";
    else if(n == 1){
      cout << "NO\n";
    }else{
      ll tv = sqrt(n - 1);
      if(tv > 1 and tv * (tv + 1) == n - 1) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  return 0;
}

