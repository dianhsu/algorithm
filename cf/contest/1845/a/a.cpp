#include <bits/stdc++.h>

using namespace std;
#define InitIO() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(12)
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

#define MULTIPLE_CASES

void solve(int);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int kase = 1;
#ifdef MULTIPLE_CASES
  cin >> kase;
#endif
  for (int i = 1; i <= kase; ++i) {
    solve(i);
  }
  return 0;
}

void solve(int case_idx) {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> arr(n + 1, -1);
  arr[0] = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= k and j <= i; ++j){
      if(j != x){
        if(arr[i - j] != -1){
          arr[i] = j;
          break;
        }
      }
    }
  }
  if(arr[n] == -1){
    cout << "NO\n";
  }else{
    cout << "YES\n";
    vector<int> res;
    int cur = n;
    while(cur > 0){
      res.push_back(arr[cur]);
      cur -= arr[cur];
    }
    cout << res.size() << "\n";
    for(auto& it: res) cout << it << " "; cout << "\n";
  }
}