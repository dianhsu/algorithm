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
    if(n == 1) cout << n << "\n";
    else if(n == 2){
      cout << 1 << " " << 2 << '\n';
    }else{
      vector<int> l, r;
      for(int i = 4; i <= n; ++i){
        if(i & 1) l.push_back(i);
        else r.push_back(i);
      }
      cout << 2 << " ";
      for(auto& v: l) cout << v << " ";
      cout << 1 << " ";
      for(auto& v: r) cout << v << " ";
      cout << 3 << "\n";
    }
  }
  return 0;
}

