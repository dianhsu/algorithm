#include <algorithm>
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
    vector<int> arr(n);
    for(auto& it: arr) cin >> it;
    auto pMax = max_element(itr(arr));
    auto pMin = min_element(itr(arr));
    vector<PII> ans;
    if(*pMax == *pMin){
      cout << 0 << "\n";
    }else{
      if(*pMax > 0){
        auto p = distance(arr.begin(), pMax);
        while(arr[p] <= 20){
          arr[p] += arr[p];
          ans.push_back({p, p});
        }
        arr[0] += arr[p];
        arr[0] += arr[p];
        ans.push_back({0, p});
        ans.push_back({0, p});
        for(int i = 1; i < n; ++i){
          arr[i] += arr[i - 1];
          arr[i] += arr[i - 1];
          ans.push_back({i, i - 1});
          ans.push_back({i, i - 1});
        }
        cout << ans.size() << "\n";
        for(auto& it: ans){
          cout << it.first + 1 << " " << it.second + 1 << "\n";
        }
      }else{
        auto p = distance(arr.begin(), pMin);
        while(arr[p] >= -20){
          arr[p] += arr[p];
          ans.push_back({p, p});
        }
        arr[n - 1] += arr[p];
        arr[n - 1] += arr[p];
        ans.push_back({n - 1, p});
        ans.push_back({n - 1, p});
        for(int i = n - 2; i >= 0; --i){
          arr[i] += arr[i + 1];
          arr[i] += arr[i + 1];
          ans.push_back({i, i + 1});
          ans.push_back({i, i + 1});
        }
        cout << ans.size() << "\n";
        for(auto& it: ans){
          cout << it.first + 1 << " " << it.second + 1 << "\n";
        }
      }
    }
  }
  return 0;
}

