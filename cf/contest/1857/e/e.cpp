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
    vector<PLL> arr(n);
    for(int i = 0; i < n; ++i){
      cin >> arr[i].first;
      arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    ll rsum = 0;
    for(int i = 0; i < n; ++i){
      rsum += arr[i].first - arr[0].first;
    }
    vector<ll> ans(n);
    ans[arr[0].second] = rsum + n;
    ll lsum = 0;
    for(int i = 1; i < n; ++i){
      lsum += i * (arr[i].first - arr[i - 1].first);
      rsum -= (n - i) * (arr[i].first - arr[i - 1].first);
      ans[arr[i].second] = lsum + rsum + n;
    }
    for(auto& it: ans) cout << it << " ";
    cout << '\n';
  }

  return 0;
}

