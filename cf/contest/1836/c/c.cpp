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
  vector<ll> flag{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll minc = flag[c - 1], maxc = flag[c] - 1;
    bool ok = false;
    for(ll cura = flag[a - 1]; cura < flag[a]; ++cura){
      ll minb = max(flag[b - 1], minc - cura);
      ll maxb = min(flag[b] - 1, maxc - cura);
      if(minb <= maxb){
        ll dis = maxb - minb + 1;
        if(dis < k){
          k -= dis;
        }else{
          cout << cura << " + " << minb + k - 1 << " = " << cura + minb + k - 1 << "\n";
          ok = true;
          break;
        }
      }
    }
    if(!ok){
      cout << -1 << "\n";
    }
  }
  return 0;
}
