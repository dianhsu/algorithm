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
    int n, m, k;
    cin >> n >> m >> k;
    vector<PII> arr(k);
    PII cur;
    cin >> cur.first >> cur.second;
    int dv = (cur.first + cur.second) % 2;
    map<int, int> mp;
    bool ok = true;
    for(auto& it: arr) {
      cin >> it.first >> it.second;
      mp[(it.first + it.second) % 2]++;
      if(it.first == cur.first and it.second == cur.second){
        ok = false;
      }
    }
    if(n == 1 and m == 1){
      ok = false;
    }else if(n == 1 or m == 1){
      if(mp[dv] >= 1){
        ok = false;
      }
    }else{
      if(mp[dv] >= 1){
        ok = false;
      }
    }
    if(ok){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }

  return 0;
}

