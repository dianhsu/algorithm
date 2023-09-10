#include <bits/stdc++.h>

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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> vis(n + 1, 0);
    for(auto& x: arr){
      cin >> x;
      vis[x] = 1;
    }
    reverse(itr(arr));
    for(int i = 0; i <= n; ++i){
      if(vis[i] == 0){
        arr.push_back(i);
        break;
      }
    }
    vector<int> ans(n);
    int nex = k % (n + 1);
    for(int i = 0; i < n; ++i){
      ans[n - 1 - i] = arr[(k + i) % (n + 1)];
    }
    for(auto& x: ans){
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}

