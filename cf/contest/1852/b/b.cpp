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
    vector<PII> arr(n);
    for(int i = 0; i < n; ++i){
      cin >> arr[i].first;
      arr[i].second = i;
    }
    sort(itr(arr), greater<>());
    vector<ll> cnt(n + 1, 0);
    for(int i = 1; i <= n; ++i){
      cnt[i] = cnt[i - 1] + arr[i - 1].first;
    }
    ll sum = cnt[n];
    int pos = -1;
    auto&& check = [&](int pos) -> bool{
      for(int i = 0; i < pos; ++i){
        int extra = arr[i].first - pos;
        if(extra < 0) return false;
        int endPos = pos + extra - 1;
        if(arr[endPos].first < i + 1) return false;
      }
      return true;
    };
    for(int i = 0; i <= n; ++i){
      ll posCnt = cnt[i] - 1ll * i * i;
      ll negCnt = cnt[n] - cnt[i];
      if(posCnt == negCnt and check(i)){
        pos = i;
        break;
      }
    }
    if(pos < 0){
      cout << "NO\n";
    }else{
      cout << "YES\n";
      vector<int> ans(n, 0);
      int l = 0, r = n - 1;
      vector<int> order;
      while(l <= r){
        if(l >= pos) {
          order.push_back(arr[r].second);
          --r;
          continue;
        }
        if(r < pos){
          order.push_back(arr[l].second);
          ++l;
          continue;
        }
        if(arr[l].first > r){
          order.push_back(arr[l].second);
          l++;
        }else{
          order.push_back(arr[r].second);
          --r;
        }
      }
      int cur = n;
      for(auto& it: order){
        ans[it] = cur--;
      }
      for(int i = pos; i < n; ++i) ans[arr[i].second] *= -1;
      for(auto& it: ans) cout << it << " "; cout << "\n";
    }
  }
  return 0;
}

