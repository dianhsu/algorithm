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
    map<ll, ll> mp;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
      ll x;
      cin >> x;
      mp[x]++;
    }
    int q;
    cin >> q;
    vector<ll> ans(q);
    for(int i = 0; i < q; i++){
      ll x, y;
      cin >> x >> y;
      ll dv = x * x - 4 * y;
      if(dv < 0){
        ans[i] = 0;
      }else if(dv == 0){
        if(x % 2 == 0){
          ans[i] = mp[x / 2] * (mp[x / 2] - 1) / 2;
        }else{
          ans[i] = 0;
        }
      }else{
        ll p = sqrt(dv);
        if(p * p == dv){
          if((x + p) % 2 == 0){
            ans[i] = mp[(x + p) / 2] * mp[(x - p) / 2];
          }else{
            ans[i] = 0;
          }
        }else{
          ans[i] = 0;
        }
      }
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}

